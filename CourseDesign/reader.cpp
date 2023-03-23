#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

#include "reader.h"
#include "interface.h"

//getset����
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
        cout << "������ѧ��:";
        cin >> no;
        cout << endl << "����������:";
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
        cout << "������ѧ��:";
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
        cout << "������ѧ��:";
        cin >> no;
        for (int i = 0; i <= top; i++) {
                if (rdarray[i].no == no && rdarray[i].r_del == 1) {
                        if (rdarray[i].r_bor == 1)
                                strcpy_s(value, "��");
                        if (rdarray[i].r_bor == 2)
                                strcpy_s(value, "��");
                        cout << "ѧ��:" << rdarray[i].no << "  " << "\t����:" << rdarray[i].name << "  " << "\t�Ƿ����:" << value << endl;
                        return i;
                }
        }
        return -1;
}

void rdatabase::editreaders() {
        int cur;
        cur = findreaders();
        if (cur == 1) {
                cout << "δ�ҵ����û�" << endl;
                return;
        }
        cout << "���޸�����:" << endl;
        cout << endl << "����:";
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
                cout << "���û��ѽ��ͼ��,��黹��ɾ��!" << endl;
                return;
        }
        rdarray[cur].r_del = 2;
        cout << "ɾ���ɹ���" << endl;
        return;
}

void rdatabase::displayreaders() {
        char value[3];
        for (int i = 0; i <= top; i++) {
                if (rdarray[i].r_del == 1) {
                        if (rdarray[i].r_bor == 1)
                                strcpy_s(value, "��");
                        if (rdarray[i].r_bor == 2)
                                strcpy_s(value, "��");
                        cout << "ѧ��:" << rdarray[i].no << "  " << "����:" << rdarray[i].name << "  " << "�Ƿ����:" << value << endl;
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
                        cout << "����������������룡" << endl;
                }
        } while (in != '6');
        return;
}