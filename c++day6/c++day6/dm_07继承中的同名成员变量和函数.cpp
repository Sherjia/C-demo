#include <iostream>
using namespace std;

class A
{
public:
	int a, b;
	void get()
	{
		cout << " b " << b << endl;
	}
	void print()
	{
		cout << "AAAA" << endl;
	}
protected:
private:
};

class B : public A
{
public:
	int b, c;
	void get_child()
	{
		cout << " b " << b << endl;
	}
	void print()
	{
		cout << "BBBB" << endl;
	}
protected:
private:
};

//ͬ����Ա����
void main71()
{
	B b1;
	b1.b = 1;//Ĭ�����޸�����ĳ�Աb //b1.B::b = 1;
	b1.get_child();

	b1.A::b = 100;//����A��::���÷����޸ĸ���ĳ�Աb
	b1.get();

	cout << "hello..." << endl;
	return;
}
//ͬ����Ա����
void main()
{
	B b1;
	b1.print();//Ĭ���ǵ�������ĳ�Ա����//b1.B::print();

	b1.A::print();//����A��::���÷������ø���ĳ�Ա����

	return;
}
