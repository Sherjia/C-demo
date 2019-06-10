#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int myadd(int a, int b)//子任务的实现者
{
	printf("func add...\n");
	return a + b;
}
int myadd2(int a, int b)//子任务的实现者
{
	printf("func add2...\n");
	return a + b;
}
int myadd3(int a, int b)//子任务的实现者
{
	printf("func add3...\n");
	return a + b;
}
int myadd4(int a, int b)//子任务的实现者
{
	printf("func add4...\n");
	return a + b;
}

//定义一个类型
typedef int(*MyTypeFuncAdd)(int a, int b);

//函数指针做函数参数
int MainOp(MyTypeFuncAdd myFuncAdd)
{
	int c = myFuncAdd(5, 6);
	return c;
}

//也是函数指针做函数参数
//int(*MyPointerFuncAdd)(int a, int b);
int MainOp2(int(*MyPointerFuncAdd)(int a, int b))
{
	int c =  MyPointerFuncAdd(5, 6);//间接调用
	return c;
}

//间接调用
//任务的调用和任务的编写可以分开
void main()
{
	/*
	MyTypeFuncAdd myFuncAdd = NULL;
	myadd(1, 2);//直接调用

	myFuncAdd = myadd;
	myFuncAdd(3, 4);//间接调用

	MainOp(myadd);
	MainOp2(myadd);
	*/

	//在MainOp没有发生任何变化的情况下，可以把后来人写的代码调用起来
	MainOp(myadd2);//函数指针做函数参数，它传来的是函数的入口地址
	MainOp(myadd3);
	MainOp(myadd4);

	printf("hello...\n");
	return;
}