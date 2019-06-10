#pragma once
#include "MyPiont.h"


class AdvCircle
{
public:
	void setCircle(int _r, int _x0, int _y0);
	int judge(MyPiont &myp);
private:
	int r;
	int x0;
	int y0;
};