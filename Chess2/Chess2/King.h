#ifndef KING_H_
#define KING_H_

#include <SFML\Graphics.hpp>
#include "Piece.h"

class King :public Piece
{
private:
	bool IsChecked;
	King();
public:
	King(Vector2f, bool, Sprite, Color);
	~King();
	bool Move(Vector2f);
	bool GetIsChecked();
};
#endif
