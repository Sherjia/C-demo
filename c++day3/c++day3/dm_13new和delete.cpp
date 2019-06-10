#include <iostream>
using namespace std;

// malloc 和 free 是c的函数
// new 和 delete 是c++的操作符
// new 基础类型变量  分配数组变量 分配类对象
void main1()
{
	//
	int *p = (int *)malloc(sizeof(int));
	*p = 10;
	free(p);

	int *p2 = new int;
	*p2 = 20;//分配基础变量
	free(p2);

	//
	int *p3 = new int(30);
	printf("*p3:%d \n", *p3);
	delete p3;

	cout << "hello..." << endl;
	return;
}

//分配数组变量
void main2()
{
	int *p = (int *)malloc(sizeof(int)* 10);
	p[0] = 1;
	free(p);

	//c++分配数组
	int *pArray = new int[10];
	pArray[1] = 2;
	delete[] pArray;//数组不要忘记中括号

	cout << "hello..." << endl;
	return;
}

class Test
{
public:
	Test(int _a)
	{
		a = _a;
		cout << "构造函数" << endl;
	}
	~Test()
	{
		cout << "析构函数" << endl;
	}
protected:
private:
	int a;
};

//分配对象
void main()
{
	Test *pT1 = (Test *)malloc(sizeof(Test));//c
	free(pT1);

	//c++
	Test *pT2 = new Test(10);//new可以自动执行类的构造函数，delete可以自动执行类的析构函数；malloc和free不行
	delete pT2;

	return;

}