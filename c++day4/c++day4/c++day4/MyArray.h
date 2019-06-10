#pragma once

#include <iostream>
using namespace std;

class Array
{
public:
	Array(int length);
	Array(const Array& obj);
	~Array();
public:
	void setData(int index, int value);
	int getData(int index);
	int length();
	//����[] ��������ֵ����ֵ����Ҫ����һ������(Ԫ�ر���������һ��ֵ)������Ҫ֧����ʽ��� 
	int& operator[](int i);
	//����=
	Array& operator=(Array &a1);
	//����==
	bool operator==(Array &a1);
	//����!=
	bool operator!=(Array &a1);

protected:
private:
	int m_length;
	int *m_space;
};