#include <iostream>
using namespace std;

//基类定义的静态变量，将被所有派生类共享

class A
{
public:
	A()
	{
		cout << "A的构造函数" << endl;
	}
public:
	static int a;
	int	b;
	void get()
	{
		cout << " b " << b << endl;
	}
	void print()
	{
		cout << "AAAA" << endl;
	}
protected:
private:
};

int A::a = 100;//不只是简单的变量赋值，重要的是让编译器分配内存，我在继承类中用到了a,否则会报错的

class B : private A
{
public:
	B()
	{
		cout << "B的构造函数" << endl;
	}
public:
	int b, c;
	void get_child()
	{
		cout << " b " << b << endl;
		cout << a << endl;
	}
	void print()
	{
		cout << "BBBB" << endl;
	}
protected:
private:
};

//1.static关键字依然遵循派生类的访问控制规则
//2.不只是简单的变量赋值，重要的是让编译器分配内存，我在继承类中用到了a,否则会报错的
//3.A类中添加构造函数 不写在public里就默认是私有的构造函数，被别的类继承要小心；单例场景中希望是私有的
void main()
{
	A a1;
	a1.print();

	B b1;
	b1.get_child();

	return;
}
