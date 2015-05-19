#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SFML\Graphics.hpp>
#include "Match.h"

class Graphic
{
private:

public:
	Graphic();
	~Graphic();
	virtual void Draw(Match& match)=0;//Eller vad vi nu behöver ha?!
};

#endif