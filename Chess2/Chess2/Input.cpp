#include "Input.h"
Input::Input()
{

}
Input::~Input()
{

}

int Input::InputMove(RenderWindow* win,bool targeted)
{
	Event ev;
	win->pollEvent(ev);
	if ((ev.type == Event::Closed) || ((ev.type == Event::KeyPressed) && ev.key.code == Keyboard::Escape))
		return -1;
	if (Mouse::isButtonPressed(Mouse::Right) && targeted == false)
		return 1;
	if (Mouse::isButtonPressed(Mouse::Left) && targeted == false)
		return 2;
	if (Mouse::isButtonPressed(Mouse::Right) && targeted == true)
		return 3;
	if (Mouse::isButtonPressed(Mouse::Left) && targeted == true)
		return 4;

}

bool Input::inputEsc(RenderWindow* win)
{
	Event ev;
	win->pollEvent(ev);
	if ((ev.type == Event::Closed) || ((ev.type == Event::KeyPressed) && ev.key.code == Keyboard::Escape))
		return true;
}

