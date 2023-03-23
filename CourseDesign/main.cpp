#include <iostream>
using namespace std;

#include "interface.h"
#include "reader.h"
#include "user.h"
int main() {
        char in = -1; 
        login();
        do {
                Main_Interface();
                cin >> in;
                switch (in) {
                case'1':
                        borrow_or_return(in);
                        break;
                case'2':
                        borrow_or_return(in);
                        break;
                case'3':
                        booksmanage();
                        break;
                case'4':
                        readersmange();
                        break;
                case'0': {
                        cout << "退出成功!" << endl;
                        break;
                }
                default:
                        cout << "输入错误，请重新输入！" << endl;
                }
        } while (in != '0');
        return 0;
}