#ifndef PIECE_H_
#define PIECE_H_

#include<SFML/Graphics.hpp>

using namespace sf;
class Piece
{
protected:
	Vector2f Position;
	bool State;
	Sprite sprite;
	Color Colour;
	bool Targeted;
	Piece();
	int kind;
public:

	Piece(Vector2f, bool, Sprite, Color);
	virtual ~Piece();
	Vector2f GetPosition();
	void SetPosition(Vector2f);
	bool GetState();
	void SetState(bool);
	Sprite GetTexture();
	void SetTexture(Sprite);
	Color GetColour();
	void SetColour(Color);
	virtual bool Move(Vector2f)=0;
	bool GetTargeted();
	void SetTargeted(bool);
	int getKind();
};

#endif
