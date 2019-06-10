#include <iostream>
using namespace std;

class A
{
private:
	int a;
protected:
	int b;
public:
	int c;

	A()
	{
		a = 0; b = 0; c = 0;
	}

	void set(int a, int b, int c)
	{
		this->a = a; this->b = b; this->c = c;
	}
};

class B : public A
{
public:
	void print()
	{
		//cout << "a=" << a;//err
		cout << "b=" << b;//ok
		cout << "c=" << endl;//ok
	}
};

class C : protected A
{
public:
	void print()
	{
		//cout << "a=" << a;//err
		cout << "b=" << b;//ok
		cout << "c=" << endl;//包含的，在子类的内部能被使用 //ok
	}
};

class D : private A
{
public:
	void print()
	{
		//cout << "a=" << a;//err
		cout << "b=" << b;//看这句话写在了D类的内部
		cout << "c=" <<c<< endl;//ok
	}
};

int main()
{
	A aa;
	B bb;
	C cc;
	D dd;

	aa.c = 100;//ok
	bb.c = 100;//ok
	//cc.c = 100;//err 保护的
	//dd.c = 100;//err

	aa.set(1, 2, 3);//ok
	bb.set(10, 20, 30);//ok
	//cc.set(40, 50, 60);//err 保护的
	//dd.set(70, 80, 90);//err

	bb.print();//ok
	cc.print();//ok
	dd.print();//ok

	return 0;
}