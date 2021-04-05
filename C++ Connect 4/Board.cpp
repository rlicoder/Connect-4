#include <bits/stdc++.h>

#include "Board.h"

using namespace std;

Board::Board()
{
    board = vector<vector<char>> (rowSze, vector<char>(colSze));
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
    board = vector<vector<char>> (rowSze, vector<char>(colSze));
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

// Will get the slot on the board
char Board::getSlot(int row, int col) 
{
    if (row < rowSze && col < colSze && row >= 0 && col >= 0)
    {
	//throw an error.
    }
    return board[row][col];
}

bool Board::place(int col, bool oneturn)
{
    if (col < 0 || col > 6)
    {
	return false;
    }
    bool set = false;
    for (int i = this->getRowSze()-1; i >= 0; i--)
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

const int Board::getColSze()
{
    return this->colSze;
}

const int Board::getRowSze()
{
    return this->rowSze;
}
