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

//同名成员变量
void main71()
{
	B b1;
	b1.b = 1;//默认是修改子类的成员b //b1.B::b = 1;
	b1.get_child();

	b1.A::b = 100;//加了A类::作用符，修改父类的成员b
	b1.get();

	cout << "hello..." << endl;
	return;
}
//同名成员函数
void main()
{
	B b1;
	b1.print();//默认是调用子类的成员函数//b1.B::print();

	b1.A::print();//加了A类::作用符，调用父类的成员函数

	return;
}
