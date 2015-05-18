#include "Square.h"
#include <SFML\Graphics.hpp>
using namespace sf;

Square::Square()//default constructor never used in the program
{

}
Square::~Square()//destructor
{

}
Square::Square(Vector2f pos, Sprite sp, bool o)//constructor
{
	Position = pos;
	sprite = sp;
	if (o == true)
	{
		sprite.setColor(Color(0, 0, 255, 255));
		o = false;
	}
	IsOccupied = o;
	sprite.setPosition(pos);
}
Vector2f Square::GetPosition()//gets the square position
{
	return this->Position;
}
Sprite Square::GetTexture()//gets the square texture
{
	return this->sprite;
}
bool Square::GetIsOccupied()//get the square IsOccupied variable
{
	return this->IsOccupied;
}
void Square::SetIsOccupied(bool o)//Sets the square IsOccupied variable
{
	IsOccupied = o;
}
