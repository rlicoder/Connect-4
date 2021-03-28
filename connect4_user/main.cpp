#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std; 

//user information
struct UserInfo
{
	char username[20];
	char password[20];
};


//new user register
void regest(){
    UserInfo inf;
    inf.username;
    inf.password;
    string temp;
    int flag = 0;
    int i = 0;
    int j = 0;
    ifstream in("UserInfo.txt", ios::in);
    ofstream out("UserInfo.txt", ios::app);

    cout << "Enter user name:\n";
    cin >> inf.username;
    cout << "Enter password: \n";
    cin >> inf.password;

    while (getline(in, temp))//read data and save to temp
    {
        i++;
        if (i % 2 == 0){
            continue;
        }
        if (!strcmp(inf.username, temp.c_str())) {
            flag = 1;
        }//flag=1 means the username has been registered
    }
    in.close();
    if (flag){
        j = 0;
    }
    else{
        out << inf.username << endl;
        out << inf.password << endl;
        out.close();
        j = 1;
    } // write username and password
    switch (j)
    {
    case 1:
        cout << "Successfully registered." << endl;
        break;
    case 0:
        cout << "The username has been registered, please select another username." << endl;
        break;
    default:
        break;
    }
}
void login(){
    char username[20];
    char password[20];

    string temp1;
    string temp2;
    int existName = 0;
    int match = 0;
    int i = 0;
    int j = 0;

    cout << "Enter your username: \n";
    cin >> username;
    cout << "Enter your password: \n";
    cin >> password;
    ifstream in("UserInfo.txt", ios::in);
    while (getline(in, temp1))
    {
        getline(in, temp2);//read username and password
        if (!strcmp(username, temp1.c_str())){
                existName = 1;
                if (!strcmp(password, temp2.c_str())){
                        match = 1;
                        break;
                }
        }//check the username if it is exist then compare the password
    }
    in.close();
    if (!existName){
        j = 2;//user name does not exist
    }
    else{
        if(match){
            j = 1;
        }
        else{
            j = 3;
        }
    }
    switch (j)
    {
        case 1:
            cout << "Successfully login in." << endl;
            break;
        case 2:
            cout << "The username does not exit." << endl;
            break;
        case 3:
            cout << "Wrong password." << endl;
            break;
        default:
            return;
    }
        
}
void Edit(){
    char username[20];
    char password[20];
    char newpassword[20];
    string temp1;
    string temp2;
    string line;
    int existName = 0;
    int match = 0;
    int i = 0;
    int j = 0;
    fstream in("UserInfo.txt", ios::in);
    ofstream outfile("temp.txt", ios::out | ios::trunc);
    cout << "Enter your username: \n";
    cin >> username;
    cout << "Enter your password: \n";
    cin >> password;
    while (getline(in, temp1))
    {
        getline(in, temp2);//read username and password
        if (!strcmp(username, temp1.c_str())){
            existName = 1;
            if (!strcmp(password, temp2.c_str())){
                match = 1;
            }
        }//check the username if it is exist then compare the password
        else{
            outfile << temp1 << endl;
            outfile << temp2 << endl;
        }
    }
    outfile.close();
    in.close();
    fstream file("temp.txt", ios::in);
    ofstream out("UserInfo.txt", ios::trunc | ios::out);
    if (!existName){
        j = 2;//user name does not exist
    }
    else{
        if(match){
            while (getline(file, line)) {
                out << line << endl;
            }
            cout << "Please enter your new password:" << endl;
            cin >> newpassword;
            out << username << endl;
            out << newpassword << endl;
        }
        else{
            cout << "Wrong password, please login again." << endl;
        }
    }
    file.close();
    out.close();
    system("del temp.txt");
}
void menu(){
    int c;
    
    cout << "1.Register.\n";
    cout << "2.login in.\n";
    cout << "3.Change new password.\n";
    cin >> c;
    
    switch(c){
        case 1:
            regest();
            break;
        case 2:
            login();
            break;
        case 3:
            Edit();
            break;
        default:
            break;
    }
}
int main()
{
    menu();

    return 0;
    
}
