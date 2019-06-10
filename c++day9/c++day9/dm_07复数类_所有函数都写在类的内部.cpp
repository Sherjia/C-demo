#include <iostream>
using namespace std;


template <typename T>
class Complex
{
	friend Complex MySub(Complex &c1, Complex &c2)//滥用友元函数
	{
		Complex tmp(c1.a - c2.a, c1.b - c2.b);
		return tmp;
	}
	friend ostream& operator<<(ostream& out, Complex& c3)//变为友元函数，因为做<<运算符重载时，要访问Complex类的私有属性：a,b
	{
		out <<c3.a << " + " << c3.b <<"i"<< endl;
		return out;
	}
public:
	Complex(T a, T b)
	{
		this->a = a;
		this->b = b;
	}
	Complex operator+(Complex &c2)
	{
		Complex tmp(a + c2.a, b + c2.b);
		return tmp;
	}
	void printCom()
	{
		cout << "a" << a << " b" << b << endl;
	}
protected:
private:
	T a;
	T b;
};
//运算符重载的正规写法
//重载<<和>>只能用友元函数，其他运算符重载，都要写为成员函数,不要滥用友元函数
/*
ostream& operator<<(ostream& out, Complex& c3)
{
	out << "a: " << c3.a << " b:" << c3.b << endl;
	return out;
}
*/
void main()
{
	//需要把模板类具体化以后，才能定义对象， c++编译器需要分配内存
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;
	//Complex operator+(Complex &c2);成员函数实现+号运算符重载

	cout << c3 << endl;
	//ostream& operator<<(ostream& out, Complex& c3);<<只能用全局函数实现重载，并且还要设定为类的友元函数

	//滥用友元函数
	{
		Complex<int> c4 = MySub(c1, c2);
		cout << c4 << endl;
	}

	cout << "hello..." << endl;
	return;
}