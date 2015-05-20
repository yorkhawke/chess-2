#ifndef MENYGRAPHICCOMPONENT_H
#define MENYGRAPHICCOMPONENT_H

#include "Graphics.h"

class MenyGraphicComponent : public Graphic
{
private:
	Texture backTex, PlayB, CloseB;
	Sprite backSprite, PlaySprite,CloseSprite;
public:
	MenyGraphicComponent(int width, int height);
	~MenyGraphicComponent();
	void Draw();
	void Render(RenderWindow* window);
	FloatRect GetGlobalRec(int);
};

#endif