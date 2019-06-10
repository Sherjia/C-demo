#pragma once
#include <iostream>
using namespace std;
#include "dm_09complex.h"


//���캯��д��������ⲿ
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

//��Ա���� ʵ��+���������
template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c2)//ע���ʱ�����ķ���ֵ��Ҫ<T>����Ϊ���ص���һ��Ԫ�أ������Ĳ���Ҳ��Ҫ<T>
{
	Complex tmp(a + c2.a, b + c2.b);//Complex<T> tmp(a + c2.a, b + c2.b);����Ĳ������б�<T>���Բ��ӣ���Ϊ�����Ѿ�����
	return tmp;
}

//��Ա���� ʵ��-���������
template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c2)
{
	Complex tmp(a - c2.a, b - c2.b); //Complex tmp(this->a - c2.a, this->b - c2.b);
	return tmp;
}

//��Ԫ���� ʵ��<<���������
template <typename T>
ostream& operator<<(ostream& out, Complex<T>& c3)
{
	out << c3.a << " + " << c3.b << "i" << endl;
	return out;
}

/*
////////////////////////////////////////////////////////////////////
//������Ԫ���� �ᱨ��
//��������н�ͼ ����5��9���Լ�14�е�д�������ǲ�����������������Ԫ����������
template <typename T>
Complex<T> MySub(Complex<T> &c1, Complex<T> &c2)//������Ԫ����
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
*///���ۣ���Ҫ������Ԫ����