#include <iostream>
using namespace std;

//数组类型基本语法知识梳理
//定义一个数组类型
//int a[10];

//定义一个指针数组类型

//定义一个指向 数组类型的指针 数组类的指针

void main01()
{
	int a[10];//a代表的是数组首元素的地址 &a代表整个数组的地址 a+1（4） &a+1（40）步长不一样

	//
	{
		//定义一个数组类型
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("%d\n", myArray[0]);
	}

	
	{
		//定义一个指针数组类型
		typedef int(*PTypeAraay)[10];  //int *p;

		PTypeAraay myPArray; //sizeof(int) * 10;
		myPArray = &a;

		(*myPArray)[0] = 20;
		printf("a[0]: %d\n", a[0]);

	}

	{
		//定义一个指向 数组类型的指针 数组类的指针
		int(*MyPointer)[10];
		MyPointer = &a;
		(*MyPointer)[0] = 40;
		printf("a[0]: %d\n", a[0]);
	}

	cout << "hello..." << endl;
	return;
}

//函数指针基本语法知识梳理
//1.如何定义一个函数类型
//2.如何定义一个函数指针类型
//3.如何定义一个函数指针（指向一个函数的入口地址）

int add(int a, int b)
{
	printf("func add...\n");
	return a + b;
}

void main()
{
	add(1, 2); //直接调用 //函数名就是函数的入口地址

	//1.如何定义一个函数类型
	{
		typedef int(MyFuncType)(int a, int b); //定义了一个类型
		MyFuncType *myPointFunc = NULL; //定义了一个指针， 指向某一种类的函数

		myPointFunc = &add;//细节
		myPointFunc(3, 4);//间接调用

		myPointFunc = add;//细节 //c是逐渐完善的，兼容历史版本的原因，所以这两个都对
		myPointFunc(3, 4);//间接调用


	}

	//2.如何定义一个函数指针类型
	{
		typedef int(*MyPointFuncType)(int a, int b);//int *a = NULL;
		MyPointFuncType myPointerFunc;//定义一个指针
		myPointerFunc = add;
		myPointerFunc(5, 6);


	}

	//3.如何定义一个函数指针（指向一个函数的入口地址）
	{
		int(*MyPointerFunc)(int a, int b); //定义了一个变量
		MyPointerFunc = add;
		MyPointerFunc(7, 8);
	}
}