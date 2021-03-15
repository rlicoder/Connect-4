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
int regest(struct UserInfo* user){
	char username[20];
	char password[20];
	strcpy(username, user->username);
	strcpy(password, user->password);
	string temp;
	int flag = 0;
	int i = 0;
	ifstream in("UserInfo.txt", ios::in);
	ofstream out("UserInfo.txt", ios::app);
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
		return 0;
	}
	else{
		out << username << endl;
		out << password << endl;
		out.close();
		return 1;
	} // write username and password
}
int login(struct UserInfo* user){
	char username[20];
	char password[20];
	strcpy(username, user->username);
	strcpy(password, user->password);
	string temp1;
	string temp2;
	int existName = 0;
	int match = 0;
	int i = 0;
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
		return 2;//user name does not exist
	}
	else{
		if(match){
                    return 1;
                }
		else{
                    return 3;
                }
	}
}
int main()
{
	UserInfo test1;
	strcpy(test1.username, "admin");
	strcpy(test1.password, "password");
	switch (regest(&test1))
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
 
	UserInfo test2;
	strcpy(test2.username, "admin");
	strcpy(test2.password, "password");
	switch (login(&test2))
	{
	case 1:
		cout << "Logging in...." << endl;
		break;
	case 3:
		cout << "Wrong password, please login again." << endl;
		break;
	case 2:
		cout << "The username was not found." << endl;
		break;
	default:
		break;
	}
	return 0;
}
