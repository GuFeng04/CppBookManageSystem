#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "user.h"
using namespace std;

const int  SIZE = 100;//����û�����
int userCount = 0;//�û���������count���Ƴ���
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
		cout << "user��ʧ�ܣ�" << endl;
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
	user1.read();//��ȡ�Ѵ����û�����
	string inuname;
	string inupwd;
here:
	cout << "\t************************ͼ �� �� Ϣ �� ̨************************" << endl<<endl;
	cout << "\t\n\n                          �������û�����";
	cin >> inuname;
	cout << "\t\n\n                          ���������룺";
	cin >> inupwd;
	cout << "\n\n\t*******************************************************************" << endl;
	cout << endl;
	for (int i = 0;i < userCount;i++) {
		if (inuname == user[i].uname || inupwd == user[i].upwd) {
			cout << "\n\n";
			cout << "                                  \\ ��¼�ɹ���/" << endl;
			system("pause");
			return 1;
		}
	}
	cout << "                                  �������������룡" << endl;
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