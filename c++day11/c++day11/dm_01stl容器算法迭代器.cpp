#include <iostream>
using namespace std;

#include "vector"
#include "algorithm"

//容器装基础数据类型
void main11()
{
	vector<int> v1;//容器：把你的元素拷贝到容器中
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(-1);

	//迭代器相当于一个指针
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}

	//算法 算法和迭代器进行无缝连接
	int num1 = count(v1.begin(), v1.end(), 3);//查找3的个数 count
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

//容器中装元素
void main12()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	vector<Teacher> v1;//容器：把你的元素拷贝到容器中 实现了算法和数据类型的有效分离
	v1.push_back(t1);
	v1.push_back(t2);
	v1.push_back(t3);

	//迭代器相当于一个指针
	for (vector<Teacher>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << it->age << " ";
	}

	//抛转：如何求 容器中 老师结点的 年龄=33的个数

	return;
}

//容器中装指针
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

	vector<Teacher*> v1;//容器：把t1, t2, t3内存首地址 拷贝放入到了容器
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);

	//迭代器相当于一个指针
	for (vector<Teacher*>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << (*it)->age << endl;//it本来就是指针，p1也是指针，(*it)就是地址p1空间的值t1

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
