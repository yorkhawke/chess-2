#include "PlayTurn.h"

PlayTurn::PlayTurn()
{
	targeted = false;
}

PlayTurn::~PlayTurn()
{

}

void PlayTurn::Turn(Piece* PiecesP1[], Piece* PiecesP2[], RenderWindow* win)
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
	case 3://trimma 
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
				/*
				if (previouspos != PiecesP1[i]->Move(mousePositionFloat))
				{
					PreviousPosition = PiecesP1[i]->GetPosition();
					break;
				}
				*/
				
				PiecesP1[i]->Move(mousePositionFloat);
				
			}
		}
		break;
	}

}

void PlayTurn::show(Piece* PiecesP1, Piece* PiecesP2)
{
	//lasters
}

bool PlayTurn::checkMove(Piece* PiecesP2[], Piece* PiecesP1[], Vector2f newPos, Vector2f prevPos, Piece* targetedPiece)
{
	int x = (int)(newPos.x / 80);
	int y = (int)(newPos.y / 80);
	if (newPos.x < 641 && newPos.y < 651)//check so that the piece cant move outside the board
	{
		int kind = targetedPiece->getKind();
		Vector2f Position = targetedPiece->GetPosition();
		switch (kind)
		{
		case 0://king 
			for (int i = 0; i < 16; i++)
			{
				if (newPos == PiecesP1[i]->GetPosition())
				return false;
			}

			if ((abs((int)Position.x - x * 80) == 80 && abs((int)Position.y - y * 80) == 80) || (abs((int)Position.x - x * 80) == 80 && abs((int)Position.y - y * 80) == 0) || (abs((int)Position.x - x * 80) == 0 && abs((int)Position.y - y * 80) == 80))//checks if move is valid
			{
				Position.x = (float)(x * 80);
				Position.y = (float)(y * 80);
			}
			break;
		case 1:
			for (int i = 0; i < 16; i++)
			{
				if (newPos == PiecesP1[i]->GetPosition())//äckkligt mycket kod
					return false;
			}

			if (abs((int)Position.x - x * 80) == abs((int)Position.y - y * 80) || abs((int)Position.x - x * 80) != 0 && abs((int)Position.y - y * 80) == 0 || abs((int)Position.x - x * 80) == 0 && abs((int)Position.y - y * 80) != 0)//makes sure the new position is valid
			{
				Position.x = (float)(x * 80);
				Position.y = (float)(y * 80);				
			}
		}

	}

}