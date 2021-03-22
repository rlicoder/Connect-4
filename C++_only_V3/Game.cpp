/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: Drake
 * 
 * Created on March 21, 2021, 6:37 PM
 */

#include <bits/stdc++.h>
#include "Game.h"

using namespace std;

Game::Game()
{
    
}

Game::Game(string moves)
{

}

void Game::start()
{
    oneturn = true;
    cout << "Test";
    while (gamestate) {
        board.displayBoard();
        cout << "Choose your column, " << (oneturn ? "Player 1 " : "Player 2 ");     
        if (this->win()>0)
            gamestate = false;
        oneturn = !oneturn;
    }
}

int Game::win()
{
    int win = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board.getSlot(i,j) == ' ')
            {
                continue;
            }
            char start = board.getSlot(i,j);
            int count = 0;
            for (int k = i, l = j; k < i+4 && l < j+4 && k < 6 && l < 7; k++, l++)
            {
                if (board.getSlot(k,l) == start)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << start << " won via downright" << endl;
                return start == 'X' ? 1 : 2;
            }
            count = 0;
            for (int k = i, l = j; k > i-4 && l > j-4 && k >= 0 && l >= 0; k--, l++)
            {
                if (board.getSlot(k,l) == start)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << start << " won via upright" << endl;
                return start == 'X' ? 1 : 2;
            }
            count = 0;
            for (int k = i; k < i+4 && k < 6; k++)
            {
                if(board.getSlot(k,j) == start)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << start << " won via rightleft" << endl;
                return start == 'X' ? 1 : 2;
            }
            count = 0;
            for (int k = j; k < j+4 && k < 7; k++)
            {
                if (board.getSlot(i,k) == start)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << start << " won by downup" << endl;
                return start == 'X' ? 1 : 2;
            }
        }
    }
    return win;
}