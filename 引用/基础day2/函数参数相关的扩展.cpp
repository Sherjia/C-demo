#include <iostream>
using namespace std;

void myPrint(int x = 3)
{
	cout << "x" << x << endl;
}

//���Ĭ�ϲ�������ô�ұ߱�����Ĭ�ϲ���
void myPrint2(int m, int x = 3, int y = 4)
{
	cout << "x" << x << endl;
}

void main11()
{
	//��д�ˣ���ʹ����д�ģ���д������Ĭ�ϵ�
	myPrint(4);
	myPrint();

	cout << "hello..." << endl;
	return;
}
//����ռλ����������ʱ������д������

void fun1(int x, int y, int)
{
	cout << "a" << a << "b" << b << endl;
}

void main11()
{
	fun1(1, 2, 3);
	//fun1(1,2)�����

	cout << "hello..." << endl;
	return;
}

//Ĭ�ϲ�����ռλ����

void func2(int a, int b, int = 0)//int = 0Ϊ�Ժ����������չ
{
	cout << "a" << a << "b" << b << endl;
}

void main()
{
	fun2(1, 2);
	fun2(1, 2, 3);

	cout << "hello..." << endl;
	return;
}