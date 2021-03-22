/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Drake
 *
 * Created on March 21, 2021, 7:58 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <bits/stdc++.h>

using namespace std;


class Player
{
    private:
        string name;
        int wins;
        int losses;
        vector<string> gameHist;

    public:
        //default
        Player();

};

#endif /* PLAYER_H */

