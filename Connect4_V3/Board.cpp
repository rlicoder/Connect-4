/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.cpp
 * Author: Drake
 * 
 * Created on March 21, 2021, 6:31 PM
 */
#include <bits/stdc++.h>

#include "Board.h"

using namespace std;

Board::Board()
{
    for (int i = 0; i < rowSze; i++)
    {
        for (int j = 0; j < colSze; j++)
        {
            board[i][j] = ' ';
        }
    }
}

Board::Board(string moves)
{
    bool oneturn = true;
    for (int i = 0; i < (int)moves.size(); i++)
    {
        this->place(moves[i] - '0', oneturn);
        oneturn = !oneturn;
    }
}

void Board::displayBoard()
{
    for (int i = 0; i < rowSze; i++)
    {
        for (int j = 0; j < colSze; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Board::place(int col, bool oneturn)
{
    bool set = false;
    for (int i = 5; i >= 0; i--)
    {
        if (board[i][col] != ' ')
        {
            continue;
        }
        else
        {
            board[i][col] = (oneturn ? 'X' : 'O');
            set = true;
            break;
        }
    }
    return set;
}
