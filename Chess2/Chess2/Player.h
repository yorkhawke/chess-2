// Includes
#ifndef PLAYER_H
#define PLAYER_H
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

public:
	//Functions
	Player();
	Player(int,int,string,bool);
	~Player();
	//Get/Set functions
	int GetID();
	void SetID(int);
	int GetNrOfWins();
	void SetNrOfWins(int);
	string GetName();
	void SetName(string);

};
#endif
