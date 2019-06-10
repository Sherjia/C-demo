#include <iostream>
using namespace std;

//函数的业务逻辑一样，但是函数的参数类型不一样
void myswap01(int &a, int &b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

void myswap02(char &a, char &b)
{
	char c = 0;
	c = a;
	a = b;
	b = c;
}

//让 类型参数化 === ，方便程序员进行编码
//泛型编程
//template是告诉编译器，我要开始泛型编程了, 看到T，不要随便报错
template <typename T>
void myswap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}
//函数模板的调用 1.显示函数调用 2.自动类型推导
void main()
{
	{
		int x = 10;
		int y = 20;

		myswap<int>(x, y);//函数模板 显示类型 调用
		//myswap(x, y);//函数模板自动类型推导 很少用
		printf("x:%d,y:%d\n", x, y);
	}

	{
		char a = 'a';
		char b = 'b';

		myswap<char>(a, b);//函数模板 显示类型 调用
		//myswap(a, b);//函数模板自动类型推导 很少用
		printf("a:%c,b:%c\n", a, b);
	}
}

void main11()
{
	{
		int x = 10;
		int y = 20;
		myswap01(x, y);
		printf("x:%d,y:%d\n", x, y);
	}
	{
		char a = 'a';
		char b = 'b';

		myswap02(a, b);
		printf("a:%c,b:%c\n", a, b);
	}

	cout << "hello..." << endl;
	return;
}
