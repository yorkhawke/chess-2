#include "PlayTurn.h"

PlayTurn::PlayTurn()
{
	targeted = false;
}

PlayTurn::~PlayTurn()
{

}

bool PlayTurn::Turn(Piece* PiecesP1[], Piece* PiecesP2[], RenderWindow* win)
{
	Vector2f previouspos;
	Vector2i mousePosition = sf::Mouse::getPosition(*win);
	Vector2f mousePositionFloat = static_cast<sf::Vector2f>(mousePosition);
	bool ret = false;
	int x = (int)mousePositionFloat.x / 80;
	int y = (int)mousePositionFloat.y / 80;

	switch (inp.InputMove(win,targeted))//Check if input has been entered and acts accordingly 
	{
	case 1://if player Rightclicks to target a piece
			for (int i = 0; i < 16; i++)
			{
				previouspos = PiecesP1[i]->GetPosition();
				if ((x * 80 == (int)previouspos.x && (int)previouspos.y == y * 80) && PiecesP1[i]->GetState() == true)
				{
					PiecesP1[i]->SetTargeted(true);
					targeted = true;
					break;
				}
			}
			break;
	case 3://if player RightClicks while a piece is targeted, it will untarget that piece  
		for (int i = 0; i < 16; i++)
		{
			previouspos = PiecesP1[i]->GetPosition();
			if ((x * 80 != (int)previouspos.x || (int)previouspos.y != y * 80) && PiecesP1[i]->GetTargeted() == true)
			{
				PiecesP1[i]->SetTargeted(false);
				targeted = false;
				break;
			}
		}
		break;
	case 4://when the player has targeted a piece and leftclicks to move the piece to the targeted position
		for (int i = 0; i < 16; i++)
		{
			if (PiecesP1[i]->GetTargeted() == true)
			{
				previouspos = PiecesP1[i]->GetPosition();

				if (checkMove(PiecesP1, PiecesP2, mousePositionFloat, PiecesP1[i]))// Checks if the move is valid, if valid changes to the new position and untargets the piece and ret to true so Match will know a move has been done
				{
					PiecesP1[i]->SetPosition(mousePositionFloat);
					targeted = false;
					ret = true;
					PiecesP1[i]->SetTargeted(false);

					for (int j = 0; j < 16; j++)
					{
						if (PiecesP2[j]->GetPosition() == PiecesP1[i]->GetPosition())
						{
							PiecesP2[j]->SetState(false);
						}
					}
				}
			}
		}
		break;
	}
	return ret;

}

bool PlayTurn::checkMove(Piece* PiecesMovingPlayer[], Piece* PiecesWaitingPlayer[], Vector2f newPos, Piece* targetedPiece)
{
	int kind = targetedPiece->getKind();
	Vector2f Position = targetedPiece->GetPosition();
	Vector2f newPosRecalc;
	int x = newPos.x / 80;
	int y = newPos.y / 80;
	newPosRecalc = Vector2f(x * 80, y * 80);
	switch (kind)
	{
	case 0://king 
#pragma region check kings move 
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (newPosRecalc == PiecesMovingPlayer[i]->GetPosition())
					return false;
			}
			return true;
		}
		else
			return false;
#pragma endregion
		break;
	case 1://queen not fully working. Lack of time
#pragma region check queens move
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (newPosRecalc == PiecesMovingPlayer[i]->GetPosition() && PiecesWaitingPlayer[i]->GetState())
					return false;
			}
			for (int i = 0; i < 16; i++)
			{

			}
		}
		else
			return false;
#pragma endregion
		break;
	case 2://bishop not fully working. Lack of time
#pragma region check bishops move
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (PiecesMovingPlayer[i]->GetPosition() == newPosRecalc)
					return false;

			}
		}
		else
			return false;
#pragma endregion
		break;
	case 3://knight
#pragma region check knights move
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (PiecesMovingPlayer[i]->GetPosition() == newPosRecalc&&PiecesMovingPlayer[i]->GetState())
					return false;
			}
			return true;
		}
		else
			return false;
#pragma endregion
		break;
	case 4://rook  not fully working. Lack of time
#pragma region check rooks move
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (PiecesMovingPlayer[i]->GetPosition() == newPosRecalc&&PiecesMovingPlayer[i]->GetState())
					return false;
			}
			return true;
		}
		else
		{
			return false;
		}
#pragma endregion
		break;
	case 5://pawn
#pragma region check pawns move
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (PiecesMovingPlayer[i]->GetPosition() == newPosRecalc&&PiecesMovingPlayer[i]->GetState())
					return false;
				if (PiecesMovingPlayer[i]->GetPosition().x == targetedPiece->GetPosition().x&& abs(PiecesMovingPlayer[i]->GetPosition().y - newPosRecalc.y) < abs(targetedPiece->GetPosition().y - newPosRecalc.y)&&PiecesMovingPlayer[i]->GetState())
					return false;
			}

			if ((newPosRecalc.y == targetedPiece->GetPosition().y + 80) && newPosRecalc.x == targetedPiece->GetPosition().x || (newPosRecalc.y == targetedPiece->GetPosition().y - 80) && newPosRecalc.x == targetedPiece->GetPosition().x)
			{
				for (int i = 0; i < 16; i++)
				{
					if (PiecesWaitingPlayer[i]->GetPosition()==newPosRecalc)
					{
						return false;
					}
				}
			}
			if (newPosRecalc.x != targetedPiece->GetPosition().x)
			{
				for (int i = 0; i < 16; i++)
				{
					if (newPosRecalc == PiecesWaitingPlayer[i]->GetPosition())
					{
						targetedPiece->SetFirstMove();
						return true;
					}
				}
				return false;

			}
			else
			{
				for (int i = 0; i < 16; i++)
				{
					if (PiecesWaitingPlayer[i]->GetPosition() == newPosRecalc)
					{
						if (x * 80 > targetedPiece->GetPosition().x || x * 80 < targetedPiece->GetPosition().x)
						{
							targetedPiece->SetFirstMove();
							return true;
						}
						else
							return false;
					}
					else
					{
						targetedPiece->SetFirstMove();
						return true;
					}
				}


			}

		}
		else
			return false;
#pragma endregion
		break;
	}
}