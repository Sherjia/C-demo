#include<iostream>


using namespace std;

class Cube
{
public:
	void setA(int a)
	{
		m_a = a;
	}
	void setB(int b)
	{
		m_b = b;
	}
	void setC(int c)
	{
		m_c = c;
	}
	void setABC(int a=0, int b=0, int c=0)
	{
		m_a = a;  m_b = b;  m_c = c;
	}
public:
	int getV()
	{
		m_v = m_a * m_b *m_c;
		return m_v;
	}
	int getS()
	{
		m_s = ((m_a*m_b) + (m_a*m_c) + (m_b*m_c)) * 2;
			return m_s;
	}
	int getA()
	{
		return m_a;
	}
	int getB()
	{
		return m_b;
	}
	int getC()
	{
		return m_c;
	}
	int judgeCube(Cube &v1, Cube &v2)
	{
		if ((v1.getA() == v2.getA()) &&
			(v1.getB() == v2.getB()) &&
			(v1.getC() == v2.getC())
			)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}



private:
	int m_a;
	int m_b;
	int m_c;
	int m_v;
	int m_s;
};
//全局函数
int judgeCube(Cube &v1, Cube &v2)
{
	if (	(v1.getA() == v2.getA()) &&
			(v1.getB() == v2.getB()) &&
			(v1.getC() == v2.getC())
	   )
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
void main()//第二种方法全局函数调用
{

	Cube v1, v2;
	v1.setABC(1, 2, 3);
	cout << v1.getS() << endl;
	cout << v1.getV() << endl;
	cout << "kb" << endl;


	v2.setABC(1, 2, 4);

	if (v1.judgeCube(v1, v2) == 1)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	system("pause");
	return;

}

/*
void main01()//第一种方法全局函数调用
{

	Cube v1, v2;
	v1.setABC(1, 2, 3);
	cout << v1.getS() << endl;
	cout << v1.getV() << endl;
	cout << "kb" << endl;


	v2.setABC(1, 2, 4);

	//如何判断两个立体是否相等
	if (judgeCube(v1, v2) == 1)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	system("pause");
	return;

}
*/