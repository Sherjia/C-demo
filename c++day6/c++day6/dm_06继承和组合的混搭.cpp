#include <iostream>
using namespace std;

//原则： 先构造父类，再构造成员变量，最后构造自己
//      先析构自己，再析构成员变量，最后析构父类//先构造的对象，后释放
class Object
{
public:
	Object(int a, int b)
	{
		this->a = a, this->b = b;
		cout << "object构造函数执行" <<" a "<<a<<" b "<<b<< endl;
	}
	~Object()
	{
		cout << "object析构函数\n";
	}
protected:
	int a;
	int b;
private:
};

class Parent : public Object
{
public:
	Parent(char *p) : Object(1,2)
	{
		this->p = p;
		cout << "父类构造函数...\n" <<p<< endl;
	}

	void printP(int a, int b)
	{
		cout << "我是爹...\n" << endl;
	}
	~Parent()
	{
		cout << "析构函数...\n" << p<<endl;
	}
protected:
	char *p;
};

class child : public Parent
{
public:
	child(char *p) : Parent(p), obj1(3,4), obj2(5,6)//构造函数的初始化列表
	{
		this->myp = p;
		cout << "子类的构造函数...\n" <<myp<< endl;
	}
	~child()
	{
		cout << "子类的析构...\n" << myp<<endl;
	}
	void printC()
	{
		cout << "我是儿子" << endl;
	}
protected:
	char* myp;
	Object obj1;
	Object obj2;
};

void objplay()
{
child c1("继承测试");
}
void main()
{
	objplay();

	cout << "hello..." << endl;
	return;
}