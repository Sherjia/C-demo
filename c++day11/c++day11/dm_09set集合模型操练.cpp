#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "set"
#include "functional"

//set是集合 元素唯一 自动排序(默认情况下是从小到大) 不能按照[]方式插入元素
//红黑树
void main91()
{
	set<int> set1;

	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();//随机产生一个数插入
		set1.insert(tmp);
	}

	//插入元素，重复的。但其实只会插入一个100，因为set元素是唯一的
	set1.insert(100);
	set1.insert(100);
	set1.insert(100);

	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}

	//删除集合
	while (!set1.empty())
	{
		set<int>::iterator it = set1.begin();
		cout << *it << " ";
		set1.erase(set1.begin());
	}

	//
}

//基本的数据类型set可以自动排序
void main92()
{
	set<int> set1; //set<int, less<int>> set1 默认自动排序从大到小
	set<int, greater<int>> set2;//从大到小

	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();//随机产生一个数插入
		set2.insert(tmp);
	}

	//从大到小
	for (set<int, greater<int>>::iterator it = set2.begin(); it != set2.end(); it++)
	{
		cout << *it << " ";
	}
}

//对于复杂数据类型
class Student
{
public:
	Student(char* name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}

	char name[64];
	int age;
};

//仿函数 先抛砖，后面会详细讲
struct FuncStuendt
{
	bool operator()(const Student &left, const Student &right)
	{
		if (left.age < right.age)//如果的小，就返回真，就是按照年龄升序排列
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


void main93()
{
	Student s1("S1", 31);
	Student s2("S2", 22);
	Student s3("S3", 44);
	Student s4("S4", 36);

	set<Student, FuncStuendt> set1;
	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);

	//遍历
	for (set<Student, FuncStuendt>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << it->age << "\t" << it->name << endl;
	}

	
}

//typedef pair<iterator, bool>_Pairib;
//如何判断 sett1.insert函数的返回值
void main94()
{
	Student s1("S1", 36);
	Student s2("S2", 22);
	Student s3("S3", 44);
	Student s4("S4", 35);
	Student s5("S5", 36);//如果有两个36岁 插入其实是不成功的

	set<Student, FuncStuendt> set1;
	//如何知道插入的结果
	pair<set<Student, FuncStuendt>::iterator, bool> pair1 = set1.insert(s1);
	if (pair1.second == true)
	{
		cout << "插入s1成功" << endl;
	}
	else
	{
		cout << "插入s1失败" << endl;
	}
	set1.insert(s2);
	pair<set<Student, FuncStuendt>::iterator, bool> pair5= set1.insert(s5);
	if (pair5.second == true)
	{
		cout << "插入s5成功" << endl;
	}
	else
	{
		cout << "插入s5失败" << endl;
	}
	

	//遍历
	for (set<Student, FuncStuendt>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << it->age << "\t" << it->name << endl;
	}
}

//find equal_range 
//返回结果是一个pair
void main95()
{
	set<int> set1; 

	for (int i = 0; i < 10; i++)
	{
		set1.insert(i + 1);
	}

	//从大到小
	for (set<int, greater<int>>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int>::iterator it0 = set1.find(5);
	cout << "it0: " << *it0 << endl;

	int num1 = set1.count(5);
	cout << "num1:" << num1 << endl;

	set<int>::iterator it1 = set1.lower_bound(5);//返回第一个大于等于5的元素的迭代器的位置
	cout << "it1: " << *it1<< endl;//5

	set<int>::iterator it2 = set1.upper_bound(5);//返回第一个大于5的迭代器位置
	cout << "it2: " << *it2 << endl;//6
	//把5元素删除掉
	set1.erase(5);
	//equal_range函数用于在序列中表示一个数值的第一次出现与最后一次出现的后一位。得到相等元素的子范围
	pair<set<int>::iterator, set<int>::iterator> mypair = set1.equal_range(5);
	set<int>::iterator it3 = mypair.first;
	cout << "it3: " << *it3 << endl;//5 //把5元素删除掉 6

	set<int>::iterator it4 = mypair.second;
	cout << "it4: " << *it4 << endl;//6  //把5元素删除掉 6
}


void main()
{
	//main91();
	//main92();
	//main93();
	//main94();
	main95();

	cout << "hello..." << endl;
	return;
}