#include <iostream>
using namespace std;

void myPrint(int x = 3)
{
	cout << "x" << x << endl;
}

//如果默认参数，那么右边必须有默认参数
void myPrint2(int m, int x = 3, int y = 4)
{
	cout << "x" << x << endl;
}

void main11()
{
	//你写了，就使用你写的；不写，就用默认的
	myPrint(4);
	myPrint();

	cout << "hello..." << endl;
	return;
}
//函数占位参数，调用时，必须写够参数

void fun1(int x, int y, int)
{
	cout << "a" << a << "b" << b << endl;
}

void main11()
{
	fun1(1, 2, 3);
	//fun1(1,2)错误的

	cout << "hello..." << endl;
	return;
}

//默认参数和占位参数

void func2(int a, int b, int = 0)//int = 0为以后程序留下扩展
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