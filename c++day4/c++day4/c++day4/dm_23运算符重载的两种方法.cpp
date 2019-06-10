#include <iostream>
using namespace std;

class Complex
{	
public:
	//全局函数重载+号运算符
	friend Complex operator+(Complex &c1, Complex &c2);
	//全局函数重载前置++
	friend Complex operator++(Complex &c1);
	//全局函数重载后置++
	friend Complex operator++(Complex &c1, int);
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << " + " << b << " i " << endl;
	}
	//成员函数方法 实现-号运算符重载
	Complex operator-(Complex &c2)
	{
		Complex tmp(this->a-c2.a, this->b-c2.b);
		return tmp;
	}
	//前置--操作符，用成员函数实现
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}
	//后置--操作符，用成员函数实现
	Complex& operator--(int)//编译器要区分这是后置--，所以参数里需要一个占位符
	{
		Complex tmp = *this;////因为是后置++，先使用，再让自身++
		this->a--;
		this->b--;
		return tmp;
	}
protected:
private:
	int a;
	int b;
};

//全局函数法实现+号运算符重载
Complex operator+(Complex &c1, Complex &c2)
{
	Complex tmp(c1.a+c2.a, c1.b+c2.b);
	return tmp;
}

//全局函数法实现 前置++运算符重载
Complex operator++(Complex &c1)
{
	c1.a++;
	c1.b++;
	return c1;
}
//全局函数法实现 后置++运算符重载
Complex operator++(Complex &c1, int)
{
	//因为是后置++，先使用，再让c1++
	Complex tmp = c1;
	c1.a++;
	c1.b++;
	return tmp;

}

/*
全局函数、类成员函数方法实现运算符重载步骤
1.要承认运算符重载是一个函数，写出函数名称
2.根据操作数，写出函数参数
3.根据业务，完善函数返回值（看函数是返回引用、还是指针 元素），及实现函数业务

*/
void main()
{
	Complex c1(1, 2), c2(3, 4);
	
	//全局函数法实现+号运算符重载
	//Complex operator+(Complex &c1, Complex &c2);
	Complex c3 = c1 + c2;
	c3.printCom();

	
	//成员函数方法 实现-号运算符重载
	//c1.operator-(c2);
	//Complex operator-(Complex &c2)
	Complex c4 = c1 - c2;
	c4.printCom();

	
	//前置++操作符 用全局函数实现
	//Complex operator++(Complex &c1)
	++c1;
	c1.printCom();

	
	//前置--操作符，用成员函数实现
	//Complex& operator--()
	--c1;
	c1.printCom();

	
	//后置++操作符，用全局函数实现
	//Complex operator++(Complex &c1, int),编译器要区分这是后置--，所以参数里需要一个占位符
	c1++;
	c1.printCom();

	
	//成员函数的方法，后置--实现
	c1--;
	c1.printCom();
	

	cout << "hello..." << endl;
	return;
}