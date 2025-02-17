#include <iostream>
using namespace std;


//结论
//先调用父类构造函数 再调用子类构造函数
//析构函数的调用顺序相反

/*
1.子类对象在创建时会首先调用父类的构造函数
2.父类构造函数执行结束后，执行子类的构造函数
3.当父类的构造函数有参数时，需要在子类的初始化列表中显示调用
4.析构函数调用的先后顺序与构造函数相反
*/
class Parent
{
public:
	Parent(int a, int b)
	{
		this->a = a, this->b = b;
		cout << "父类构造函数...\n" << endl;
	}
	
	void printP(int a, int b)
	{
		this->a = a, this->b = b;
		cout << "我是爹...\n" << endl;
	}
	~Parent()
	{
		cout << "析构函数...\n" << endl;
	}
private:
	int a;
	int b;
};

class child : public Parent
{
public:
	child(int a, int b, int c) : Parent(a,b)//构造函数的初始化列表
	{
		this->c = c;
		cout << "子类的构造函数...\n" << endl;
	}
	~child()
	{
		cout << "子类的析构...\n" << endl;
	}
	void printC()
	{
		cout << "我是儿子" << endl;
	}
protected:
private:
	int c;
};
void playObj()
{
	child c1(1, 2, 3);
}
void main()
{
	//Parent p(1, 2);

	playObj();

	cout << "hello..." << endl;
	return;
}