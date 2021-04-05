#include<iostream>
#include<fstream>
#include<string>
#include<ctime>

#include"playerHst.h"

using namespace std;

// Function Prototype
void menu(string,bool);
string time();
int totalM(string);
int totalW(string);
int totalL(string);

// Program executes here
int main() {
    string username="test";
    string username1="test1";
    bool stat = true;
    
    srand(static_cast<unsigned int>(time(0)));
    
    playerHst history;
    history.setName(username,username1);
    
    //menu(username,stat);
    
    return 0;
}

// Menu 
void menu(string u, bool s){
    int c;
    string user=u+".txt";       // Create a text file for the player
    
    // Looping menu
    do{
        cout<<"==========MENU=========="<<endl;
        cout<<"[1] Write current status"<<endl;
        cout<<"[2] Print data"<<endl;
        cout<<"[0] Exit"<<endl;
        cin>>c;
        switch(c){
            case 1:{
                // Output the game status and current time into player's file
                ofstream out;
                out.open(user,fstream::app);
                out<<s<<"\t"<<time();
                out.close();  
                break;
            }
                
            // Print from file
            case 2:
                string text;
                int w=totalW(user);
                int l=totalL(user);
                int m=totalM(user);
                
                ifstream in(user);
                while(getline(in,text)){
                    cout<<text<<endl;
                }
                cout<<"Total Match: "<<m<<endl;
                cout<<"Total W: "<<w<<endl;
                cout<<"Total L: "<<l<<endl;
                in.close();
                break;
        }
    }while(c!=0);
}

// Record the current time
string time(){
    time_t t;
    time(&t);
    string print = asctime(localtime(&t));
    return print;
}


// Count total matches
int totalM(string u){
    int m=0;
    string tmp;
    
    ifstream in(u);
    while(getline(in,tmp)){
        ++m;
    }
    return m;   
}

// Count total wins
int totalW(string u){
    int x,w=0;
    string tmp;
    ifstream in(u);
    
    // Read the file
    while(getline(in,tmp)){
        in>>x;
        if(x==1) w++;
    }
    
    in.close();
    return w;
}

// Count total loses
int totalL(string u){
    int x,l=0;
    string tmp;
    ifstream in(u);
    
    // Read the file
    while(getline(in,tmp)){
        in>>x;
        if(x==0) l++;
    }
    
    in.close();
    return l;
}