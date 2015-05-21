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

	int x = (int)mousePositionFloat.x / 80;
	int y = (int)mousePositionFloat.y / 80;

	switch (inp.InputMove(win,targeted))
	{
	case 1://TARGETING
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
	case 3:
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
	case 4:
		for (int i = 0; i < 16; i++)
		{
			if (PiecesP1[i]->GetTargeted() == true)
			{
				previouspos = PiecesP1[i]->GetPosition();
				if (checkMove(PiecesP1, PiecesP2, mousePositionFloat, PiecesP1[i]))
				{
					PiecesP1[i]->SetPosition(mousePositionFloat);
					targeted = false;
					return true;		
				}
			}
		}
		break;
	}
	return false;

}

void PlayTurn::show(Piece* PiecesP1, Piece* PiecesP2)
{
	//lasters
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
	case 1://queen
#pragma region check queens move
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (newPosRecalc == PiecesMovingPlayer[i]->GetPosition())
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
	case 2://bishop
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
				if (PiecesMovingPlayer[i]->GetPosition() == newPosRecalc)
					return false;
			}
			return true;
		}
		else
			return false;
#pragma endregion
		break;
	case 4://rook
#pragma region check rooks move
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (PiecesMovingPlayer[i]->GetPosition() == newPosRecalc)
					return false;
				if ((newPosRecalc.x == targetedPiece->GetPosition().x)&& PiecesMovingPlayer[i]->GetPosition().x==newPosRecalc.x)
				{
					if (abs(PiecesMovingPlayer[i]->GetPosition().y - newPosRecalc.y) < abs(targetedPiece->GetPosition().y - newPosRecalc.y))
						return false;
				}
				if (newPosRecalc.y == targetedPiece->GetPosition().y && PiecesMovingPlayer[i]->GetPosition().y == newPosRecalc.y)
				{
					if (abs(PiecesMovingPlayer[i]->GetPosition().x - newPosRecalc.x) < abs(targetedPiece->GetPosition().x - newPosRecalc.x))
						return false;
				}
			}
			for (int i = 0; i < 16; i++)
			{
				if (newPosRecalc.x == targetedPiece->GetPosition().x && PiecesWaitingPlayer[i]->GetPosition().x == newPosRecalc.x)
				{
					if (abs(PiecesWaitingPlayer[i]->GetPosition().y - newPosRecalc.y) < abs(targetedPiece->GetPosition().y - newPosRecalc.y))
						return false;
				}
				if (newPosRecalc.y == targetedPiece->GetPosition().y&&newPosRecalc.y == PiecesWaitingPlayer[i]->GetPosition().y)
				{
					if (abs(PiecesWaitingPlayer[i]->GetPosition().x - newPosRecalc.x) < abs(targetedPiece->GetPosition().x - newPosRecalc.x))
						return false;
				}
			}
			return true;
		}
		else
			return false;
#pragma endregion
		break;
	case 5://pawn
#pragma region check pawns move
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (PiecesMovingPlayer[i]->GetPosition() == newPosRecalc)
					return false;
				if (PiecesMovingPlayer[i]->GetPosition().x == targetedPiece->GetPosition().x&& abs(PiecesMovingPlayer[i]->GetPosition().y - newPosRecalc.y) < abs(targetedPiece->GetPosition().y - newPosRecalc.y))
					return false;	
			}
			for (int i = 0; i < 16; i++)
			{
				if (PiecesWaitingPlayer[i]->GetPosition() == newPosRecalc)
				{
					int x = (int)newPos.x / 80;
					if (x * 80 > targetedPiece->GetPosition().x || x * 80 < targetedPiece->GetPosition().x)
						return true;
					else
						return false;
				}
				else
					return true;
			}
		}
		else
			return false;
#pragma endregion
		break;
	}
}