#include <iostream>
using namespace std;

//public修饰的成员变量，在类的外部和内部都可以使用
//private修饰的成员变量，只能在类的内部使用
//protected修饰的成员变量,在类的内部使用，在继承的子类中可用；是为了在家族中使用，是为了继承
//派生类访问控制理结论
//1.protected修饰的成员变量,在类的内部使用，在继承的子类中可用；是为了在家族中使用，是为了继承
//2.项目开发中 一般情况下 是public
class Parent
{
public:
	int a;
protected:
	int b;
private:
	int c;
public:
	void printT()
	{
		cout << "printT" << endl;
	}
};

/*
c++中的继承方式（public，protected，private）会影响子类的对外访问属性
	判断某一句话，能否被访问到
	1.看调用语句，这句话写在子类的内部、外部
	2.看子类如何从父类继承（public，protected，private）
	3.看父类的访问级别（public，protected，private）
*/

class Child : public Parent
{
public:
	void uesVar()
	{
		a = b = 0;
		//c = 0;//无论何种继承，父类私有属性都无法访问，错误
	}
protected:
private:
};

//public继承
void main21()
{
	Parent t1, t2;
	t1.a = 10;//
	//t1.b = 20;//错误,在父类中是保护的，无法在外部访问
	//t2.c = 30;//无论何种继承，父类私有属性都无法访问，错误

	cout << "hello..." << endl;
	return;
}
//private继承
class Child2 : private Parent
{
public:
	void uesVar()
	{
		//a = b = 0;在子类中变为private成员
		//c = 0;//无论何种继承，父类私有属性都无法访问，错误
	}
protected:
private:
};

void main22()
{
	Child2 c1,c2,c3;
	//c1.a = 10;//错误,在子类中变私有，且写在子类外部，不能访问
	//c2.b = 10;//错误，在子类中变私有，且写在子类外部，不能访问
	//c3.b = 30;//错误，本身就为父类的私有

	cout << "hello..." << endl;
	return;
}
//protected继承
class Child3 : protected Parent
{
public:
	void uesVar()
	{
		a = b = 0;//在子类都变为protected成员，只能在子类的内部访问
		//c = 0;//无论何种继承，父类私有属性都无法访问，错误
	}
protected:
private:
};
void main()
{
	Child3 c3;
	//c3.a = 10;//在子类都变为protected成员，只能在子类的内部访问，错误
	//c3.b = 20;//在子类都变为protected成员，只能在子类的内部访问，错误
	//c3.c = 30;//错误，本身就为父类的私有

	cout << "hello..." << endl;
	return;
}
