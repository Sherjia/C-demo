#include <iostream>
using namespace std;

#include "vector"
#include "algorithm"

//����װ������������
void main11()
{
	vector<int> v1;//�����������Ԫ�ؿ�����������
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(-1);

	//�������൱��һ��ָ��
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}

	//�㷨 �㷨�͵����������޷�����
	int num1 = count(v1.begin(), v1.end(), 3);//����3�ĸ��� count
	cout << "num1: " << num1 << endl;
	
	


	return;
}

class Teacher
{
public:
	int age;
	char name[64];
	void print()
	{
		cout << "age: " << age << endl;
	}
protected:
private:
};

//������װԪ��
void main12()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	vector<Teacher> v1;//�����������Ԫ�ؿ����������� ʵ�����㷨���������͵���Ч����
	v1.push_back(t1);
	v1.push_back(t2);
	v1.push_back(t3);

	//�������൱��һ��ָ��
	for (vector<Teacher>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << it->age << " ";
	}

	//��ת������� ������ ��ʦ���� ����=33�ĸ���

	return;
}

//������װָ��
void main13()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	
	Teacher *p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	vector<Teacher*> v1;//��������t1, t2, t3�ڴ��׵�ַ �������뵽������
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	//�������൱��һ��ָ��
	for (vector<Teacher*>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << (*it)->age << endl;//it��������ָ�룬p1Ҳ��ָ�룬(*it)���ǵ�ַp1�ռ��ֵt1

	}

	return;
}

void main()
{
	//main11();
	//main12();
	main13();

	cout << "hello..." << endl;
	return;
}
