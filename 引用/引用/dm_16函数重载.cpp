#include <iostream>
using namespace std;

void myPrint(int a)
{
	cout << "a" << " " << a << endl;
}

void myPrint(char* p)
{
	cout << "p" << " " << p << endl;
}
void myPrint(int a, int b)
{
	cout << "a" << " " << a << endl;
	cout << "b" << " " << b << endl;
}
/*
//��������ֵ��ͬ���Ǻ������ص��жϱ�׼������������������벻ͨ��
int myPrint(int a, int b)
{
	cout << "a" << " " << a << endl;
	cout << "b" << " " << b << endl;
}
*/

//���õ�ʱ����Ҳ�����ƥ���
int main1601()
{
	myPrint(1);
	myPrint("hdasiuhs");
	myPrint(2, 6);
	
	cout << "hello..." << endl;
	return 0;
}

//����Ĭ�ϲ��� �� �������� ��һ��

void myfunc(int a, int b, int c = 0)
{
	cout << "a" << " " << a << endl;
	cout << "b" << " " << b << endl;
	cout << "c" << " " << c << endl;
}

void myfunc(int a, int b)
{
	cout << "a" << " " << a << endl;
	cout << "b" << " " << b << endl;
}
void myfunc(int a)
{
	cout << "a" << " " << a << endl;
}

void main()
{
	//myfunc(1, 2);//��������ʱ�������������

	myfunc(8);
	cout << "hello..." << endl;
	return;
}