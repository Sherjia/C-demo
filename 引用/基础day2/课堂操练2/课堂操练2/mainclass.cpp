#include <iostream>
using namespace std;
#include "AdvCircle.h"
#include "MyPiont.h"


void main()
{
	AdvCircle c1;
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

	cout << "hello..." << endl;
	return ;
}