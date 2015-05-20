#ifndef MATCHGRAPHICCOMPONENT_H
#define MATCHGRAPHICCOMPONENT_H

#include "Graphics.h"
#include "Square.h"

class MatchGraphicComponent : public Graphic
{
private:
	Sprite Sp1, Sp2;
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
	FloatRect GetGlobalRec(int);
	Sprite GetSprite(int);
};

#endif