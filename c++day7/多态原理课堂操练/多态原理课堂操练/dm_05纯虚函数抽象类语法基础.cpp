#include <iostream>
using namespace std;

//面向抽象类编程（面向一套预先定义好的接口编程）
//解耦合....模块的划分

class Figure //抽象类 有纯虚函数的类就叫抽象类
{
public:
	//约定一个统一的界面（接口），让子类必须去实现
	virtual void getArea() = 0; //纯虚函数
protected:
private:
};

class Circle : public Figure
{
public:
	Circle(int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "圆形的面积:" << 3.14*a*a << endl;
	}
protected:
private:
	int a;
	int b;
};

class Tri : public Figure
{
public:
	Tri(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "三角形的面积:" << a*b/2 << endl;
	}
private:
	int a;
	int b;
};

void objplay(Figure *base)
{
	base->getArea(); //会发生多态
}

class Square : public Figure
{
public:
	Square(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "四边形的面积:" << a*b << endl;
	}
protected:
private:
	int a;
	int b;
};

void main()
{
	//Figure f; //错误，抽象类不能被实例化

	Figure *base = NULL;//

	Circle c1(10, 20);
	Tri t1(20, 30);
	Square s1(50, 60);

	//面向抽象类编程（面向一套预先定义好的接口编程）

	objplay(&c1);
	objplay(&t1);
	objplay(&s1);

	//c1.getArea();

	cout << "hello..." << endl;
	return;
}