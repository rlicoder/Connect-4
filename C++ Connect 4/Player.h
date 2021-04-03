#ifndef PLAYER_H
#define PLAYER_H

#include "GameHist.h"
#include <bits/stdc++.h>

using namespace std;

class Player
{
    private:
        string name;
        int wins;
        int losses;
        vector<GameHist> history;
	string encryption_key;

    public:
        //default
        Player();

	//basic login
	//hash constructor, get data from database
	Player(string);

	//get func
	string getName();
	string getEncryption_Key();
	int getWins();
	int getLosses();

	//set func
	void setName();
	void setEncryption_Key();
	void setWins();
	void setLosses();




	//hash constructor, get data from database
	Player(string);
        // Get player name
        string getName() { return name; }
        // Get player's wins
        int getWins() { return wins; }
        // Get player's losses
        int getLoss() { return losses; }
};

#endif /* PLAYER_H */
