#include "Rook.h"
#include <SFML\Graphics.hpp>

using namespace sf;

Rook::~Rook()
{

}
Rook::Rook()
{

}
Rook::Rook(Vector2f pos, bool s, Sprite sp, Color c) :Piece(pos, s, sp, c)
{
	sprite.setTextureRect(IntRect(0, 0, 75, 80));//sets the rectangle of the texture from which the sprite gets the texture for the piece
	kind = 4;
}
Vector2f Rook::Move(Vector2f pos)
{
	if (pos.x < 641 && pos.y<641)//Check so that the piece cant move outside the board
	{
		int x = (int)(pos.x / 80);
		int y = (int)(pos.y / 80);
		if (abs((int)Position.x - x * 80) != 0 && abs((int)Position.y - y * 80) == 0 || abs((int)Position.x - x * 80) == 0 && abs((int)Position.y - y * 80) != 0)//makes sure the new position is valid
		{
			Position.x = (float)(x * 80);
			Position.y = (float)(y * 80);
			sprite.setPosition(Position);
		}
	}
	return  Position;
}
