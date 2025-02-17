#include"MyArray.h"


Array::Array(int length)
{
	if (length < 0)
	{
		length = 0;
	}
	m_length = length;
	m_space = new int[m_length];
}
//Array a2 = a1;a1初始化a2，要深拷贝
Array::Array(const Array& obj)
{
	this->m_length = obj.m_length;//this是a2,obj是a1
	this->m_space = new int[this->m_length];//分配内存空间

	for (int i = 0; i <m_length; i++)//数组元素复制
	{
		this->m_space[i] = obj.m_space[i];
	}
}
Array::~Array()
{
	if (m_space != NULL)
	{
		delete[] m_space;
		m_length = 0;
	}
}

//a1.setData(i, i);
void Array::setData(int index, int value)
{
	m_space[index] = value;
}
int Array::getData(int index)
{
	return m_space[index];
}
int Array::length()
{
	return m_length;
}
//重载[]
int& Array::operator[](int i)
{
	return m_space[i];
}
//a3 = a1
Array& Array::operator=(Array &a1)
{
	//1.释放旧的内存
	if (this->m_space != NULL)
	{
		delete[] m_space;
		m_length = 0;
	}
	//2.根据a1大小，分配内存
	m_length = a1.m_length;
	m_space = a1.m_space;
	//3.拷贝数据
	for (int i = 0; i < m_length; i++)
	{
		//m_space[i] = a1.m_space[i];
		m_space[i] = a1[i];
	}
	return *this;
}
//if (a3 == a1) 只需判断两个数组的长度和每个元素是否相等即可
bool Array::operator==(Array &a1)
{
	if (this->m_length != a1.m_length)
	{
		return false;
	}

	for (int i = 0; i < m_length; i++)
	{
		if (this->m_space[i] != a1[i])
		{
			return false;
		}
	}
	return true;
}

bool Array::operator!=(Array &a1)
{
	/*
	if (*this == a1)
	{
		return false;
	}
	else
	{
		return ture;
	}
	*/
	return !(*this == a1);
	
}