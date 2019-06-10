#pragma once
#include <iostream>
using namespace std;
#include "dm_09complex.h"


//构造函数写在了类的外部
template <typename T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

template <typename T>
void Complex<T>::printCom()
{
	cout << "a" << a << " b" << b << endl;
}

//成员函数 实现+运算符重载
template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c2)//注意此时函数的返回值需要<T>，因为返回的是一个元素；函数的参数也需要<T>
{
	Complex tmp(a + c2.a, b + c2.b);//Complex<T> tmp(a + c2.a, b + c2.b);里面的参数化列表<T>可以不加，因为外面已经加了
	return tmp;
}

//成员函数 实现-运算符重载
template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c2)
{
	Complex tmp(a - c2.a, b - c2.b); //Complex tmp(this->a - c2.a, this->b - c2.b);
	return tmp;
}

//友元函数 实现<<运算符重载
template <typename T>
ostream& operator<<(ostream& out, Complex<T>& c3)
{
	out << c3.a << " + " << c3.b << "i" << endl;
	return out;
}

/*
////////////////////////////////////////////////////////////////////
//滥用友元函数 会报错
//解决方法有截图 就是5—9行以及14行的写法；但是并不会解决所有滥用友元函数的问题
template <typename T>
Complex<T> MySub(Complex<T> &c1, Complex<T> &c2)//滥用友元函数
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
*///结论：不要滥用友元函数