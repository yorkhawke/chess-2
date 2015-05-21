#ifndef PLAYTURN_H
#define PLAYTURN_H
#include<SFML/Graphics.hpp>
#include "Piece.h"
#include "Input.h"
class PlayTurn
{
private:
	Input inp;
	bool targeted;
	Vector2f PreviousPosition;
public:
	PlayTurn();
	~PlayTurn();
	void Turn(Piece* PiecesP1[], Piece* PiecesP2[], RenderWindow* win);
	void show(Piece* PiecesP1, Piece* PiecesP2);//kanske fixa?
	bool checkMove(Piece* [], Piece* [], Vector2f, Piece*);
};


#endif