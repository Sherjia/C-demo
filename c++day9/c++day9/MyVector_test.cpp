/*
这个案例完全按照视频敲击出来的，但编译时一直有错，目前无法看出来具体错误；但整个思想和逻辑是正确的，完全可以按照这个看。
2019/3/15
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//1.容器内储存的元素必须能够被拷贝(必须提供拷贝构造函数)
#include "MyVector.cpp"

//1.优化Teacher类， 属性变成 char *panme，购置函数里面 分配内存
//2.优化Teacher类，析构函数 释放panme指向的内存空间
//3.优化Teacher类，避免浅拷贝 重载= 重写拷贝构造函数
//4.优化Teacher类， 在Teacher类中增加<<
//5.在模板数组中，存 int char Teacher Teacher*(指针类型)

//=====>stl 容器概念


class Teacher
{
public:
	Teacher()
	{
		age = 33;
		m_p = new char[1];
		strcpy(m_p, "");
	}
	Teacher(char *name, int age)
	{
		this->age = age;
		m_p = new char[strlen(name) + 1];
		strcpy(m_p, name);
	}
	Teacher(const Teacher& obj)
	{
		m_p = new char[strlen(obj.m_p) + 1];
		strcpy(m_p, obj.m_p);
		age = obj.age;
	}
	~Teacher()
	{
		if (m_p != NULL)
		{
			delete m_p;
			m_p = NULL;
		}
	}
	void printT()
	{
		cout << m_p << "，" << age << endl;
	}

	//重载<<
	friend ostream& operator<<(ostream& out, Teacher &t);
	//重载=
	Teacher& operator=(const Teacher &obj)
	{
		//1.判断原来的空间内存是否释放
		if (m_p != NULL)
		{
			delete[] m_p;
			m_p = NULL;
			age = 33;
		}
		//2.根据obj分配新的内存空间
		m_p = new char[strlen(obj.m_p) + 1];
		age = obj.age;
		//3.拷贝数据
		strcpy(m_p, obj.m_p);
		
		return *this;
	}
protected:
private:
	int age;
	//char name[32];
	char *m_p;
};
//重载<<
ostream& operator<<(ostream& out, Teacher &t)
{
	out << t.age << ", " << t.m_p << endl;
	return out;
}
void main()
{
	Teacher t1("t1", 31), t2("t2", 32), t3("t3", 33), t4("t4", 34);

	MyVetcor<Teacher*> tArray[4];

	tArray[0] = &t1;
	tArray[1] = &t2;
	tArray[2] = &t3;
	tArray[3] = &t4;

	for (int i = 0; i < 4; i++)
	{
		Teacher *tmp = tArray[i];
		tmp->printT();
	}

}

void main03()
{
	Teacher t1("t1", 31), t2("t2", 32), t3("t3", 33), t4("t4", 34);
	
	MyVetcor<Teacher> tArray[4];

	tArray[0] = t1;
	tArray[1] = t2;
	tArray[2] = t3;
	tArray[3] = t4;

	for (int i = 0; i < 4; i++)
	{
		Teacher tmp = tArray[i];
		tmp.printT();
	}

}


void main02()
{
	MyVetcor<char> myv1(10);
	myv1[0] = 'a';
	myv1[1] = 'b';
	myv1[2] = 'c';
	myv1[3] = 'd';

	cout << myv1;
}

void main01()
{
	MyVetcor<int> myv1(10);

	for (int i = 0; i < myv1.getLen(); i++)
	{
		myv1[i] = i + 1;
		cout << myv1[i] << " ";
	}
	cout << endl;

	MyVetcor<int> myv2 = myv1;
	
	for (int i = 0; i < myv2.getLen(); i++)
	{
		myv1[i] = i + 1;
		cout << myv2[i] << " ";
	}
	cout << myv2 << endl;
	ostream& operator<<(ostream& out, const MyVetcor<int> &obj);



	cout << "hello..." << endl;
	return;
}