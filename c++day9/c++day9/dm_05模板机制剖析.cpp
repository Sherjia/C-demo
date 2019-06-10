#include <iostream>
using namespace std;

/*
����ģ����ƽ���
	�����������ǰ�ģ�庯��������ܹ�����������ĺ���
	�������Ӻ���ģ��ͨ���������Ͳ�����ͬ�ĺ���
	��������Ժ���ģ��������α��룺
	1.�������ĵط���ģ����뱾����б��� 2.�ڵ��õĵط��Բ����滻��Ĵ�����б���
*/

//1.cpp

//g++ -S 1.cpp
template <typename T>
void myswap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

void main()
{
	{
		int x = 10;
		int y = 20;

		myswap<int>(x, y);//����ģ�� ��ʾ���� ����
		//myswap(x, y);//����ģ���Զ������Ƶ� ������
		printf("x:%d,y:%d\n", x, y);
	}

	{
		char a = 'a';
		char b = 'b';

		myswap<char>(a, b);//����ģ�� ��ʾ���� ����
		//myswap(a, b);//����ģ���Զ������Ƶ� ������
		printf("a:%c,b:%c\n", a, b);
	}
}

