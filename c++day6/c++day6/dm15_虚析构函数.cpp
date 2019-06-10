#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		p = new char[20];
		strcpy(p, "obja");
		printf("A()\n");
	}
	virtual ~A()//虚析构函数
	{
		delete []p;
		printf("~A()\n");
	}
protected:
private:
	char *p;
};

class B : public A
{
public:
	B()
	{
		p = new char[20];
		strcpy(p, "objb");
		printf("B()\n");
	}
	virtual ~B()//虚析构函数
	{
		delete []p;
		printf("~B()\n");
	}
protected:
private:
	char *p;
};

class C : public B
{
public:
	C()
	{
		p = new char[20];
		strcpy(p, "objc");
		printf("C()\n");
	}
	~C()
	{
		delete []p;
		printf("~C()\n");
	}
protected:
private:
	char *p;
};

//这个场景之下只执行了 父类的析构函数，会发生内存泄漏；
//想通过父类指针把所有子类对象的析构函数都执行一遍
//就是想通过父类指针释放所有的子类资源 就要使用虚析构函数（在父类也就是老祖宗类的析构函数前加上virtual关键字）
void howtodelete(A *base)
{
	delete base;//若不使用虚析构函数这句话不会表现成多态这种属性
}

void main()
{
	C *myC = new C;//new delete匹配
	howtodelete(myC);//new了一个子类，把子类扔给父类指针，这是类型兼容性原则里的，不会报错

	cout << "hello..." << endl;
	return;
}
