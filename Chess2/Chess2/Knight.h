#ifndef KNIGHT_H_
#define KNIGHT_H_
#include "Piece.h"
#include <SFML\Graphics.hpp>

class Knight :public Piece
{
private:
	Knight();
public:
	~Knight();
	Knight(Vector2f, bool, Sprite, Color);
	Vector2f Move(Vector2f);
};

#endif
