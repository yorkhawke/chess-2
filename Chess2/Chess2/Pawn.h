#ifndef PAWN_H_
#define PAWN_H_
#include"Piece.h"
#include <SFML\Graphics.hpp>

class Pawn : public Piece
{
private:
	Pawn();
	bool firstmove;
public:
	~Pawn();
	Pawn(Vector2f, bool, Sprite, Color);
	bool Move(Vector2f);
};
#endif
