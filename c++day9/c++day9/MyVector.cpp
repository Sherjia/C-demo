#include <iostream>
using namespace std;
#include "MyVector.h"


//MyVetcor<int> myv1(10);
template <typename T>
MyVetcor<T>::MyVetcor(int size)//构造函数
{
	m_space = new T[size];
	m_len = size;
}

template <typename T>
ostream& operator<< (ostream& out, const MyVetcor<T> &obj)
{
	for (int i = 0; i <obj.m_len; i++)
	{
		out << obj.m_space[i] << " ";
	}
	out << endl;
	return out;
}

//MyVetcor<int> myv2 = myv1;
template <typename T> 
MyVetcor<T>::MyVetcor(const MyVector<T> &obj)//拷贝构造函数
{
	//根据myv的大小分配内存
	m_len = obj.m_len;
	m_space = new T[m_len];
	
	//copy数据
	for(int i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}
}

template <typename T>
MyVetcor<T>::~MyVetcor()//析构函数
{
	if (m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;//为了防止出现野指针
		m_len = 0;
	}
}

template <typename T>
T& MyVetcor<T>::operator[](int index)//a1.operator[i]函数返回值当左值，需要返回一个引用(元素本身，而不是一个值)，并要支持链式编程
{
	return m_space[index];
}

//a3 = a2 = a1;
template <typename T>
MyVector<T>& MyVetcor<T>::operator=(const MyVetcor<T> obj)//函数返回值当左值，需要返回一个引用(元素本身，而不是一个值)，并要支持链式编程
{
	//先把a2旧的内存释放掉
	if (m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}

	//根据a1分配内存
	m_len = obj.m_len;
	m_space = new T[m_len];

	//拷贝数据
	for (int i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}

	return *this;//a2 = a1,返回a2的自身
}