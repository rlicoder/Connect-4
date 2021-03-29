#ifndef PLAYER_H
#define PLAYER_H

#include <bits/stdc++.h>

using namespace std;

class Player
{
    private:
        string name;
        int wins;
        int losses;
        vector<string> gameHist;

    public:
        //default
        Player();

	//hash constructor, get data from database
	Player(string);

};

#endif /* PLAYER_H */

