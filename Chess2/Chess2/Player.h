// Includes
#ifndef PLAYER_H
#define PLAYER_H
#include "PieceHeader.h"
#include <iostream>
#include <string.h>

using namespace std;
class Player
{
private:
	//Attributes
	int ID;
	int NrOfWins;
	string Name;
	bool Concede;
	Piece* pieces[16];
	Vector2f PreviousPosition;

public:
	//Functions
	Player();
	Player(int,int,string,bool,Sprite);
	~Player();
	void ResetPieces(bool);
	bool PlayTurn(RenderWindow* window,bool);
	//Get/Set functions
	int GetID();
	void SetID(int);
	int GetNrOfWins();
	void SetNrOfWins(int);
	string GetName();
	void SetName(string);
	bool GetConcede();
	void SetConcede(bool);
	Sprite GetPieceTexture(int);
	void RenderPieces(RenderWindow*);
	void ResetCol();
	Vector2f GetPreviousPosition();
	void CheckTakenOut(Vector2f);
	bool KingIsDead();
};
#endif
