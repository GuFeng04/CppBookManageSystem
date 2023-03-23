#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "interface.h"
#include "reader.h"
using namespace std;

//getset方法
void book::setno(int n) {
        no = n;
}

int book::getno() {
        return no;
}

void book::setname(char na[]) {
        strcpy_s(name, na);
}

char* book::getname() {
        return name;
}

void book::borbook() {
        b_flag = 2;         //借书，将flag设置成2表示借出去
}

void book::delbook() {
        b_del = 2;           
}

void book::addbook(int no, char na[]) {
        setno(no);
        setname(na);
        b_flag = 1;
        b_del = 1;
}

//构造函数
bdatabase::bdatabase() {
        book b;           
        top = -1;                                        //数组下标从0开始,此处top值置为-1可保证从数组第一个元素开始存储信息
        fstream file("book.txt", ios::in);
        if (!file)
        {
                cerr << "ERROR！" << endl;
                exit(1);
        }
        while (1) {
                file.read((char*)&b, sizeof(b));//从文件中读取b个字符到char*指向的缓存中(book类对象b的地址)
                if (!file)                                      //读取到文件尾EOF,返回非0值(一般为1)
                        break;
                top++;
                btarray[top] = b;
        }
        file.close();
}

bdatabase::~bdatabase() {
        fstream file("book.txt", ios::out);//将内容写入文件
        if (!file)
        {
                cerr << "ERROR！" << endl;
                exit(1);
        }
        for (int i = 0; i <= top; i++) {
                if (btarray[i].b_del == 1)
                        file.write((char*)&btarray[i], sizeof(btarray[i]));
        }
        file.close();
}

void bdatabase::addbooks() {
        book bk;                       //创建book类对象bk
        int no;                        
        char bname[20];                
        cout << "请输入书号:";
        cin >> no;
        cout << endl << "请输入书名:";
        cin >> bname;
        cout << endl;
        bk.b_flag = 1;
        bk.addbook(no, bname);          //类中成员函数addbook(),设置书号与书名 修改标志
        top++;
        btarray[top] = bk;
        return;                           //返回上个操作界面
}

int bdatabase::findbooks(int suffix) {
        int no;
        cout << "请输入书号:";
        cin >> no;
        for (int i = 0; i <= top; i++) {
                if (btarray[i].no == no && btarray[i].b_del == 1) {
                        return i;
                }
        }
        return -1;
}

int bdatabase::findbooks() {
        int no;
        char value[6];
        cout << "请输入书号:";
        cin >> no;
        for (int i = 0; i <= top; i++) {
                if (btarray[i].no == no && btarray[i].b_del == 1) {
                        if (btarray[i].b_flag == 1)
                                strcpy_s(value, "在架");
                        if (btarray[i].b_flag == 2)
                                strcpy_s(value, "借出");
                        cout << "书号:" << btarray[i].no << "  " << "书名:" << btarray[i].name << "  " << "图书状态:" << value << endl;
                        return i;
                }
        }
        return -1;
}

void bdatabase::editbooks() {
        int cur;
        cur = findbooks();
        if (cur == 1) {
                cout << "该书不存在" << endl;
                return;
        }
        cout << "当前图书信息:\t" << "书号:" << btarray[cur].no << "  " << "书名:" << btarray[cur].name << endl;
        cout << endl;
        cout << "修改图书信息" << endl;
        cout << endl << "书名:";
        cin >> btarray[cur].name;
        return;
}

void bdatabase::delbooks() {
        int cur;
        cur = findbooks();
        if (cur == 1) {
                cout << "删除成功！" << endl;
                return;
        }
        if (btarray[cur].b_flag == 2) {       //删除时判断图书是否借出
                cout << "该图书已经借出,无法删除!" << endl;
                return;
        }
        btarray[cur].b_del = 2;
        return;
}

void bdatabase::displaybooks() {
        char value[6];
        for (int i = 0; i <= top; i++) {
                if (btarray[i].b_del == 1) {
                        if (btarray[i].b_flag == 1)
                                strcpy_s(value, "在架");
                        if (btarray[i].b_flag == 2)
                                strcpy_s(value, "借出");
                        cout << "书号:" << btarray[i].no << "\t书名:" << btarray[i].name << "\t图书状态:" << value << endl;
                }
        }
        return;
}

void borrow_or_return(char br) { //借书、还书
        int reader_ID = 0;  
        int book_ID = 0;    
        int rsuffix, bsuffix;
        bdatabase t_bd;
        rdatabase t_rd;
        if (br == '1') {    //借书
                rsuffix = t_rd.findreaders(reader_ID);
                bsuffix = t_bd.findbooks(book_ID);
                if (rsuffix == -1 || bsuffix == -1)
                        return;
                if (t_bd.btarray[bsuffix].b_flag == 2) {
                        cout << "图书已经借出,请选择其它图书" << endl;
                        return;
                }
                t_bd.btarray[bsuffix].b_flag = 2;
                t_rd.rdarray[rsuffix].r_bor = 1;
                t_rd.rdarray[rsuffix].brbook = t_bd.btarray[bsuffix];
                cout << t_rd.rdarray[rsuffix]. name<<" 借阅 "<< t_bd.btarray[bsuffix].name<<" 成功！" << endl;
                system("pause");
                return;
        }
        if (br == '2') {
                rsuffix = t_rd.findreaders(reader_ID);
                bsuffix = t_bd.findbooks(book_ID);
                if (rsuffix == -1 || bsuffix == -1)
                        return;
                if (t_rd.rdarray[rsuffix].brbook.no == t_bd.btarray[bsuffix].no) {
                        t_bd.btarray[bsuffix].b_flag = 1;
                        t_rd.rdarray[rsuffix].r_bor = 2;
                        t_rd.rdarray[rsuffix].brbook = t_bd.btarray[bsuffix];
                }
                else {
                        cout << "请重新输入,读者借阅图书书号错误" << endl;
                        return;
                }
                cout << t_rd.rdarray[rsuffix].name<<" 归还 "<< t_bd.btarray[bsuffix]. name<<" 成功！" << endl;
                system("pause");
                return;
        }
}

void booksmanage() {
        char in;
        bdatabase bd;
        do {
                system("pause");
                system("cls");
                Book_Maintenance_Interface();
                cin >> in;
                switch (in) {
                case'1':
                        bd.addbooks();
                        break;
                case'2':
                        bd.editbooks();
                        break;
                case'3':
                        bd.delbooks();
                        break;
                case'4':
                        bd.findbooks();
                        break;
                case'5':
                        bd.displaybooks();
                        break;
                case'6':
                        break;
                default:
                        cout << "输入错误，请重新输入！" << endl;
                }
        } while (in != '6');
        return;
}