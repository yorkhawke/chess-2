#ifndef MATCH_H_
#define MATCH_H_


// Includes
#include <iostream>
#include "Input.h"
#include "Player.h"
#include "Square.h"
#include "Graphics.h"
#include "MatchGraphicComponent.h"

#define SCRWIDTH 800
#define SCRHEIGHT 660

using namespace sf;

class Match
{
private:
	//Attributes
	bool game = { true };

public:
	//Functions
	Match();
	~Match();
	void PlayMatch(RenderWindow* win);

	//Get/Set functions
};
#endif
