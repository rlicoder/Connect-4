#ifndef BOARD_H
#define BOARD_H

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Board
{
    private:
        vector<vector<char>> board;
        const int rowSze = 6;
        const int colSze = 7;
    public:
        //default constructor
        Board();

        //moves constructor
        Board(string moves);

        void displayBoard();
        //get slot on board
        char getSlot(int row, int col);

        bool place(int col, bool oneturn);

	int getRowSze();

	int getColSze();
};


#endif /* BOARD_H */

