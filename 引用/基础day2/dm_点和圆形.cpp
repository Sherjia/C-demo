#include <iostream>
using namespace std;

class MyPiont;//类的前置声明

class MyPiont
{
public:
	void setPoint(int _x1, int _y1)
	{
		x1 = _x1;
		y1 = _y1;
	}
	int getX1()
	{
		return x1;
	}
	int getY1()
	{
		return y1;
	}
private:
	int x1;
	int y1;
};


class AdvCricle
{
public:
	void setCircle(int _r, int _x0, int _y0)
	{
		r = _r; x0 = _x0; y0 = _y0;
	}
public:
	int judge(MyPiont &myp)
	{
		int dd = (myp.getX1() - x0)*(myp.getX1() - x0) + (myp.getY1() - y0)*(myp.getY1() - y0);
		if (dd <= r*r)
		{
			return 1;//在圆内
		}
		else
		{
			return 0;//在圆外
		}

		return 0;
	}
private:
	int r;
	int x0;
	int y0;
};


void main()
{
	AdvCricle c1;
	MyPiont p1;

	c1.setCircle(2, 3, 3);
	p1.setPoint(7, 7);

	//在圆内1 否则0
	int tag = c1.judge(p1);
	if (tag == 1)
	{
		cout << "在圆内" << endl;
	}
	else
	{
		cout << "在圆外" << endl;
	}
	

	cout << "hello..." << endl;
	return;
}