#include <iostream>
#include "MyPiont.h"//因为judge里面用到了MyPiont类，所以也要加头文件
#include "AdvCircle.h"
using namespace std;

void AdvCircle::setCircle(int _r, int _x0, int _y0)
{
	r = _r; x0 = _x0; y0 = _y0;
}

int AdvCircle::judge(MyPiont &myp)
{
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
}