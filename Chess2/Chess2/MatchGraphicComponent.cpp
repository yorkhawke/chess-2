#include "MatchGraphicComponent.h"

MatchGraphicComponent::MatchGraphicComponent(int width, int height) :Graphic(width, height)
{

}

MatchGraphicComponent::~MatchGraphicComponent()
{

}

void MatchGraphicComponent::Draw()
{

	if (!font.loadFromFile("OptimusPrinceps.ttf"))
	{
		return;
	}
	if (!tex.loadFromFile("Pieces2.png"))
	{
		return;
	}

	FloatRect Tr = winText.getLocalBounds();
	winText.setOrigin(Tr.left + Tr.width / 2.0f, Tr.top + Tr.height / 2.0f);
	winText.setPosition(Vector2f(300, 300));
	winText.setFont(font);
	Sp1.setTexture(tex);
	Sp2.setTexture(tex);

	sprite.setTexture(tex);
	sprite.setTextureRect(IntRect(480, 0, 80, 80));
	Vector2f pos(0, 0);


	//Drawing the board
	bool o = false;
	for (int i = 0; i < 64; i++)
	{
		if (i % 2 == 0)
		{
			if (i == 0)
				o = false;
			else if (i < 8 && i > 0 || i < 24 && i>15 || i < 40 && i > 31 || i < 56 && i > 47)
				o = false;
			else
				o = true;

		}
		else
		{
			if (i < 8 && i>0 || i < 24 && i>15 || i < 40 && i>31 || i < 56 && i > 47)
				o = true;
			else
				o = false;
		}
		Board[i] = Square(pos, sprite, o);
		if (pos.x < 560)
		{
			pos.x += 80;
		}
		else
		{
			pos.x = 0;
			pos.y += 80;
		}
	}
}

void  MatchGraphicComponent::Render(RenderWindow* win)
{
	for (int i = 0; i < 64; i++)
	{
		win->draw(Board[i].GetTexture());
	}
}

FloatRect MatchGraphicComponent::GetGlobalRec(int nr)
{
	if and shit
}
Sprite MatchGraphicComponent::GetSprite(int nr)
{
	if (nr == 1)
	{
		return Sp1;
	}
	if (nr == 2)
	{
		return Sp2;
	}
}

