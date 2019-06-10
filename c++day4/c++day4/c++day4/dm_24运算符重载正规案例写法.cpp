#include <iostream>
using namespace std;

class Complex
{
public:
	//friend void operator<<(ostream &cout, Complex &c1);//友元函数
	friend ostream& operator<<(ostream &out, Complex &c1);
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << " + " << b << " i " << endl;
	}
	//实现+号运算符重载
	Complex operator+(Complex &c2)
	{
		Complex tmp(this->a+ c2.a, this->b+ c2.b);
		return tmp;
	}

	//成员函数法实现 前置++运算符重载
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}
	//成员函数法实现 后置++运算符重载
	Complex& operator++(int)
	{
		//因为是后置++，先使用，再让c1++
		Complex tmp = *this;
		this->a++;
		this->b++;
		return tmp;

	}
	//成员函数方法 实现-号运算符重载
	Complex operator-(Complex &c2)
	{
		Complex tmp(this->a - c2.a, this->b - c2.b);
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

/*
void operator<<(ostream &out, Complex &c1)
{
	out << c1.a << " + " << c1.b << " i "<<endl;
}
*/
//可以连续输出，链式编程支持
ostream& operator<<(ostream &out, Complex &c1)
{
	out << c1.a << " + " << c1.b << " i " << endl;
	return out;
}

void main01()
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

void main()
{
	int a = 10;
	Complex c1(1, 2), c2(3, 4);
	cout << a << endl;//按照数据类型来判断
	
	
	//1.void operator<<(ostream &out, Complex &c1);友元函数实现左移操作符的重载
	cout << c1;
	//2.ostream 类中 添加成员函数 .operator<<
	//cout.operator<<(c1);这种方法实现不了，因为没有ostream类的源代码

	

	//2.函数返回值当左值，需要返回一个引用
	cout << c1 << "aaaddd";//左移操作符的调用顺序，是从左至右


}