#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

#include "reader.h"
#include "interface.h"

//getset方法
void reader::addreader(int id, char na[]) {
        no = id;
        strcpy_s(name, na);
        r_del = 1;
}

void reader::setbrbook(book bt) {
        brbook = bt;
}

rdatabase::rdatabase() {
        reader rd;
        top = -1;
        fstream file("reader.txt", ios::in);
        while (1) {
                file.read((char*)&rd, sizeof(rd));
                if (!file) break;
                top++;
                rdarray[top] = rd;
        }
        file.close();
}

rdatabase::~rdatabase() {
        fstream file("reader.txt", ios::out);
        for (int i = 0; i <= top; i++) {
                if (rdarray[i].r_del == 1)
                        file.write((char*)&rdarray[i], sizeof(rdarray[i]));
        }
        file.close();
}

void rdatabase::addreaders() {
        reader rd;
        int no;
        char rname[20];
        cout << "请输入学号:";
        cin >> no;
        cout << endl << "请输入姓名:";
        cin >> rname;
        cout << endl;
        rd.addreader(no, rname);
        rd.r_bor = 2;
        top++;
        rdarray[top] = rd;
        return;
}

int rdatabase::findreaders(int suffix) {
        int no;
        cout << "请输入学号:";
        cin >> no;
        for (int i = 0; i <= top; i++) {
                if (rdarray[i].no == no && rdarray[i].r_del == 1) {
                        return i;
                }
        }
        return -1;
}

int rdatabase::findreaders() {
        int no;
        char value[3];
        cout << "请输入学号:";
        cin >> no;
        for (int i = 0; i <= top; i++) {
                if (rdarray[i].no == no && rdarray[i].r_del == 1) {
                        if (rdarray[i].r_bor == 1)
                                strcpy_s(value, "借");
                        if (rdarray[i].r_bor == 2)
                                strcpy_s(value, "无");
                        cout << "学号:" << rdarray[i].no << "  " << "\t姓名:" << rdarray[i].name << "  " << "\t是否借书:" << value << endl;
                        return i;
                }
        }
        return -1;
}

void rdatabase::editreaders() {
        int cur;
        cur = findreaders();
        if (cur == 1) {
                cout << "未找到该用户" << endl;
                return;
        }
        cout << "请修改数据:" << endl;
        cout << endl << "姓名:";
        cin >> rdarray[cur].name;
        return;
}

void rdatabase::delreaders() {
        int cur;
        cur = findreaders();
        if (cur == 1) {
                return;
        }
        if (rdarray[cur].r_bor == 1) {
                cout << "该用户已借出图书,请归还后删除!" << endl;
                return;
        }
        rdarray[cur].r_del = 2;
        cout << "删除成功！" << endl;
        return;
}

void rdatabase::displayreaders() {
        char value[3];
        for (int i = 0; i <= top; i++) {
                if (rdarray[i].r_del == 1) {
                        if (rdarray[i].r_bor == 1)
                                strcpy_s(value, "借");
                        if (rdarray[i].r_bor == 2)
                                strcpy_s(value, "无");
                        cout << "学号:" << rdarray[i].no << "  " << "姓名:" << rdarray[i].name << "  " << "是否借书:" << value << endl;
                }
        }
        return;
}

void readersmange() {
        char in;
        rdatabase bd;
        do {
                system("pause");  
                system("cls");
                Reader_Maintenance_Interface();
                cin >> in;
                switch (in) {
                case'1':
                        bd.addreaders();
                        break;
                case'2':
                        bd.editreaders();
                        break;
                case'3':
                        bd.delreaders();
                        break;
                case'4':
                        bd.findreaders();
                        break;
                case'5':
                        bd.displayreaders();
                        break;
                case'6':
                        break;
                default:
                        cout << "输入错误，请重新输入！" << endl;
                }
        } while (in != '6');
        return;
}