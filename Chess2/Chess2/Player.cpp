#include "Player.h"
Player::~Player()
{
}
Player::Player()
{
	Concede = false;
  
}
Player::Player(int ID, int Nr, string name, bool c)//Creates the player Default Color is White
{
  this->ID=ID;
  this->NrOfWins=Nr;
  this->Name = name;
  this->Concede = c;

}

int Player::GetID()//Just basic set and get functions
{
  return this->ID;
}
void Player::SetID(int ID)
{
  this->ID=ID;
}
int Player::GetNrOfWins()
{
  return this->NrOfWins;
}
void Player::SetNrOfWins(int nr)
{
  this->NrOfWins = nr;
}
string Player::GetName()
{
  return this->Name;
}
void Player::SetName(string name)
{
  this->Name = name;
}
