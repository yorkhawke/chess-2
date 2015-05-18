#include "Match.h"

Match::Match()
{

}

Match::~Match()
{

}

void Match::PlayMatch(RenderWindow* win)
{
	Sprite Sp1, Sp2;
	Sprite sprite;
	Texture tex;
	Font font;
	bool endOfGame=false;
	Text winText;
	//Loading Texture and Font
	if (!font.loadFromFile("OptimusPrinceps.ttf"))
	{
		win->close();
	}
	if (!tex.loadFromFile("Pieces2.png"))
	{
		win->close();
	}
	//Positioning Text
	FloatRect Tr = winText.getLocalBounds();
	winText.setOrigin(Tr.left + Tr.width / 2.0f, Tr.top + Tr.height / 2.0f);
	winText.setPosition(Vector2f(300, 300));
	winText.setFont(font);
	Sp1.setTexture(tex);
	Sp2.setTexture(tex);
	//Creating players
	Player p1(1, 0, "Player 1", false, Sp1);
	Player p2(2, 0, "Player 2", false, Sp2);

	p1.ResetPieces(true);
	p2.ResetPieces(false);


	sprite.setTexture(tex);
	sprite.setTextureRect(IntRect(480, 0, 80, 80));
	Vector2f pos(0, 0);
	Square Board[64];

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

	Event ev;
	bool turn=true;
	bool keft = false;
	Vector2f PreviousPos;
	//Starting the match loop, in Tournament class we could have a attribute that makes this loop 3 times and then decide the winner... it felt unneccesary atm.
	while (win->isOpen())
	{
		while (win->pollEvent(ev))
		{
			if ((ev.type == Event::Closed) || ((ev.type == Event::KeyPressed) && ev.key.code == Keyboard::Escape))
				win->close();
			//Rendering the pieces and the board
			win->clear();
			for (int i = 0; i < 64; i++)
			{
				win->draw(Board[i].GetTexture());
			}
			p1.RenderPieces(win);
			p2.RenderPieces(win);
			win->display();
			//gives player1 the first turn becuase player one is by default the white player.
			if (turn)
			{
				keft = p1.PlayTurn(win, keft);
				if (keft)
				{
					turn = false;
					keft = false;
					p1.ResetCol();
					PreviousPos = p1.GetPreviousPosition();
					p2.CheckTakenOut(PreviousPos);
					//When Player2 king has died enters here and shows the ending screen. Likewise for player1...
					if (p2.KingIsDead())
					{
						while (!endOfGame)
						{
							winText.setString("Player 1 Wins\n Press Y to quit");
							win->clear();
							win->draw(winText);
							win->display();
							if (Keyboard::isKeyPressed(Keyboard::Y))
								win->close();


						}
					}
				}
			}
			else
			{
				keft=p2.PlayTurn(win,keft);
				if (keft)
				{
					turn = true;
					keft = false;
					p2.ResetCol();
					PreviousPos = p2.GetPreviousPosition();
					p1.CheckTakenOut(PreviousPos);
					if (p1.KingIsDead())
					{
						while (endOfGame==false)
						{

							winText.setString("Player 2 Wins/n Press Y to quit");
							win->clear();
							win->draw(winText);
							win->display();
							if (Keyboard::isKeyPressed(Keyboard::Y))
								win->close();


						}

					}
				}
			}

		}


	}


}


