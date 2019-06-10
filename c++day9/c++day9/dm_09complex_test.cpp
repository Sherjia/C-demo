#include <iostream>
using namespace std;
#include "dm_09complex.cpp"//有类模板和函数模板的就要写这个头文件。因为类模板的机制就是二次编译



void main()
{

	//需要把模板类具体化以后，才能定义对象， c++编译器需要分配内存
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;
	//Complex operator+(Complex &c2);成员函数实现+号运算符重载

	cout << c3 << endl;
	//ostream& operator<<(ostream& out, Complex& c3);<<只能用全局函数实现重载，并且还要设定为类的友元函数

	/*
	//滥用友元函数
	{
		Complex<int> c4 = MySub(c1, c2);
		cout << c4 << endl;
	}
	*/

	cout << "hello..." << endl;
	return;
}