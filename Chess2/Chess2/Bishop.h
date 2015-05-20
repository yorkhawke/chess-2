#ifndef BISHOP_H_
#define BISHOP_H_
#include "Piece.h"
#include <SFML\Graphics.hpp>

class Bishop :public Piece
{
private:
	Bishop();
public:
	Bishop(Vector2f, bool, Sprite, Color);
	~Bishop();
	bool Move(Vector2f);
};


#endif
