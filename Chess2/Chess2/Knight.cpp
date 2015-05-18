#include "Knight.h"
#include <SFML\Graphics.hpp>

using namespace sf;

Knight::~Knight()
{

}
Knight::Knight()
{

}
Knight::Knight(Vector2f pos, bool s, Sprite sp, Color c) :Piece(pos, s, sp, c)
{
	sprite.setTextureRect(IntRect(325, 0, 75, 80));//sets the rectangle of the texture from which the sprite gets the texture for the piece
}

Vector2f Knight::Move(Vector2f pos)
{
	if (pos.x < 641 && pos.y<651)//check to make sure piece dont move outside the board
	{
		int x = (int)(pos.x / 80);
		int y = (int)(pos.y / 80);
		if (abs((int)Position.x - x * 80) == 160 && abs((int)Position.y - y * 80) == 80 || abs((int)Position.x - x * 80) == 80 && abs((int)Position.y - y * 80) == 160)//check if the move is a valid move
		{
			Position.x = (float)(x * 80);
			Position.y = (float)(y * 80);
			sprite.setPosition(Position);
		}
	}
	return  Position;
}
