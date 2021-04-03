#include "Player.h"

Player::Player() 
{
<<<<<<< HEAD
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
=======
    // Interface to input player info
    cout << "Input player name: ";
    cin >> this->name;
    // Initialize wins and losses
    wins = 0;
    losses = 0;
>>>>>>> 6c1618d0eac581bd902df4610e9ea07f5e4f9ede
}

void Player::setEncryption_Key(string sencryption_key)
{
    this->encryption_key = sencryption_key;
}