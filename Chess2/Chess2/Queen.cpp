#include <SFML\Graphics.hpp>
#include "Queen.h"

using namespace sf;

Queen::~Queen()
{

}
Queen::Queen()
{

}
Queen::Queen(Vector2f pos, bool s, Sprite sp, Color c) :Piece(pos, s, sp, c)
{
	sprite.setTextureRect(IntRect(245, 0, 75, 80));//sets the rectangle of the texture from which the sprite gets the texture for the piece
}

Vector2f Queen::Move(Vector2f pos)
{ 
	if (pos.x < 641 && pos.y<641)//Check so the piece cant move outside the board
	{
		int x = (int)(pos.x / 80);
		int y = (int)(pos.y / 80);
		if (abs((int)Position.x - x * 80) == abs((int)Position.y - y * 80) || abs((int)Position.x - x * 80) != 0 && abs((int)Position.y - y * 80) == 0 || abs((int)Position.x - x * 80) == 0 && abs((int)Position.y - y * 80) != 0)//makes sure the new position is valid
		{
			Position.x = (float)(x * 80);
			Position.y = (float)(y * 80);
			sprite.setPosition(Position); 
		}
	}
	return  Position;
}
