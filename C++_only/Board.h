/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: Drake
 *
 * Created on March 21, 2021, 6:31 PM
 */

#ifndef BOARD_H
#define BOARD_H

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Board
{
    private:
        vector<vector<char>> board;
        int rowSze = 7;
        int colSze = 6;
    public:
        //default constructor
        Board();

        //moves constructor
        Board(string moves);

        void displayBoard();
        //get slot on board
        char getSlot(int row, int col);

        bool place(int col, bool oneturn);
};


#endif /* BOARD_H */

