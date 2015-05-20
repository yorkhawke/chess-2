#include "MenyGraphicComponent.h"

MenyGraphicComponent::MenyGraphicComponent(int width,int height) :Graphic(width,height)
{

}

MenyGraphicComponent::~MenyGraphicComponent()
{

}

void MenyGraphicComponent::Draw()
{

	//Texture 
	if (!backTex.loadFromFile("BackC.png"))
		return;
	backSprite.setTexture(backTex);

	if (!PlayB.loadFromFile("Play.png"))
		return;
	PlaySprite.setTexture(PlayB);

	if (!CloseB.loadFromFile("Close.png"))
		return;
	CloseSprite.setTexture(CloseB);

	//Sets the positions of the Sprites
	FloatRect backBound = backSprite.getGlobalBounds();
	FloatRect CloseBound = CloseSprite.getGlobalBounds();
	FloatRect PlayBound = PlaySprite.getGlobalBounds();


	backSprite.setOrigin(backBound.width / 2.0f, backBound.height / 2.0f);
	CloseSprite.setOrigin(CloseBound.width / 2.0f, CloseBound.height / 2.0f);
	PlaySprite.setOrigin(PlayBound.width / 2.0f, PlayBound.height / 2.0f);

	backSprite.setPosition(SCRWIDTH / 2.0f, SCRHEIGHT / 2.0f);
	PlaySprite.setPosition(SCRWIDTH / 2.0f, SCRHEIGHT / 2.0f);
	CloseSprite.setPosition(SCRWIDTH / 2.0f, ((SCRHEIGHT / 2.0f) + 60.0f));

	

}

void  MenyGraphicComponent::Render(RenderWindow* window)
{
	window->draw(backSprite);
	window->draw(PlaySprite);
	window->draw(CloseSprite);
}

FloatRect MenyGraphicComponent::GetGlobalRec(int nr)
{
	if (nr==1)
	return CloseSprite.getGlobalBounds();
	else
	return PlaySprite.getGlobalBounds();
}
