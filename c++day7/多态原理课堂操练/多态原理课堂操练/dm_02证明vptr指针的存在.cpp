#include <iostream>
using namespace std;

class Parent1
{
public:
	Parent1(int a = 0)
	{
		this->a = a;
	}
	void print() 
	{
		cout << "我是爹" << endl;
	}
private:
	int a;
};

class Parent2
{
public:
	Parent2(int a = 0)
	{
		this->a = a;
	}
	virtual void print() //1.动手脚的地方 ，写virtual关键字 会特殊处理 //虚函数表
	{
		cout << "我是爹" << endl;
	}
private:
	int a;
};

void main()
{
	printf("sizeof(Parent1):%d sizeof(Parent2):%d \n", sizeof(Parent1), sizeof(Parent2));
	//Parent1 4个字节， Parent2 8个字节

	cout << "hello..." << endl;
	return;
}