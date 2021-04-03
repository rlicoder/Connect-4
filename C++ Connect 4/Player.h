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




};

#endif /* PLAYER_H */
