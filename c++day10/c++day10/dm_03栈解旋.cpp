#include <iostream>
using namespace std;

//异常被抛出后，从进入到try起，到异常被catch前，这期间在栈上的构造的所有对象，都会被自动析构。析构和构造的顺序相反，这一过程就栈解旋
class Test3
{
public:
	Test3(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
		cout << "构造函数do\n";
	}
	~Test3()
	{
		cout << "析构函数do\n";
	}
protected:
private:
	int a = 0;
	int b = 0;
};

void myDivide()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDivide要发生异常了\n";
	throw 1;//此时throw这句一被执行，t1,t2就被自动调用的析构函数给析构了 
}

/*
//只能抛出所列类型的异常
void myDivide1() throw (int, char, char *)
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDivide要发生异常了\n";
	throw 1;
}
*/

//不写，可以抛出任何类型
void myDivide1()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDivide要发生异常了\n";
	throw 1;
}

/*
//不抛出
void myDivide1() throw ()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDivide要发生异常了\n";
	throw 1;
}
*/

void main()
{
	try
	{
		myDivide();
	}
	catch (int a)
	{
		cout << "int类型异常了\n";
	}
	catch (...)
	{
		cout << "未知类型异常了\n";
	}
}