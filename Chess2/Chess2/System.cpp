#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Match.h"
#include "Graphics.h"
#include "MenyGraphicComponent.h"

#define SCRWIDTH 800
#define SCRHEIGHT 660

int main()
{
	Match aMatch;
	RenderWindow window;
	Graphic* meny;
	meny = new MenyGraphicComponent(SCRWIDTH, SCRHEIGHT);
	window.create(sf::VideoMode(SCRWIDTH, SCRHEIGHT), "Schack");
	meny->Draw();
	while (window.isOpen())
	{
		//Drawing the meny
		Event event;
		Mouse mousePos;
		window.clear();

		meny->Render(&window);
		while (window.pollEvent(event))
		{
			if ((event.type == Event::Closed) || ((event.type == Event::KeyPressed) && event.key.code == Keyboard::Escape))
				window.close();
		}

		if (meny->GetGlobalRec(0).contains(mousePos.getPosition(window).x, mousePos.getPosition(window).y)&&Mouse::isButtonPressed(Mouse::Left))
		{
			//When Play is pressed enters to start the match.
			aMatch.PlayMatch(&window);
		}

		if (meny->GetGlobalRec(1).contains(mousePos.getPosition(window).x, mousePos.getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
		{
			return 0;
		}

		window.display();
	}
	return 0;
}



