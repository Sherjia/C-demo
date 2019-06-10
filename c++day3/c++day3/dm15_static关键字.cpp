#include <iostream>
using namespace std;

class BB
{
public:
	void AddC()
	{
		c += 1;
	}
	void printC()
	{
		cout << "c:" << c << endl;
	}
	static void getC()//静态成员函数
	{
		cout << "c:" << c << endl;
		//请问在静态成员函数中可以调用普通成员属性或者普通成员函数吗？
		//cout << "a:" << a << endl;//error C2597: 对非静态成员“BB::a”的非法引用
	}
protected:
private:
	int a;
	int b;
	static int c;//静态成员变量

};
//静态函数中 不能使用普通成员变量和 普通成员函数
int BB::c = 10;

void main()
{
	BB b1, b2, b3;
	b1.printC();
	b2.AddC();
	b3.printC();

	//静态成员函数的调用方法
	b3.getC();//用对象.
	BB::getC();//类::

	cout << "hello..." << endl;
	return;
}
