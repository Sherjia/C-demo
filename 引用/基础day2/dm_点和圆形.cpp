#include <iostream>
using namespace std;

class MyPiont;//���ǰ������

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
			return 1;//��Բ��
		}
		else
		{
			return 0;//��Բ��
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
}