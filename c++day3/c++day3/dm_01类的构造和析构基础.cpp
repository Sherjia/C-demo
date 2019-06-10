#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class Test
{
public:
	Test()//构造函数  作用是完成对属性的初始化工作
	{
		a = 10;
		p = (char*)malloc(100);
		strcpy(p, "aaaaaf");
		cout << "我是构造函数" << endl;
	}
	void printP()
	{
		cout << a << endl;
		cout << p << endl;
	}
	~Test()
	{
		if (p != NULL)
		{
			free(p);
		}
		cout << "我是析构函数" << endl;
	}
private:
	int a;
	char *p;
protected:
};

//给对象搭建一个舞台，研究对象的行为
void objplay()
{
	//先创建的对象后释放。先调用t1的构造函数，在调用t2的构造函数；释放时，先析构t2,再t1
	Test t1;//调用构造函数
	t1.printP();

	cout << "分隔符1" << endl;

	Test t2;
	t2.printP();

	cout << "分隔符2" << endl;
}

void main()
{
	objplay();

	cout << "hello..." << endl;
	return;
}