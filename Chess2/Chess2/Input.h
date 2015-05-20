#ifndef INPUT_H_
#define INPUT_H_

// Includes
#include <iostream>
#include "Match.h"

class Input
{
private:
	//Attributes

public:
	//Functions
	Input();
	~Input();
	int InputMove(RenderWindow* win,bool targeted);
	int InputMouse();
	//Get/Set functions
};
#endif
