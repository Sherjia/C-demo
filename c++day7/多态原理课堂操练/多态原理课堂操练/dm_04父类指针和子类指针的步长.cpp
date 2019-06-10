#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		//print();
	}
	virtual void print()
	{
		cout << "我是爹" << endl;
	}
private:
	int a;
};

//成功，一次偶然的成功，比必然的失败更可怕:如果在Child中加入变量b，那么程序就会在65行宕机
//因为子类新添加了一个成员属性b，所以步长不一致了。指针是一种数据类型，它的步长和它的数据类型有关。
//结论：多态是用父类指针指向子类对象 和 父类步长++，是两个不同的概念
class Child : public Parent
{
public:
	
	/*
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
		print();
	}
	*/
	Child(int b = 0) :Parent(0)
	{
		//this->b = b;
	}
	virtual void print()
	{
		cout << "我是儿子" << endl;
	}
private:
	//int b;
};

void HowToPlay(Parent *base)
{
	base->print();
}

void main()
{
	Child c1;//
	//c1.print();
	Child  *pC = NULL;
	Parent *pP = NULL;

	Child array[] = { Child(1), Child(2), Child(3) };
	
	pP = array;
	pC = array;
	pP->print();
	pC->print();//多态发生

	pP++;
	pC++;
	pP->print();
	pC->print();//多态发生

	pP++;
	pC++;
	pP->print();
	pC->print();//多态发生


	cout << "hello..." << endl;
	return;
}