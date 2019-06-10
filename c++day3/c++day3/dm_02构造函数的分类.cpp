#include <iostream>
using namespace std;

class Test2
{
public:
	Test2()//无参构造函数
	{
		m_a = 0;
		m_b = 0;
		cout << "无参构造函数" << endl;
	}

	Test2(int a,int b)//有参数的构造函数
	{
		m_a = a; m_b = b;
		cout << "有参数构造函数" << endl;
	}
	Test2(int c)//有参数的构造函数
	{
		m_c = c;
		cout << "有参数构造函数，就一个参数" << endl;
	}
	//赋值构造函数 (拷贝构造函数)
	Test2(const Test2& obj)
	{
		cout << "我也是构造函数" << endl;
	}
private:
protected:
	int m_a;
	int m_b;
	int m_c;
};

void main21()
{
	Test2 t1;//这样会自动调用无参构造函数


	cout << "hello..." << endl;
	return;
}

void main()
{
	Test2 t1(1,2);//调用有参构造函数，   括号法，编译器自动调用

	
	Test2 t2 = (3, 4);//调用的单参数的有参构造函数，此时","是运算符，输出4     =号法，编译器自动调用
					  //c++对等号操作符进行了功能增强，不再是赋值的功能

	
	
	Test2 t3 = Test2(5, 6);//手动调用法  会产生一个匿名对象（它的去和留）作用是完成了t3对象的初始化
						   //不同于t1 = t4 ，这是把t4赋值给t1,不是初始化

	
	
	cout << "hello..." << endl;
	return;
}