#include <iostream>
using namespace std;

void myfunc(int a)
{
	cout << "a" << "\t" << a <<  endl;
}
void myfunc(char *p)
{
	cout << "p" << "\t" <<p << endl;
}
void myfunc(int a, int b)
{
	cout << "a" << "\t" << a << endl;
	cout << "b" << "\t" << b << endl;
}
void myfunc(char *p1, char *p2)
{
	cout << "p1" << "\t" << p1 << endl;
	cout << "p2" << "\t" << p2 << endl;
}

//����ָ��
//����һ����������

//void myfunc(int a,int b) 
typedef void(myTypeFunc)(int a, int b); //�Զ�����������
//myTypeFunc *myfuncp = NULL;//����һ������ָ�룬ָ��ָ��������ڵ�ַ

//����һ������ָ������
typedef void(*myPTypeFunc)(int a, int b);//����һ��ָ�����������
//myPTypeFunc fp = NULL;//ͨ�� ����ָ������ ������һ������ָ��


//����һ������ָ����� 
void(*myVarPFunc)(int a, int b);

void main()
{
	myPTypeFunc fp;//������һ������ָ�����

	fp = myfunc;
	fp(1, 2);//�ϸ�ƥ���ѡ�ߵĺ��������뺯��ָ��ĺ�������
	
	
	/*
	{
		char buf1[] = "aaaaffff";
		char buf2[] = "bbbb";

		fp(buf1, buf2);
	}
	*/

	cout << "kb" << endl;
	return;
}