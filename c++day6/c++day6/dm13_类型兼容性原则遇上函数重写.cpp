#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
		cout << "Parent a" << a << endl;
	}

	virtual void print()//子类和父类的函数名一样
	{
		cout << "Parent 打印a" << a << endl;
	}
protected:
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b) : Parent(10)
	{
		this->b = b;
		cout << "Child b" << b << endl;
	}

	void print()//virtual void print(); 父类写了virtual,子类可写可不写，但一般都写
	{
		cout << "Child 打印b" << b << endl;
	}
protected:
private:
	int b;
};

void howToPrint(Parent *base)
{
	base->print(); //一种调用语句 有多种表现形态
}

void howToPrint2(Parent &base)
{
	base.print();
}

void main()
{
	Parent *base = NULL;
	Parent p1(20);
	Child c1(30);

	base = &p1;
	base->print();//执行父类的打印函数

	base = &c1;
	base->print();//还是在执行父类的打印函数  那就要提出面向对象新需求 
				  //编译器做法不是我们想要的：1.根据实际的对象类型来判断重名函数的调用
				  //2.若父类指针指向的是父类对象则调用父类中定义的函数
				  //3.如果父类指针指向的是子类对象则调用子类定义的重名函数
				  //那就需要多态来解决。使用virtual关键字来实现
	{
		Parent &base2 = p1;
		base2.print();

		Parent &base3 = c1;//base3是c1的别名。但还是打印父类的打印函数。加virtual之后就会打印子类的打印函数
		base3.print();
	}

	//函数调用
	howToPrint(&p1);
	howToPrint(&c1);//仍然是打印父类的打印函数 加virtual之后就会打印子类的打印函数

	howToPrint2(p1);
	howToPrint2(c1);//仍然是打印父类的打印函数 加virtual之后就会打印子类的打印函数

	cout << "hello..." << endl;
	return;
}