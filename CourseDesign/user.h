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
	int Login();	//登录，成功返回1，失败返回-1
	void save();	//保存到文件
	void read();	//从文件中读取
};
void login();