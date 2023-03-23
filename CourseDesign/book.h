#pragma once
//图书管理模块
//图书类
class book {
public:
	int no;           
	char name[20];     
	int b_flag;        //1:在架 2:借出
	int b_del;         //1:存在 2:删除
public:
	book() {}        
	void setno(int n);			//设置编号
	int getno();				//获得编号
	void setname(char na[]);		//设置书名
	char* getname();			//获得名字
	void borbook();			//借阅书籍
	void delbook();			//删除书籍
	void addbook(int no, char na[]);//添加书籍
};

//图书数据库类
const int BMAX = 50;      
class bdatabase {
public:
	book btarray[BMAX];    //图书集合
	int top;
public:
	bdatabase();
	~bdatabase();       //析构函数,写入文件中
	void addbooks();                
	int findbooks(int suffix);      //查找图书,该函数用于借书操作,suffix是数组下标
	int findbooks();                 //查找图书,该函数用于图书维护
	void editbooks();     //编辑图书
	void delbooks();  //删除图书
	void displaybooks();      //显示全部图书
};

void booksmanage(); //图书信息管理界面 声明
void borrow_or_return(char br);//借阅和还书