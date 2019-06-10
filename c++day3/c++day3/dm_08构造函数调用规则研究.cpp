#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		a = 0;
		b = 0;
	}
	Test(int _a)
	{
		a = _a;
		b = 0;
	}
	Test(const Test& obj)
	{
		a = obj.a + 100;
		b = obj.b + 100;
	}
	void printT()
	{
		cout << "a:" << a << "b:" << b << endl;
	}
	
private:
	int a, b;
};

//当类中定义了拷贝构造函数时，编译器不会提供无参构造函数
//当类定义了一个有参构造函数时，编译器不会构造无参构造函数
//写了构造函数必须要用
void main()
{

	Test t1;//调用无参构造函数
	cout << "hello..." << endl;
	return;
}