#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SFML\Graphics.hpp>
#include "Match.h"



class Graphic
{
protected:
	int SCRWIDTH;
	int SCRHEIGHT;
public:
	Graphic();
	Graphic(int,int);
	virtual ~Graphic();
	virtual void Draw() = 0;
	virtual void Render(RenderWindow* window) = 0;
	virtual FloatRect GetGlobalRec(int nr) = 0;

};

#endif