#include <iostream>
using namespace std;

void myPrint(int a)
{
	cout << "a" << " " << a << endl;
}

void myPrint(char* p)
{
	cout << "p" << " " << p << endl;
}
void myPrint(int a, int b)
{
	cout << "a" << " " << a << endl;
	cout << "b" << " " << b << endl;
}
/*
//函数返回值不同不是函数重载的判断标准，下面这个函数，编译不通过
int myPrint(int a, int b)
{
	cout << "a" << " " << a << endl;
	cout << "b" << " " << b << endl;
}
*/

//调用的时候就找参数最匹配的
int main1601()
{
	myPrint(1);
	myPrint("hdasiuhs");
	myPrint(2, 6);
	
	cout << "hello..." << endl;
	return 0;
}

//函数默认参数 和 函数重载 在一起

void myfunc(int a, int b, int c = 0)
{
	cout << "a" << " " << a << endl;
	cout << "b" << " " << b << endl;
	cout << "c" << " " << c << endl;
}

void myfunc(int a, int b)
{
	cout << "a" << " " << a << endl;
	cout << "b" << " " << b << endl;
}
void myfunc(int a)
{
	cout << "a" << " " << a << endl;
}

void main()
{
	//myfunc(1, 2);//函数调用时，会产生二义性

	myfunc(8);
	cout << "hello..." << endl;
	return;
}