#include <iostream>
using namespace std;

/*
函数模板机制结论
	编译器并不是把模板函数处理成能够处理任意类的函数
	编译器从函数模板通过具体类型产生不同的函数
	编译器会对函数模板进行两次编译：
	1.在声明的地方对模板代码本身进行编译 2.在调用的地方对参数替换后的代码进行编译
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

