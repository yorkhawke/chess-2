#ifndef INPUT_H_
#define INPUT_H_

// Includes
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
using namespace sf;
class Input
{
private:
	//Attributes

public:
	//Functions
	Input();
	~Input();
	int InputMove(RenderWindow* win,bool targeted);
	bool inputEsc(Event ev);
	//Get/Set functions
};
#endif
