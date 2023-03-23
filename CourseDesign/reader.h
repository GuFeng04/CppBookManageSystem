#pragma once
#include"book.h"

//读书管理模块
//读者类
class reader {
public:
        int no;
        char name[20];
        int r_del;      //1存在    2删除
        int r_bor;      //1借过书  2未借书
        book brbook;
public:
        void addreader(int id, char na[]);   //增加读者
        void setbrbook(book bt); //设置借书标记
        book getbrbook() {
                return brbook;  //返回借书信息
        }
};

//读者数据库类
class rdatabase {
public:
        reader rdarray[BMAX];
        int top;
public:
        rdatabase();
        ~rdatabase();
        void addreaders();   //添加读者
        int findreaders(int suffix);      //查找读者,该函数用于借书还书操作,suffix是数组下标
        int findreaders();        //查找读者,该函数用于读者维护操作
        void editreaders();     //编辑读者信息
        void delreaders();      //删除读者,读者如果借书,需要还书后才能删除
        void displayreaders();      //显示所有读者
};

void readersmange();