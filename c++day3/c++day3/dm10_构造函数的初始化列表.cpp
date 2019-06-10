#include <iostream>
using namespace std;

class A
{
public:
	A(int _a)
	{
		a = _a;
		cout << "构造函数"<<"a:" << a << endl;
	}
	~A()
	{
		
		cout <<"析构函数"<< "a:" << a << endl;
	}
private:
	int a;
protected:
};

class B
{
public:
	B(int _b1, int _b2) :a1(1), a2(2), c(0)
	{

	}
	B(int _b1, int _b2, int m, int n) :a1(m), a2(n),c(0)//构造函数初始化列表 解决：在B类中 组合了一个A类对象（A设计了构造函数）
									 //据规则，写了A的构造，就要用；没有机会初始化A
									 //新的语法：Constructor::Constructor():m1(v1),m2(v1,v2),m3(v3)
									 //有const，就必须使用初始化列表来初始化 
	{
		b1 = _b1; b2 = _b2; cout << "B的构造函数" << endl;
	}
	~B()
	{
		cout << "B的析构函数" << endl;
	}
private:
	int b1, b2;
	A a1, a2;
	const int c;
protected:
};

void obj10play()
{

	//A a1(10);
	//B objB(1,2);

	//1.参数传递
	B objB2(1, 2, 3, 4);

	//2.调用顺序 首先先执行被组合对象的构造函数（若有多个，按照定义顺序，不是按照初始化列表顺序）
	//          析构函数：和构造函数的调用顺序相反
	return;
}

void main()
{
	obj10play();
	return;
}