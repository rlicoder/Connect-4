
#ifndef GAMEHIST_H
#define GAMEHIST_H

#include <bits/stdc++.h>

using namespace std;

class GameHist
{
    private:
	string moves;  // Holds moves as a string
	string playerO; // Holds player O name
	string playerX; // Holds player X name
    
    public:
        // Set the game history
	GameHist(string po_name, string px_name, string moveHist);

    
};

#endif /* GAMEHIST_H */
