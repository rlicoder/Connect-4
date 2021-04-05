/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   playerHst.h
 * Author: johnn
 *
 * Created on April 4, 2021, 4:17 PM
 */

#ifndef PLAYERHST_H
#define PLAYERHST_H

#include<cstdlib>
#include<iostream>
using namespace std;

class playerH{
    private:
        int *mResult;
        string pName1, pName2;
        bool usrCheck;
    public:
        playerH(int);
        string getName1();
        string getName2();
        void setName(string,string);
        string getTime();
        string getHst(string);
        void setUsrCheck(bool);
};

#endif /* PLAYERHST_H */

