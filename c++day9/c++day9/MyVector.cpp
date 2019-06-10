#include <iostream>
using namespace std;
#include "MyVector.h"


//MyVetcor<int> myv1(10);
template <typename T>
MyVetcor<T>::MyVetcor(int size)//���캯��
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
MyVetcor<T>::MyVetcor(const MyVector<T> &obj)//�������캯��
{
	//����myv�Ĵ�С�����ڴ�
	m_len = obj.m_len;
	m_space = new T[m_len];
	
	//copy����
	for(int i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}
}

template <typename T>
MyVetcor<T>::~MyVetcor()//��������
{
	if (m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;//Ϊ�˷�ֹ����Ұָ��
		m_len = 0;
	}
}

template <typename T>
T& MyVetcor<T>::operator[](int index)//a1.operator[i]��������ֵ����ֵ����Ҫ����һ������(Ԫ�ر���������һ��ֵ)����Ҫ֧����ʽ���
{
	return m_space[index];
}

//a3 = a2 = a1;
template <typename T>
MyVector<T>& MyVetcor<T>::operator=(const MyVetcor<T> obj)//��������ֵ����ֵ����Ҫ����һ������(Ԫ�ر���������һ��ֵ)����Ҫ֧����ʽ���
{
	//�Ȱ�a2�ɵ��ڴ��ͷŵ�
	if (m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}

	//����a1�����ڴ�
	m_len = obj.m_len;
	m_space = new T[m_len];

	//��������
	for (int i = 0; i < m_len; i++)
	{
		m_space[i] = obj.m_space[i];
	}

	return *this;//a2 = a1,����a2������
}