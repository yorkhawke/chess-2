#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Match.h"

#define SCRWIDTH 800
#define SCRHEIGHT 660

int main()
{
	Match aMatch;
	RenderWindow window;
	Texture backTex,PlayB,CloseB;
	window.create(sf::VideoMode(SCRWIDTH, SCRHEIGHT), "Schack");

	//Texture 
	if (!backTex.loadFromFile("BackC.png"))
		return 1;
	Sprite backSprite(backTex);

	if (!PlayB.loadFromFile("Play.png"))
		return 1;
	Sprite PlaySprite(PlayB);

	if (!CloseB.loadFromFile("Close.png"))
		return 1;
	Sprite CloseSprite(CloseB);
	//Sets the positions of the Sprites
	FloatRect backBound = backSprite.getGlobalBounds();
	FloatRect CloseBound = CloseSprite.getGlobalBounds();
	FloatRect PlayBound = PlaySprite.getGlobalBounds();

	backSprite.setOrigin(backBound.width / 2.0f, backBound.height / 2.0f);
	CloseSprite.setOrigin(CloseBound.width / 2.0f, CloseBound.height / 2.0f);
	PlaySprite.setOrigin(PlayBound.width / 2.0f, PlayBound.height / 2.0f);

	backSprite.setPosition(SCRWIDTH / 2.0f, SCRHEIGHT / 2.0f);
	PlaySprite.setPosition(SCRWIDTH / 2.0f, SCRHEIGHT / 2.0f);
	CloseSprite.setPosition(SCRWIDTH / 2.0f, ((SCRHEIGHT / 2.0f)+60.0f));

	while (window.isOpen())
	{
		//Drawing the meny
		Event event;
		Mouse mousePos;
		window.clear();
		window.draw(backSprite);
		window.draw(PlaySprite);
		window.draw(CloseSprite);

		while (window.pollEvent(event))
		{
			if ((event.type == Event::Closed) || ((event.type == Event::KeyPressed) && event.key.code == Keyboard::Escape))
				window.close();
		}

		if (PlaySprite.getGlobalBounds().contains(mousePos.getPosition(window).x, mousePos.getPosition(window).y)&&Mouse::isButtonPressed(Mouse::Left))
		{
			//When Play is pressed enters to start the match.
			aMatch.PlayMatch(&window);
		}

		if (CloseSprite.getGlobalBounds().contains(mousePos.getPosition(window).x, mousePos.getPosition(window).y) && Mouse::isButtonPressed(Mouse::Left))
		{
			return 0;
		}

		window.display();
	}
	return 0;
}



