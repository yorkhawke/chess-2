#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Piece.h"

using namespace sf;

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
};

#endif