#include "Player.h"

Player::Player() 
{
    //initialize everything to blanks 
    this->name = "";
    this->wins = 0;
    this->losses = 0;
    this->encryption_key = "";
    this->history = vector<GameHist>();
}

Player::Player(string encryption_key)
{
    //search the database, and fill in the data if you find the appropriate player.
}

int Player::getWins()
{
    return this->wins;
}

int Player::getLosses()
{
    return this->losses;
}

string Player::getEncryption_Key()
{
    return this->encryption_key;
}

string Player::getName()
{
    return this->name;
}

void Player::setWins(int swins)
{
    this->wins = swins;
}

void Player::setLosses(int slosses)
{
    this->losses = slosses;
}

void Player::setName(int sname)
{
    this->name = sname;
}

void Player::setEncryption_Key(string sencryption_key)
{
    this->encryption_key = sencryption_key;
}