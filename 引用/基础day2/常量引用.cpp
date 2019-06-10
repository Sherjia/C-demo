#include <iostream>
using namespace std;

//常引用的知识架构 
void main301()
{
	//普通引用

	int a = 10;
	int &b = a;
	printf("b:%d \n", b);

	//常引用
	int x = 20;
	const int &y = x; //常引用 是 让变量 引用只读属性 不能通过y去修改x了

	//常引用 初始化 分为2种情况
	//1.用变量 初始化 常引用
	{
		int x1 = 20;
		const int &y = x1;
	}
	//2. 字面量 初始化 常量引用
	{
		const int a = 40; //c++编译器把a放在符号表中
		//int &m = 41; //这句话不通过,因为调用字面量不分配内存
		const int &m = 41;//会分配内存。因为引用的本质就是给内存取别名。
	}

	cout << "hello..." << endl;
	return;
}
struct Teacher
{
	char name[64];
	int age;
};


void printTeacher(const Teacher &myt)
{
	//常引用 让 实参变量 拥有只读属性
	printf("myt.age:%d \n", myt.age);
}

void main()
{
	Teacher t1;
	t1.age = 36;

	printTeacher(t1);


	cout << "hello..." << endl;
	return;
}