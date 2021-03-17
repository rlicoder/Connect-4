#ifndef BOARD_H
#define BOARD_H

#include <bits/stdc++.h>

using namespace std;

class Board
{
    private:
        vector<vector<char>> board;

    public:
        //default constructor
        Board();

        //moves constructor
        Board(string moves);

        void displayBoard();
};

#endif


