#include <bits/stdc++.h>

#include "Board.hpp"

using namespace std;

Board::Board()
{
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board[i].size(); j++)
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
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board[i].size(); j++)
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
