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
	switch (kind)
	{
	case 0://king 
#pragma region check kings move
		if (targetedPiece->Move(newPos))
		{
			for (int i = 0; i < 16; i++)
			{
				if (newPos == PiecesMovingPlayer[i]->GetPosition())
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
				if (newPos == PiecesMovingPlayer[i]->GetPosition())
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
				if (PiecesMovingPlayer[i]->GetPosition() == newPos)
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
				if (PiecesMovingPlayer[i]->GetPosition() == newPos)
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
			int x = (int)newPos.x / 80;
			int y = (int)newPos.y / 80;
			for (int i = 0; i < 16; i++)
			{
				if (PiecesMovingPlayer[i]->GetPosition() == newPos)
					return false;
				if (x * 80 == targetedPiece->GetPosition().x)
				{
					if (abs(PiecesMovingPlayer[i]->GetPosition().y - targetedPiece->GetPosition().y) < abs(y * 80 - targetedPiece->GetPosition().y))
					{
						return false;
					}
				}
				if (y * 80 == targetedPiece->GetPosition().y)
				{
					if (abs(PiecesMovingPlayer[i]->GetPosition().x - targetedPiece->GetPosition().x) < abs(x * 80 - targetedPiece->GetPosition().x))
					{
						return false;
					}
				}

			}

			for (int i = 0; i < 16; i++)
			{
				if (targetedPiece->GetPosition().x == x * 80)
				{
					if (abs(PiecesWaitingPlayer[i]->GetPosition().y - targetedPiece->GetPosition().y) < abs(y * 80 - targetedPiece->GetPosition().y))
					{
						return false;
					}
				}
				if (targetedPiece->GetPosition().y == y * 80)
				{
					if (abs(PiecesWaitingPlayer[i]->GetPosition().x - targetedPiece->GetPosition().x) < abs(x * 80 - targetedPiece->GetPosition().x))
					{
						return false;
					}
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
				if (PiecesMovingPlayer[i]->GetPosition() == newPos)
					return false;
			}
			for (int i = 0; i < 16; i++)
			{
				if (PiecesWaitingPlayer[i]->GetPosition() == newPos)
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