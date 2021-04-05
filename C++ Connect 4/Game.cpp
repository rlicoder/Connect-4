#include <bits/stdc++.h>
#include "Game.h"

using namespace std;

Game::Game()
{
    this->gamestate = false;
    this->moves = "";
}

/*Game::Game(string moves)
{
    
}*/

Game::~Game() 
{
    delete board;
}

void Game::start()
{
    this->gamestate = true;
    this->oneturn = true;
    board = new Board; // Assign new board object to board pointer
    while (this->gamestate) 
    {
        board->displayBoard();
        cout << "Choose your column, " << (oneturn ? "Player 1 " : "Player 2 ") << endl;
	int col;
	cin >> col;
	while (!board->place(col, oneturn))
	{
	    cout << "Try again: ";
	    cin >> col;
	}
	this->addMove(col + '0');
        this->oneturn = !this->oneturn;
        if (this->win()>0)
	{
            this->gamestate = false;
	}
    }
    board->displayBoard();
}

int Game::win()
{
    int win = 0;
    //check the general win conditions
    for (int i = 0; i < board->getRowSze(); i++)
    {
        for (int j = 0; j < board->getColSze(); j++)
        {
            if (board->getSlot(i,j) == ' ')
            {
                continue;
            }
            int count = 0;
            for (int k = i, l = j; k < i+4 && l < j+4 && k < board->getRowSze() && l < board->getColSze(); k++, l++)
            {
                if (board->getSlot(k,l) == board->getSlot(i,j))
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << board->getSlot(i,j) << " won via downright" << endl;
                return board->getSlot(i,j) == 'X' ? 1 : 2;
            }
            count = 0;
            for (int k = i, l = j; k > i-4 && l > j-4 && k >= 0 && l >= 0; k--, l++)
            {
                if (board->getSlot(k,l) == board->getSlot(i,j))
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << board->getSlot(i,j) << " won via upright" << endl;
                return board->getSlot(i,j) == 'X' ? 1 : 2;
            }
            count = 0;
            for (int k = i; k < i+4 && k < board->getRowSze(); k++)
            {
                if(board->getSlot(k,j) == board->getSlot(i,j))
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << board->getSlot(i,j) << " won via downup" << endl;
                return board->getSlot(i,j) == 'X' ? 1 : 2;
            }
            count = 0;
            for (int k = j; k < j+4 && k < board->getColSze(); k++)
            {
                if (board->getSlot(i,k) == board->getSlot(i,j))
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << board->getSlot(i,j) << " won by rightleft" << endl;
                return board->getSlot(i,j) == 'X' ? 1 : 2;
            }
        }
    }
    //check if the board is full
    bool full = true;
    board->displayBoard();
    for (int i = 0; i < board->getRowSze(); i++)
    {
	for (int j = 0; j < board->getColSze(); j++)
	{
	    if (board->getSlot(i,j) == ' ')
	    {
		full = false;
		break;
	    }
	}
    }
    return (full ? 3 : win);
}

string Game::getMoves()
{
    return this->moves;
}


void Game::addMove(char move)
{
    this->moves += move;
}