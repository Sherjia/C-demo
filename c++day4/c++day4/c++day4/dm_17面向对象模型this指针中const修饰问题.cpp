#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b)//----> Test (Test *this,int a,int b) 
	{
		this->a = a;
		this->b = b;
	}
	void prinT()
	{
		cout << "a" << a << "b" << b << endl;
	}
	//const写在什么地方，没关系
	//const修饰的是谁？
	//const修饰的不是形参a，b
	//const修饰的是this指针，它指向的内存空间的值不会被修改 this->a和this->b
	void OpVar(int a, int b) const // void const OpVar(int a, int b)--->>void OpVar(const Test *this,int a, int b)
	{
		cout << "a" << a << "b" << this->b << endl;
	}
protected:
private:
	int a;
	int b;
};


void main()
{

	Test t1(1, 2);
	t1.prinT();//prinT（&+1）
	cout << "hello..." << endl;
	return;
}