#include "Pawn.h"
#include <SFML\Graphics.hpp>

using namespace sf;

Pawn::~Pawn()
{

}
Pawn::Pawn()
{

}
Pawn::Pawn(Vector2f pos, bool s, Sprite sp, Color c) :Piece(pos,s,sp,c)
{
	sprite.setTextureRect(IntRect(405, 0, 75, 80));//sets the rectangle of the texture from which the sprite gets the texture for the piece
	firstmove = true;//variable used to check if its the piece first move, pawns can move 2 steps forward the first time they move each game
	kind = 5;
}

bool Pawn::Move(Vector2f pos)
{
	if (pos.x < 641 && pos.y<641)//check to make sure the piece cant move outside the board
	{
		int x = (int)(pos.x / 80);
		int y = (int)(pos.y / 80);
		if (abs((int)Position.x - x * 80) == 80 || (int)Position.x == x * 80)//makes sure the piece either only moves straight ahead or a max of one step to the side
		{
			if (firstmove)//if it is the first move the piece can either take 2 steps forward or one
			{
				if ((abs((int)Position.y - y * 80) <= 160) || (abs((int)Position.y - y * 80) <= 80))
				{
					firstmove = false;
					return true;
				}
			}
			if (abs((int)Position.y - y * 80) <= 80)//if its not the first move the piece can move one step forward/diagonaly forward(1 step forward and one to the side)
			{
				return true;
			}
		}
	}
	return false;
}
