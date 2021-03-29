#include "Player.h"

Player::Player() 
{
    // Interface to input player info
    cout << "Input player name: ";
    cin >> this->name;
    // Initialize wins and losses
    wins = 0;
    losses = 0;
}

