#include <iostream>
using namespace std;

//�� ���Ͳ����� === ���������Ա���б���
//���ͱ��
//template�Ǹ��߱���������Ҫ��ʼ���ͱ����, ����T����Ҫ��㱨��
template <typename T>
void myswap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout << "����ģ�庯��" << endl;
}

void myswap(int a, char c)
{
	cout << "a:" << a << " c:" << c << endl;
	cout << "������ͨ����" << endl;
}



void main()
{
	int a = 10;
	char c = 'z';

	myswap(a, c);//��ͨ�����ĵ��ã����Խ�����ʽ������ת��
	myswap(c, a);//��ͨ�����ĵ��ã����Խ�����ʽ������ת��
	
	myswap(a, a);//����ģ��ĵ��ã����ʣ����Ͳ������������ϸ�ذ�������ƥ�䣬��������Զ�����ת��

	

	cout << "hello..." << endl;
	return;
}