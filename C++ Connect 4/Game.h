#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include <bits/stdc++.h>

using namespace std;

class Game
{
    private:
        Board board;
        Player player1;
        Player player2;
        bool gamestate;
        bool oneturn;

    public:
        //default constructor
        Game();

        //moves constructor
        Game(string moves);

        //starts game
        void start();
        //checks win condition
        int win();
};


#endif /* GAME_H */

