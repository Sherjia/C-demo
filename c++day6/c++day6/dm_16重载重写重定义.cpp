#include <iostream>
using namespace std;

//重写 重载 重定义
//重写发生在2个类之间
//重载必须在一个类之间

//重写分为2类
//1.虚函数重写 将要发生多态
//2.非虚函数重写（重定义）

class Parent
{
	//这三个函数都是重载关系
public:
	void abc()//没有virtual关键字，就是重写中的函数重定义
	{
		printf("abc");
	}
	virtual void func()
	{
		cout << "func() do..." << endl;
	}
	virtual void func(int i)
	{
		cout << "func() do..." <<i<< endl;
	}
	virtual void func(int i, int j)
	{
		cout << "func() do..." << i <<" "<<j<< endl;
	}
	virtual void func(int i, int j, int k, int n)
	{
		cout << "func() do..." << i << " " << j << endl;
	}
protected:
private:
};

class Child : public Parent
{
public:
	void abc()//没有virtual关键字，就是重写中的函数重定义
	{
		printf("child abc");
	}
	void abc(int l, int m, int n)
	{
		printf("child lmn");
	}
	virtual void func(int i, int j)
	{
		cout << "func(int i, int j) do..." << i << " " << j << endl;
	}
	virtual void func(int i, int j, int k)
	{
		cout << "func(int i, int j, int k) do..." << endl;
	}
protected:
private:
};


void main()
{
	// error C2661: “Child::func”: 没有重载函数接受 0 个参数
	Child c1;
	//c1.func()  //错误
	c1.Parent::func();//正确，显式地调用一把
	//func函数的名字，在子类中发生了名称的覆盖：子类函数的名字，占用了父类函数的名字的位置
	//因为子类中已经有了func名字的重载形式
	//编译器开始在子类中找func函数...但是没有0个参数的func函数

	
	//1.c++编译器看到func名称，因子类中已经存在（名称覆盖），所以编译器不会去找父类的4个参数的func函数
	//2.c++编译器只会在子类中查找func函数，找到两个func，一个是2个参数的，一个是3个参数的
	//3.c++编译器开始报错：error C2661: “Child::func”: 没有重载函数接受 4 个参数
	//若想调用父类的func函数，只能显式地调用：c1.Parent::func(1, 2, 3,4);
	//c1.func(1, 2, 3,4);  //错误

	
	
	//子类无法重载父类的函数，父类同名函数将被覆盖
	//重载要在同一类之间
	//c1.abc(1, 2, 3);  //错误
	

	cout << "hello..." << endl;
	return;
}