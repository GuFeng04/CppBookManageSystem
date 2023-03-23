#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "user.h"
using namespace std;

const int  SIZE = 100;//最大用户容量
int userCount = 0;//用户数量，用count控制长度
User user[SIZE];
User user1;


void User::save()
{
	ofstream ofile;
	ofile.open("user.txt", ios::out);

	for (int i = 0; i < userCount; i++)
	{
		ofile << user[i].uname << endl;
		ofile << user[i].upwd << endl;
	}
	ofile.close();
}

void User::read()
{
	ifstream ifile;
	ifile.open("user.txt", ios::in);

	userCount = 0;

	if (!ifile.is_open())
	{
		cout << "user打开失败！" << endl;
		return;
	}

	for (int i = 0; !ifile.eof(); i++)
	{
		ifile >> user[i].uname;
		ifile >> user[i].upwd;
		userCount++;
	}
	userCount--;
	ifile.close();
}
int User::Login()
{
	user1.read();//读取已储存用户数据
	string inuname;
	string inupwd;
here:
	cout << "\t************************图 书 信 息 后 台************************" << endl<<endl;
	cout << "\t\n\n                          请输入用户名：";
	cin >> inuname;
	cout << "\t\n\n                          请输入密码：";
	cin >> inupwd;
	cout << "\n\n\t*******************************************************************" << endl;
	cout << endl;
	for (int i = 0;i < userCount;i++) {
		if (inuname == user[i].uname || inupwd == user[i].upwd) {
			cout << "\n\n";
			cout << "                                  \\ 登录成功！/" << endl;
			system("pause");
			return 1;
		}
	}
	cout << "                                  错误，请重新输入！" << endl;
	system("pause");
	return -1;
}
void login() {
	User user2;
	while (1)
	{
		system("cls");
		if (user2.Login() == 1)
			break;
	}
}