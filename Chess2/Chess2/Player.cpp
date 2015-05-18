#include "Player.h"
#include "PieceHeader.h"
#include <SFML\Graphics.hpp>
using namespace std;
using namespace sf;
Player::~Player()
{
}
Player::Player()
{
	Concede = false;
  
}
Player::Player(int ID, int Nr, string name, bool c,Sprite sprite)//Creates the player Default Color is White
{
  this->ID=ID;
  this->NrOfWins=Nr;
  this->Name = name;
  this->Concede = c;

  pieces[0] = new Pawn(Vector2f(0,480),true,sprite,Color::White);
  pieces[1] = new Pawn(Vector2f(80, 480), true, sprite, Color::White);
  pieces[2] = new Pawn(Vector2f(160, 480), true, sprite, Color::White);
  pieces[3] = new Pawn(Vector2f(240, 480), true, sprite, Color::White);
  pieces[4] = new Pawn(Vector2f(320, 480), true, sprite, Color::White);
  pieces[5] = new Pawn(Vector2f(400, 480), true, sprite, Color::White);
  pieces[6] = new Pawn(Vector2f(480, 480), true, sprite, Color::White);
  pieces[7] = new Pawn(Vector2f(560, 480), true, sprite, Color::White);
  pieces[8] = new Rook(Vector2f(0,560),true,sprite,Color::White);
  pieces[9] = new Knight(Vector2f(80, 560), true, sprite, Color::White);
  pieces[10] = new Bishop(Vector2f(400, 560), true, sprite, Color::White);
  pieces[11] = new Queen(Vector2f(320, 560), true, sprite, Color::White);
  pieces[12] = new King(Vector2f(240, 560), true, sprite, Color::White);
  pieces[13] = new Bishop(Vector2f(160, 560), true, sprite, Color::White);
  pieces[14] = new Knight(Vector2f(480, 560), true, sprite, Color::White);
  pieces[15] = new Rook(Vector2f(560, 560), true, sprite, Color::White);

}
void Player::ResetPieces(bool col)//Resets the pieces to their default positions also used to change the Color of the players Pieces.
{
	Vector2f pos;
	if(col)
	{
		pos=Vector2f(0,480);
		for(int i = 0; i < 16 ; i++)//If col is true the player is white else it is black.
		{
			pieces[i]->SetPosition(pos);
			pieces[i]->SetColour(Color::White);
			pos.x+=80;
			if(pos.x>560)
			{
				pos.y+=80;
				pos.x=0;
			}
		}
	}
	else
	{
		pos = Vector2f(0,80);
		for (int i = 0; i < 16; i++)
		{
			pieces[i]->SetPosition(pos);
			pieces[i]->SetColour(Color::Black);
			pos.x += 80;
			if (pos.x >560)
			{
				pos.y -= 80;
				pos.x = 0;
			}
		}
	}

}
bool Player::PlayTurn(RenderWindow* window,bool keft)
{
	Event ev;
	Vector2f previouspos;
	bool Playturn = false;
	while (!Playturn)//Loops until player targets.
	{
		if (!keft)//Used when the player wants to target a piece. if true a player has already targeted a piece and will move on the the next step.
		{
			if (Mouse::isButtonPressed(Mouse::Right))
			{
				Vector2i mousePosition = sf::Mouse::getPosition(*window);
				Vector2f mousePositionFloat = static_cast<sf::Vector2f>(mousePosition);
				for (int i = 0; i < 16; i++)
				{
					int x = (int)mousePositionFloat.x / 80;
					int y = (int)mousePositionFloat.y / 80;
					previouspos = pieces[i]->GetPosition();
					if ((x * 80 == (int)previouspos.x && (int)previouspos.y == y * 80) && pieces[i]->GetState() == true)
					{
						pieces[i]->SetTargeted(true);
						return false;
					}
					if ((x * 80 != (int)previouspos.x || (int)previouspos.y != y * 80) && pieces[i]->GetTargeted() == true)
					{
						pieces[i]->SetTargeted(false);
					}
				}
			}
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Vector2i mousePosition = sf::Mouse::getPosition(*window);
			Vector2f mousePositionFloat = static_cast<sf::Vector2f>(mousePosition);
			for (int i = 0; i < 16; i++)
			{
				if (pieces[i]->GetTargeted() == true)
				{
					previouspos = pieces[i]->GetPosition();
					if (previouspos != pieces[i]->Move(mousePositionFloat))
					{
						PreviousPosition = pieces[i]->GetPosition();
						return true;
						Playturn = true;
					}
				}
			}
		}

		window->pollEvent(ev);//basic exit event.
		if ((ev.type == Event::Closed) || ((ev.type == Event::KeyPressed) && ev.key.code == Keyboard::Escape))
		{
			window->close();
			Playturn = true;
		}

	}
}

void Player::ResetCol()
{
	for (int i = 0; i < 16; i++)
	{
		if (pieces[i]->GetTargeted())
		{
			pieces[i]->SetTargeted(false);
		}
	}

}

int Player::GetID()//Just basic set and get functions
{
  return this->ID;
}
void Player::SetID(int ID)
{
  this->ID=ID;
}
int Player::GetNrOfWins()
{
  return this->NrOfWins;
}
void Player::SetNrOfWins(int nr)
{
  this->NrOfWins = nr;
}
string Player::GetName()
{
  return this->Name;
}
void Player::SetName(string name)
{
  this->Name = name;
}
bool Player::GetConcede()
{
  return this->Concede;
}
void Player::SetConcede(bool c)
{
  this->Concede = c;
}
void Player::RenderPieces(RenderWindow* win)//Renders the pieces if they are active
{
	for (int i = 0; i < 16; i++)
	{
		if (pieces[i]->GetState())
			win->draw(pieces[i]->GetTexture());
	}

}
Vector2f Player::GetPreviousPosition()
{
	return PreviousPosition;
}
void Player::CheckTakenOut(Vector2f position)
{
	for (int i = 0; i < 16; i++)
	{
		if (pieces[i]->GetPosition() == position)
		{
			pieces[i]->SetState(false);
		}
	}
}
bool Player::KingIsDead()// Checks the king if its dead or alive.
{
	if (pieces[12]->GetState() == false)
	{
		return true;
	}
	else return false;
}