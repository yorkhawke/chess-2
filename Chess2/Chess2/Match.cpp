#include "Match.h"

Match::Match()
{

}

Match::~Match()
{

}

void Match::PlayMatch(RenderWindow* win)
{
	Graphic* mGrap;

	mGrap = new MatchGraphicComponent(SCRWIDTH, SCRWIDTH);
	
	bool endOfGame=false;

	//Loading Texture and Font
	mGrap->Draw();

	//Creating players
	Player p1(1, 0, "Player 1", false, Sp1);
	Player p2(2, 0, "Player 2", false, Sp2);

	p1.ResetPieces(true);
	p2.ResetPieces(false);

	Event ev;
	bool turn=true;
	bool keft = false;
	Vector2f PreviousPos;
	//Starting the match loop, in Tournament class we could have a attribute that makes this loop 3 times and then decide the winner... it felt unneccesary atm.
	while (win->isOpen())
	{
		while (win->pollEvent(ev))
		{



			/*
			if ((ev.type == Event::Closed) || ((ev.type == Event::KeyPressed) && ev.key.code == Keyboard::Escape))
			win->close();
			//Rendering the pieces and the board
			win->clear();
			// move pieces rendering here....
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
			*/

		}
	}

}



