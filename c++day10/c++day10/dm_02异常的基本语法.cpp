#include <iostream>
using namespace std;

//基本语法
//发生异常之后，是跨函数的
//捕捉到异常以后，如果不想处理，可以继续往外扔
//catch异常时，按照类型进行catch
//异常是严格按照类型来匹配

void main()
{
	try
	{
		throw 'z';
	}
	catch (int e)
	{
		cout << "捕获int类型异常" << endl;
	}
	catch (...)
	{
		cout << "未知类型异常" << endl;
	}
}

void divide(int x, int y)
{
	if (y == 0)
	{
		throw x;//抛出int类型异常
	}

	cout << "divide结果：" << x / y << endl;
}

void myDivide(int x, int y)
{
	try
	{
		divide(x, y);
	}
	catch (...)//捕捉到异常以后，如果不想处理，可以继续往外扔
	{
		cout << "我接到了divide的异常，但没处理，我向上抛" << endl;
		throw;
	}
}

void main21()
{
	try
	{
		//divide(10,2);
		//divide(100, 0);

		myDivide(100, 0);
	}
	catch (int e)
	{
		cout << e << "被零除" << endl;
	}
	catch (...)
	{
		cout << "其他未知类型异常" << endl;
	}

	cout << "hello..." << endl;
	return;
}