#include <iostream>
using namespace std;

void myfunc(int a)
{
	cout << "a" << "\t" << a <<  endl;
}
void myfunc(char *p)
{
	cout << "p" << "\t" <<p << endl;
}
void myfunc(int a, int b)
{
	cout << "a" << "\t" << a << endl;
	cout << "b" << "\t" << b << endl;
}
void myfunc(char *p1, char *p2)
{
	cout << "p1" << "\t" << p1 << endl;
	cout << "p2" << "\t" << p2 << endl;
}

//函数指针
//声明一个函数类型

//void myfunc(int a,int b) 
typedef void(myTypeFunc)(int a, int b); //自定义数据类型
//myTypeFunc *myfuncp = NULL;//定义一个函数指针，指针指向函数的入口地址

//声明一个函数指针类型
typedef void(*myPTypeFunc)(int a, int b);//声明一个指针的数据类型
//myPTypeFunc fp = NULL;//通过 函数指针类型 定义了一个函数指针


//定义一个函数指针变量 
void(*myVarPFunc)(int a, int b);

void main()
{
	myPTypeFunc fp;//定义了一个函数指针变量

	fp = myfunc;
	fp(1, 2);//严格匹配候选者的函数类型与函数指针的函数类型
	
	
	/*
	{
		char buf1[] = "aaaaffff";
		char buf2[] = "bbbb";

		fp(buf1, buf2);
	}
	*/

	cout << "kb" << endl;
	return;
}