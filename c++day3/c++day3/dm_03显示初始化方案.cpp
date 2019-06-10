#include <iostream>
using namespace std;

class Test3
{
public:
	void init(int _a, int _b)
	{
		a = _a;
		b = _b;
	}

protected:
private:
	int a;
	int b;	
};


void main()
{
	Test3 t1;//类没有提供构造函数，编译器会自动提供一个默认的构造函数
			 //若没有提供拷贝构造函数，编译器也会提供一个默认的

	int a = 10, b = 5;
	t1.init(a, b);//显示的初始化方案，显得很蹩脚
	
	cout << "hello..." << endl;
	return;
}