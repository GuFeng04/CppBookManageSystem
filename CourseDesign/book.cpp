#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "interface.h"
#include "reader.h"
using namespace std;

//getset����
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
        b_flag = 2;         //���飬��flag���ó�2��ʾ���ȥ
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

//���캯��
bdatabase::bdatabase() {
        book b;           
        top = -1;                                        //�����±��0��ʼ,�˴�topֵ��Ϊ-1�ɱ�֤�������һ��Ԫ�ؿ�ʼ�洢��Ϣ
        fstream file("book.txt", ios::in);
        if (!file)
        {
                cerr << "ERROR��" << endl;
                exit(1);
        }
        while (1) {
                file.read((char*)&b, sizeof(b));//���ļ��ж�ȡb���ַ���char*ָ��Ļ�����(book�����b�ĵ�ַ)
                if (!file)                                      //��ȡ���ļ�βEOF,���ط�0ֵ(һ��Ϊ1)
                        break;
                top++;
                btarray[top] = b;
        }
        file.close();
}

bdatabase::~bdatabase() {
        fstream file("book.txt", ios::out);//������д���ļ�
        if (!file)
        {
                cerr << "ERROR��" << endl;
                exit(1);
        }
        for (int i = 0; i <= top; i++) {
                if (btarray[i].b_del == 1)
                        file.write((char*)&btarray[i], sizeof(btarray[i]));
        }
        file.close();
}

void bdatabase::addbooks() {
        book bk;                       //����book�����bk
        int no;                        
        char bname[20];                
        cout << "���������:";
        cin >> no;
        cout << endl << "����������:";
        cin >> bname;
        cout << endl;
        bk.b_flag = 1;
        bk.addbook(no, bname);          //���г�Ա����addbook(),������������� �޸ı�־
        top++;
        btarray[top] = bk;
        return;                           //�����ϸ���������
}

int bdatabase::findbooks(int suffix) {
        int no;
        cout << "���������:";
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
        cout << "���������:";
        cin >> no;
        for (int i = 0; i <= top; i++) {
                if (btarray[i].no == no && btarray[i].b_del == 1) {
                        if (btarray[i].b_flag == 1)
                                strcpy_s(value, "�ڼ�");
                        if (btarray[i].b_flag == 2)
                                strcpy_s(value, "���");
                        cout << "���:" << btarray[i].no << "  " << "����:" << btarray[i].name << "  " << "ͼ��״̬:" << value << endl;
                        return i;
                }
        }
        return -1;
}

void bdatabase::editbooks() {
        int cur;
        cur = findbooks();
        if (cur == 1) {
                cout << "���鲻����" << endl;
                return;
        }
        cout << "��ǰͼ����Ϣ:\t" << "���:" << btarray[cur].no << "  " << "����:" << btarray[cur].name << endl;
        cout << endl;
        cout << "�޸�ͼ����Ϣ" << endl;
        cout << endl << "����:";
        cin >> btarray[cur].name;
        return;
}

void bdatabase::delbooks() {
        int cur;
        cur = findbooks();
        if (cur == 1) {
                cout << "ɾ���ɹ���" << endl;
                return;
        }
        if (btarray[cur].b_flag == 2) {       //ɾ��ʱ�ж�ͼ���Ƿ���
                cout << "��ͼ���Ѿ����,�޷�ɾ��!" << endl;
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
                                strcpy_s(value, "�ڼ�");
                        if (btarray[i].b_flag == 2)
                                strcpy_s(value, "���");
                        cout << "���:" << btarray[i].no << "\t����:" << btarray[i].name << "\tͼ��״̬:" << value << endl;
                }
        }
        return;
}

void borrow_or_return(char br) { //���顢����
        int reader_ID = 0;  
        int book_ID = 0;    
        int rsuffix, bsuffix;
        bdatabase t_bd;
        rdatabase t_rd;
        if (br == '1') {    //����
                rsuffix = t_rd.findreaders(reader_ID);
                bsuffix = t_bd.findbooks(book_ID);
                if (rsuffix == -1 || bsuffix == -1)
                        return;
                if (t_bd.btarray[bsuffix].b_flag == 2) {
                        cout << "ͼ���Ѿ����,��ѡ������ͼ��" << endl;
                        return;
                }
                t_bd.btarray[bsuffix].b_flag = 2;
                t_rd.rdarray[rsuffix].r_bor = 1;
                t_rd.rdarray[rsuffix].brbook = t_bd.btarray[bsuffix];
                cout << t_rd.rdarray[rsuffix]. name<<" ���� "<< t_bd.btarray[bsuffix].name<<" �ɹ���" << endl;
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
                        cout << "����������,���߽���ͼ����Ŵ���" << endl;
                        return;
                }
                cout << t_rd.rdarray[rsuffix].name<<" �黹 "<< t_bd.btarray[bsuffix]. name<<" �ɹ���" << endl;
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
                        cout << "����������������룡" << endl;
                }
        } while (in != '6');
        return;
}