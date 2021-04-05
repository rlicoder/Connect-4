#include <bits/stdc++.h>
#include "Game.h"


using namespace std;

int main()
{
    Game game;
    
    game.start(); // Round 1
    
    game.start(); // Round 2
    
    fstream db;
    db.open("database.txt");
    int numPlayers;
    db >> numPlayers;
    vector<Player> players (numPlayers);
    for (int i = 0; i < numPlayers; i++)
    {
        string e_key;
        int wins, losses, numGames;
        db >> e_key >> wins >> losses >> numGames;
        for (int j = 0; j < numGames; j++)
        {
            
        }
    }
    db.close();
    
    return 0;
}
