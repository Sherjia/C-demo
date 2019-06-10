#include <iostream>
using namespace std;

class Test
{
public:
	int a, b;
public:
	Test(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
	}
	//t3 = t1.TestAdd(t2);
	Test TestAdd(Test &t2)//返回一个元素
	{
		Test tmp(this->a + t2.a, this->b + t2.b);
		return tmp;
	}
	//t1 = t1 + t2
	//返回一个引用，相当于返回一个变量自身；返回t1这个元素 this就是&t1
	Test& TestAdd2(Test &t2)
	{
		this->a = this->a + t2.a;
		this->b = this->b + t2.b;

		return *this;//把 *（&t1）又回到了t1元素
	}
	void prinT()
	{
		cout << "a" << a << "b" << b << endl;
	}
	~Test()
	{
		cout << "a" << a << "b" << b;
		cout << "析构函数" << endl;
	}
protected:
private:
};
//把成员函数 转成 全局函数 多了一个参数
void prinT(Test *pT)
{
	cout << "a:" << pT->a << "b:" << pT->b << endl;
}

//全局函数的方法
//全局函数 转成员函数 少一个参数
Test TestAdd(Test &t1, Test &t2)
{
	Test tmp(t1.a + t2.a, t1.b + t2.b);
	return tmp;
}
void main()
{
	Test t1(1, 2);
	Test t2(3, 4);

	//t1 = t1 + t2
	t1.TestAdd2(t2);
	t1.prinT();
	
	Test t3;
	t3 = TestAdd(t1, t2);
	prinT(&t3);
}

void main181()
{
	Test t1(1, 2);
	Test t2(3, 4);
	
	Test t3;

	//全局函数方法
	t3 = TestAdd(t1, t2);

	//成员函数方法	
	{
		//先把测试案例写出来
		Test t4 = t1.TestAdd(t2);//匿名对象直接转化为t4
		t4.prinT();
		Test t5;
		t5 = t1.TestAdd(t2);//匿名对象复制给t5
		t5.prinT();
	}

	cout << "hello..." << endl;
	return;
}
