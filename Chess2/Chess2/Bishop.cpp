#include <SFML\Graphics.hpp>
#include "Bishop.h"

using namespace sf;

Bishop::~Bishop()
{

}
Bishop::Bishop()
{

}
Bishop::Bishop(Vector2f pos, bool s, Sprite sp, Color c) :Piece(pos, s, sp, c)
{
	sprite.setTextureRect(IntRect(85, 0, 75, 80));//sets the rectangle from which the sprite will get the texture for the specified piece
	kind = 2;
}

bool Bishop::Move(Vector2f pos)//used to move the piece
{
	if (pos.x < 641 && pos.y<651)//makes sure the piece cant move outside the board
	{
		int x = (int)(pos.x / 80);
		int y = (int)(pos.y / 80);
		if (abs((int)Position.y - y * 80) == abs((int)Position.x - x * 80))//calculates if the new position is a position the piece could move to
		{
			return true;
		}
	}
	return  false;
}
