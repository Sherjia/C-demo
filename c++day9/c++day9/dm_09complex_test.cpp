#include <iostream>
using namespace std;
#include "dm_09complex.cpp"//����ģ��ͺ���ģ��ľ�Ҫд���ͷ�ļ�����Ϊ��ģ��Ļ��ƾ��Ƕ��α���



void main()
{

	//��Ҫ��ģ������廯�Ժ󣬲��ܶ������ c++��������Ҫ�����ڴ�
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;
	//Complex operator+(Complex &c2);��Ա����ʵ��+�����������

	cout << c3 << endl;
	//ostream& operator<<(ostream& out, Complex& c3);<<ֻ����ȫ�ֺ���ʵ�����أ����һ�Ҫ�趨Ϊ�����Ԫ����

	/*
	//������Ԫ����
	{
		Complex<int> c4 = MySub(c1, c2);
		cout << c4 << endl;
	}
	*/

	cout << "hello..." << endl;
	return;
}