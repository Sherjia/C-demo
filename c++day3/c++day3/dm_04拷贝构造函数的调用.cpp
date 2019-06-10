#include <iostream>
using namespace std;

class Test4
{
public:
	Test4()//无参构造函数
	{
		m_a = 0;
		m_b = 0;
		cout << "无参构造函数" << endl;
	}

	Test4(int a, int b)//有参数的构造函数
	{
		m_a = a; m_b = b;
		cout << "有参数构造函数" << endl;
	}
	Test4(int c)//有参数的构造函数
	{
		m_c = c;
		cout << "有参数构造函数，就一个参数" << endl;
	}
	//赋值构造函数 (拷贝构造函数)
	Test4(const Test4& obj)
	{
		cout << "我也是构造函数" << endl;
		m_b = obj.m_b + 100;
		m_a = obj.m_a + 100;
	}
public:
	void printT()
	{
		cout << "我是普通函数" << endl;
		cout << "m_a" << m_a << " "<< "m_b"<<m_b<< endl;

	}
private:
protected:
	int m_a;
	int m_b;
	int m_c;
};
//拷贝构造函数 用1个对象去初始化另外1个对象

void main()
{
	Test4 t1(1,2);
	Test4 t0(1,2);
	
	t0 = t1;//用t1给t0赋值,不会调用拷贝构造函数，与下面的初始化不同
	
	//第一种调用方法
	//Test4 t2 = t1;//用t1来初始化t2,它调用了拷贝构造函数 Test4(const Test4& obj)
	//t2.printT();
	
	
	//第二种调用方法 
	Test4 t2(t1);//用t1 初始化 t2
	t2.printT();


	cout << "hello..." << endl;
	return;
}