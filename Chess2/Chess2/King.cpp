#include <SFML\Graphics.hpp>
#include "King.h"

using namespace sf;

King::~King()
{

}
King::King()
{

}

King::King(Vector2f pos, bool s, Sprite sp, Color c) :Piece(pos, s, sp, c)
{
	sprite.setTextureRect(IntRect(165, 0, 75, 80));//sets the rectangle of the texture from which the sprite gets the texture for the piece
	kind = 0;
}

bool King::GetIsChecked()
{
	return this->IsChecked;
}

bool King::Move(Vector2f pos)
{
	if (pos.x < 641 && pos.y<651)//check so that the piece cant move outside the board
	{
		int x = (int)(pos.x / 80);
		int y = (int)(pos.y / 80);
		if ((abs((int)Position.x - x * 80) == 80 && abs((int)Position.y - y * 80) == 80) || (abs((int)Position.x - x * 80) == 80 && abs((int)Position.y - y * 80) == 0) || (abs((int)Position.x - x * 80) == 0 && abs((int)Position.y - y * 80) == 80))//checks if move is valid
		{
			return true;
		}
	}
	return  false;
}
void King::SetFirstMove()
{

}
