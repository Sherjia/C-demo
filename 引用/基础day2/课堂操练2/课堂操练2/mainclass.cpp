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

	//��Բ��1 ����0
	int tag = c1.judge(p1);
	if (tag == 1)
	{
		cout << "��Բ��" << endl;
	}
	else
	{
		cout << "��Բ��" << endl;
	}


	cout << "hello..." << endl;
	return;

	cout << "hello..." << endl;
	return ;
}