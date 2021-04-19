/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include"playerHst.h"


// Generate a random History
playerHst::playerH(int size){
    mResult = new int(size);
    for(int i=0;i<size;i++){
        mResult[i]=rand()%2;
    }
    ofstream file(getName1()+".dat");
    for(int i=0;i<size;i++){
        file<<mResult[i]<<"\t"<<getTime();
    }
    file.close();
}

// Get current time&date
string playerHst::getTime(){
    time_t t;
    time(&t);
    string print = asctime(localtime(&t));
    return print;
}

void playerHst::setName(string n1, string n2){
    pName1=n1;
    pName2=n2;
}

string playerHst::getName1(){
    return pName1;
}

string playerHst::getName2(){
    return pName2;
}

// Print the specific player's history
string playerHst::getHst(string name){
    string temp;
    ifstream file(name+".dat");
    while(getline(file,temp)){
        getline(file,temp);
        return temp;
    }
    return 0; // delete this
}

void playerHst::setUsrCheck(bool c){
    usrCheck=c;
}