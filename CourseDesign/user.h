#pragma once
#include <string>
using namespace std;
class User
{
private:
	string uname;
	string upwd;
public:
	User() {};
	int Login();	//��¼���ɹ�����1��ʧ�ܷ���-1
	void save();	//���浽�ļ�
	void read();	//���ļ��ж�ȡ
};
void login();