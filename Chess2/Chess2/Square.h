#ifndef SQUARE_H_
#define SQUARE_H_
#include <SFML\Graphics.hpp>
using namespace sf;
class Square
{
private:
	Vector2f Position;
	Sprite sprite;
	bool IsOccupied;

public:
	Square();
	Square(Vector2f, Sprite, bool);
	~Square();
	Vector2f GetPosition();
	Sprite GetTexture();
	bool GetIsOccupied();
	void SetIsOccupied(bool);

};

#endif
