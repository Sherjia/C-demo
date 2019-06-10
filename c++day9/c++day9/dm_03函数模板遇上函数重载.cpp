#include <iostream>
using namespace std;

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
	cout << "我是模板函数" << endl;
}

void myswap(int a, char c)
{
	cout << "a:" << a << " c:" << c << endl;
	cout << "我是普通函数" << endl;
}



void main()
{
	int a = 10;
	char c = 'z';

	myswap(a, c);//普通函数的调用：可以进行隐式的类型转换
	myswap(c, a);//普通函数的调用：可以进行隐式的类型转换
	
	myswap(a, a);//函数模板的调用（本质：类型参数化），将严格地按照类型匹配，不会进行自动类型转化

	

	cout << "hello..." << endl;
	return;
}