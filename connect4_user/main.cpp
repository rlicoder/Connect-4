#include <iostream>
#include <fstream>
#include <cstring>

using namespace std; 

//user information
struct UserInfo
{
	char username[20];
	char password[20];
};


//new user register
void regest(){
	char username[20];
	char password[20];
	string temp;
	int flag = 0;
	int i = 0;
        int j = 0;
	ifstream in("UserInfo.txt", ios::in);
	ofstream out("UserInfo.txt", ios::app);
        
        cout << "Enter user name:\n";
        cin >> username;
        cout << "Enter password: \n";
        cin >> password;
        
	while (getline(in, temp))//read data and save to temp
	{
		i++;
		if (i % 2 == 0){
                    continue;
                }
		if (!strcmp(username, temp.c_str())) {
                    flag = 1;
                }//flag=1 means the username has been registered
	}
	in.close();
	if (flag){
		j = 0;
	}
	else{
		out << username << endl;
		out << password << endl;
		out.close();
		j = 1;
	} // write username and password
        switch (j)
	{
	case 1:
		cout << "Successfully registered." << endl;
	case 0:
		cout << "The username has been registered, please select another username." << endl;
	default:
            return;
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
            case 2:
		cout << "The username does not exit." << endl;
            case 3:
                cout << "Wrong password." << endl;
            default:
                return;
	}
        
}
void Edit(){
    	char username[20];
	char password[20];
        char newPassword[20];
	string temp1;
	string temp2;
        int existName = 0;
	int match = 0;
	int i = 0;
        int j = 0;
	ifstream in("UserInfo.txt", ios::in);
	ofstream out("UserInfo.txt", ios::app);
        
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
				break;
			}
		}//check the username if it is exist then compare the password
	}
        if (!existName){
		j = 2;//user name does not exist
	}
	else{
		if(match){
                    cout << "Please enter your new password:" << endl;
                    cin >> newPassword;
                    password == newPassword;
                    out << password << endl;    
                }
		else{
                    cout << "Wrong password, please login again." << endl;
                }
	}
}
void menu(){
    
    UserInfo info;
    int c;
    
    cout << "1.Register.\n";
    cout << "2.login in.\n";
    cout << "3.Change new password.\n";
    cin >> c;
    
    switch(c){
        case 1:
            regest();
        case 2:
            login();
        case 3:
            Edit();
        default:
            break;
    }
}
int main()
{
    menu();

    return 0;
    
}
