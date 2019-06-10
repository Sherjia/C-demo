#include <iostream>
using namespace std;

class A
{
public:
	//声明的位置和 public与private没关系
	friend void modifyA(A *pA, int _a);//加了关键字friend后 函数modifyA变成 类A的好朋友(友元函数) 可以访问A类的私有属性：a,b
	friend class B;//B类是A类的好朋友，在B中可以访问A类的私有成员或变量
	A(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{ 
		return this->a;
	}
protected:
private:
	int a, b;
};
class B
{
public:
	void Set(int a)
	{
		Aobject.a = a;
	}
	void printB()
	{
		cout << Aobject.a << endl;
	}
private:
	A Aobject;
};

void modifyA(A *pA, int _a)//友元函数的参数里，至少有一个A *pA，因为你要通过它访问类的私有属性
{
	//pA->a = 100;
	 pA->a = _a;
}

void main()
{
	B b1;
	b1.Set(300);
	b1.printB();
	return;
}

void main01()
{
	A a1(1, 2);
	cout << a1.getA()<< endl;

	modifyA(&a1, 300);
	cout << a1.getA() << endl;
	
	
	cout << "hello..." << endl;
	return;
}