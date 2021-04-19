#ifndef BOARD_H
#define BOARD_H

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Board
{
    private:
        vector<vector<char>> board; //Store's the connect 4 board
        const int rowSze = 6; // number of rows in the column
        const int colSze = 7; // number of columns in the row
    public:
        //default constructor
        Board();

        //moves constructor
        Board(string moves);
        // displays the board
        void displayBoard();
        //get slot on board
        char getSlot(int row, int col);

        bool place(int col, bool oneturn); // Place an x/o on the board

	const int getRowSze(); // returns number of rows in the column

	const int getColSze(); // returns number of columns in the row
};


#endif /* BOARD_H */