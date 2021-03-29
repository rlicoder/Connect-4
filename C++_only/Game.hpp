#include "Board.hpp"
#include "Player.hpp"
#include <bits/stdc++.h>

using namespace std;

class Game
{
    private:
        Board board;
        Player player1;
        Player player2;
        bool gameover;

    public:
        //default constructor
        Game();

        //moves constructor
        Game(string moves);

        //starts game
        void start();
};
