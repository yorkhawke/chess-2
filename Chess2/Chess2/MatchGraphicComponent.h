#ifndef MATCHGRAPHICCOMPONENT_H
#define MATCHGRAPHICCOMPONENT_H

#include "Graphics.h"
#include "Square.h"

class MatchGraphicComponent : public Graphic
{
private:
	Sprite Sp;
	Sprite sprite;
	Texture tex;
	Font font;
	Text winText;
	Square Board[64];
public:
	MatchGraphicComponent(int width, int height);
	~MatchGraphicComponent();
	void Draw();
	void Render(RenderWindow* window);
	void Render(RenderWindow* window, Piece* p1[], Piece* p2[]);
	Sprite GetSprite();
};

#endif