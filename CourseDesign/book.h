#pragma once
//ͼ�����ģ��
//ͼ����
class book {
public:
	int no;           
	char name[20];     
	int b_flag;        //1:�ڼ� 2:���
	int b_del;         //1:���� 2:ɾ��
public:
	book() {}        
	void setno(int n);			//���ñ��
	int getno();				//��ñ��
	void setname(char na[]);		//��������
	char* getname();			//�������
	void borbook();			//�����鼮
	void delbook();			//ɾ���鼮
	void addbook(int no, char na[]);//����鼮
};

//ͼ�����ݿ���
const int BMAX = 50;      
class bdatabase {
public:
	book btarray[BMAX];    //ͼ�鼯��
	int top;
public:
	bdatabase();
	~bdatabase();       //��������,д���ļ���
	void addbooks();                
	int findbooks(int suffix);      //����ͼ��,�ú������ڽ������,suffix�������±�
	int findbooks();                 //����ͼ��,�ú�������ͼ��ά��
	void editbooks();     //�༭ͼ��
	void delbooks();  //ɾ��ͼ��
	void displaybooks();      //��ʾȫ��ͼ��
};

void booksmanage(); //ͼ����Ϣ������� ����
void borrow_or_return(char br);//���ĺͻ���