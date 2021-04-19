#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include <bits/stdc++.h>

using namespace std;

class Game
{
    private:
        Board *board; // Pointer to board object
        Player *player1;
        Player *player2;
	string moves;
        bool gamestate;
        bool oneturn;
        char cont;

    public:
        //default constructor
        Game();
        // Destructor
        virtual ~Game(); // Unexplained error, temporarily disabled
        //moves constructor
        //Game(string moves);

        //starts game
        void start();
        //checks win condition
        int win();

	string getMoves();

	void addMove(char move);
        void menu();
};


#endif /* GAME_H */
