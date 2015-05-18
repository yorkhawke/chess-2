#ifndef ROOK_H_
#define ROOK_H_


#include "Piece.h"
#include <SFML\Graphics.hpp>

class Rook :public Piece
{
private:
	Rook();
public:
	Rook(Vector2f, bool, Sprite, Color);
	~Rook();
	Vector2f Move(Vector2f);

};
#endif
