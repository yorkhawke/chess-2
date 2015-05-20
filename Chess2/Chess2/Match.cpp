#include "Match.h"

Match::Match()
{

}

Match::~Match()
{

}

void Match::PlayMatch(RenderWindow* win)
{
	Input in;
	MatchGraphicComponent* mGrap = new MatchGraphicComponent(SCRWIDTH, SCRWIDTH);
	
	bool endOfGame=false;

	//Loading Texture and Font
	mGrap->Draw();

	//Creating players
	Player p1(1, 0, "Player 1", false);
	Player p2(2, 0, "Player 2", false);

	Piece* piecesPlayer1[16];

	Piece* piecesPlayer2[16];

	//pieces
	piecesPlayer1[0] = new Pawn(Vector2f(0, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[1] = new Pawn(Vector2f(80, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[2] = new Pawn(Vector2f(160, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[3] = new Pawn(Vector2f(240, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[4] = new Pawn(Vector2f(320, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[5] = new Pawn(Vector2f(400, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[6] = new Pawn(Vector2f(480, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[7] = new Pawn(Vector2f(560, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[8] = new Rook(Vector2f(0, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[9] = new Knight(Vector2f(80, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[10] = new Bishop(Vector2f(400, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[11] = new Queen(Vector2f(320, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[12] = new King(Vector2f(240, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[13] = new Bishop(Vector2f(160, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[14] = new Knight(Vector2f(480, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer1[15] = new Rook(Vector2f(560, 560), true, mGrap->GetSprite(), Color::White);
	//Player 2
	piecesPlayer2[0] = new Pawn(Vector2f(0, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[1] = new Pawn(Vector2f(80, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[2] = new Pawn(Vector2f(160, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[3] = new Pawn(Vector2f(240, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[4] = new Pawn(Vector2f(320, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[5] = new Pawn(Vector2f(400, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[6] = new Pawn(Vector2f(480, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[7] = new Pawn(Vector2f(560, 480), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[8] = new Rook(Vector2f(0, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[9] = new Knight(Vector2f(80, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[10] = new Bishop(Vector2f(400, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[11] = new Queen(Vector2f(320, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[12] = new King(Vector2f(240, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[13] = new Bishop(Vector2f(160, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[14] = new Knight(Vector2f(480, 560), true, mGrap->GetSprite(), Color::White);
	piecesPlayer2[15] = new Rook(Vector2f(560, 560), true, mGrap->GetSprite(), Color::White);

	InitPieces(piecesPlayer1,true);
	InitPieces(piecesPlayer2, false);
	mGrap->Draw();
	Event ev;
	//Starting the match loop, in Tournament class we could have a attribute that makes this loop 3 times and then decide the winner... it felt unneccesary atm.
	while (win->isOpen())
	{
		while (win->pollEvent(ev))
		{
			if (in.inputEsc(win))
				win->close();

			win->clear();
			mGrap->Render(win, piecesPlayer1, piecesPlayer2);
			win->display();

			//Playturn

		}
	}

}

void Match::InitPieces(Piece* pieces[],bool col)
{
	Vector2f pos;
	if (col)
	{
		pos = Vector2f(0, 480);
		for (int i = 0; i < 16; i++)//If col is true the player is white else it is black.
		{
			pieces[i]->SetPosition(pos);
			pieces[i]->SetColour(Color::White);
			pos.x += 80;
			if (pos.x>560)
			{
				pos.y += 80;
				pos.x = 0;
			}
		}
	}
	else
	{
		pos = Vector2f(0, 80);
		for (int i = 0; i < 16; i++)
		{
			pieces[i]->SetPosition(pos);
			pieces[i]->SetColour(Color::Black);
			pos.x += 80;
			if (pos.x >560)
			{
				pos.y -= 80;
				pos.x = 0;
			}
		}
	}
}



