#pragma once
#include"book.h"

//�������ģ��
//������
class reader {
public:
        int no;
        char name[20];
        int r_del;      //1����    2ɾ��
        int r_bor;      //1�����  2δ����
        book brbook;
public:
        void addreader(int id, char na[]);   //���Ӷ���
        void setbrbook(book bt); //���ý�����
        book getbrbook() {
                return brbook;  //���ؽ�����Ϣ
        }
};

//�������ݿ���
class rdatabase {
public:
        reader rdarray[BMAX];
        int top;
public:
        rdatabase();
        ~rdatabase();
        void addreaders();   //��Ӷ���
        int findreaders(int suffix);      //���Ҷ���,�ú������ڽ��黹�����,suffix�������±�
        int findreaders();        //���Ҷ���,�ú������ڶ���ά������
        void editreaders();     //�༭������Ϣ
        void delreaders();      //ɾ������,�����������,��Ҫ��������ɾ��
        void displayreaders();      //��ʾ���ж���
};

void readersmange();