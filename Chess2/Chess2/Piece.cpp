#include "Piece.h"
#include <SFML\Graphics.hpp>

using namespace sf;
Piece::~Piece()
{

}

Piece::Piece()//constructor for piece, never used because its a private constructor
{

}

Piece::Piece(Vector2f pos, bool s, Sprite sp, Color c)//constructor used in the program to create a piece
{
	Position = pos;
	State = s;
	sprite= sp;
	sprite.setPosition(pos);
	Colour = c;
	Targeted=false;
}

Vector2f Piece::GetPosition() //Gets the pieces position
{
	return Position;
}
void Piece::SetPosition(Vector2f pos)//Sets the position of the piece
{
	int x = pos.x / 80;
	int y = pos.y / 80;
	pos.x = x * 80;
	pos.y = y * 80;
	Position =pos;
	sprite.setPosition(pos);//changes the sprites position to make sure that the sprite is at the same position as the Piece::Position
}
bool Piece::GetState()//Gets the Piece::State which tells if the pieces should be drawn
{
	return State;
}
void Piece::SetState(bool s)//Sets the state when the Piece is taken out or the pieces are reseted
{
	State = s;
}
Sprite Piece::GetTexture()//Gets the sprite for the pieces which is used to draw them
{
	return this->sprite;
}
void Piece::SetTexture(Sprite sp)//Sets the Piece sprite
{
	sprite = sp;
}
Color Piece::GetColour()//Gets the Colour of the piece
{
	return Colour;
}
void Piece::SetColour(Color c)//Sets the colour of the piece
{
	Colour = c;
	sprite.setColor(c);
}
bool Piece::GetTargeted()//gets the variable is targeted from peice
{
	return Targeted;
}
void Piece::SetTargeted(bool o)//changes the Targeted variable in piece
{
	if (o)
	{
		sprite.setColor(Color::Red);//changes the colour of the texture of the piece to red to show that it is targeted
	}
	else
	{
		sprite.setColor(Colour);//Resets the colour to the standard colour of the piece when the piece is no longer targeted
	}
	Targeted = o;
}
int Piece::getKind()
{
	return kind;
}
