#include <iostream>
#include <cstdlib>    
#include <string>
#include <fstream>

using namespace std;

void Main_Interface() {               
        system("cls"); 
        cout << "\t***************欢 迎 进 入 图 书 管 理 系 统***********************"<<endl;
        cout << "\t*\t            1.   借书                                     * " << endl;
        cout << "\t*\t            2.   还书                                     *  " << endl;
        cout << "\t*\t            3.   图书信息管理                             * " << endl;
        cout << "\t*\t            4.   读者信息管理                             * " << endl;
        cout << "\t*\t            0.   退出                                     *  " << endl;
        cout << "\t******************************************************************* " << endl;
        cout << "                                                             ";
        cout << "\t\n请选择您要执行的操作编号: ";
        cout << endl;
}

void Book_Maintenance_Interface() {                           //图书维护子菜单
        cout << "\t************************图 书 信 息 后 台************************" << endl;//与case顺序一致
        cout << "\t*\t            1.   添加                                     *" << endl;
        cout << "\t*\t            2.   修改                                     *" << endl;
        cout << "\t*\t            3.   删除                                     *" << endl;
        cout << "\t*\t            4.   查找                                     *" << endl;
        cout << "\t*\t            5.   显示                                     *" << endl;
        cout << "\t*\t            6.   返回上级操作                             * " << endl;
        cout << "\t*******************************************************************" << endl;
        cout << "                                                             ";
        cout << "\t\n请选择您要执行的操作编号: ";
        cout << endl;
}

void Reader_Maintenance_Interface() {                            //读者维护子菜单
        cout << "\t***************************读 者 信 息 后 台************************" << endl;//与case顺序一致
        cout << "\t*\t            1.   添加                                     *" << endl;
        cout << "\t*\t            2.   修改                                     *" << endl;
        cout << "\t*\t            3.   删除                                     *" << endl;
        cout << "\t*\t            4.   查找                                     *" << endl;
        cout << "\t*\t            5.   显示                                     *" << endl;
        cout << "\t*\t            6.   返回上级操作                             *" << endl;
        cout << "\t*******************************************************************" << endl;
        cout << "                                                             ";
        cout << "\t\n请选择您要执行的操作编号: ";
        cout << endl;
}
