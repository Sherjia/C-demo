# include <iostream>

using namespace std;

//求圆的面积
//1.把属性和方法进行封装
//2.对属性和方法进行访问控制
//3.类的内部和外部
//4.类的访问关键字
//public : 修饰的成员函数变量和函数，可以在类的内部和类的外部访问
//private: .....................,只能在内部访问
//protected:....................,只能在内部访问，用在继承

class MyCircle
{
public:
	double m_r;//属性 成员变量
	double m_s;

public:
	double getR()//成员函数
	{
		return m_r;
	}
	void setR(double r)
	{
		m_r = r;

	}
	double getS()
	{
		m_s = 3.14*m_r*m_r;
		return m_s;
	}

protected:
private:
};

//类封装了成员变量和成员函数 //可以调用类的成员函数
void printCircle01(MyCircle *pC)
{
	cout << "r" << pC->getR()<< endl;
	cout << "s" << pC->getS()<< endl;
}
void printCircle02(MyCircle &myc)
{
	cout << "r" << myc.getR() << endl;
	cout << "s" << myc.getS() << endl;
}

void main01()//类的封装第一层含义
{
	
	MyCircle c1, c2;
	c1.setR(10);
	cout << "c1 s:" << c1.getS() << endl;
	
	c1.setR(11);
	printCircle01(&c1);
	
	c2.setR(20);
	printCircle01(&c2);

	c2.setR(15);
	printCircle02(c2);
	
	
	
	cout << "hello" << endl;

}

class MyAdvCircle
{

//double m_r默认没有权限修饰的成员函数是私有的 
private://相当密码，不能外部访问
	double m_r;//属性 成员变量
	double m_s;

public:
	double getR()//成员函数
	{
		return m_r;
	}
	void setR(double r)
	{
		m_r = r;

	}
	double getS()
	{
		m_s = 3.14*m_r*m_r;
		return m_s;
	}
};

void main02()
{
	MyAdvCircle c1, c2;
	//c1.m_r = 10;
	c1.setR(10);
}
/*
struct AAA
{
	int a;//struct定义的类。不写，默认是public
public:
private:
protected:
}; 

*/