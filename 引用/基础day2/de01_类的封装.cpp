# include <iostream>

using namespace std;

//��Բ�����
//1.�����Ժͷ������з�װ
//2.�����Ժͷ������з��ʿ���
//3.����ڲ����ⲿ
//4.��ķ��ʹؼ���
//public : ���εĳ�Ա���������ͺ���������������ڲ�������ⲿ����
//private: .....................,ֻ�����ڲ�����
//protected:....................,ֻ�����ڲ����ʣ����ڼ̳�

class MyCircle
{
public:
	double m_r;//���� ��Ա����
	double m_s;

public:
	double getR()//��Ա����
	{
		return m_r;
	}
	void setR(double r)
	{
		m_r = r;

	}
	double getS()
	{
		m_s = 3.14*m_r*m_r;
		return m_s;
	}

protected:
private:
};

//���װ�˳�Ա�����ͳ�Ա���� //���Ե�����ĳ�Ա����
void printCircle01(MyCircle *pC)
{
	cout << "r" << pC->getR()<< endl;
	cout << "s" << pC->getS()<< endl;
}
void printCircle02(MyCircle &myc)
{
	cout << "r" << myc.getR() << endl;
	cout << "s" << myc.getS() << endl;
}

void main01()//��ķ�װ��һ�㺬��
{
	
	MyCircle c1, c2;
	c1.setR(10);
	cout << "c1 s:" << c1.getS() << endl;
	
	c1.setR(11);
	printCircle01(&c1);
	
	c2.setR(20);
	printCircle01(&c2);

	c2.setR(15);
	printCircle02(c2);
	
	
	
	cout << "hello" << endl;

}

class MyAdvCircle
{

//double m_rĬ��û��Ȩ�����εĳ�Ա������˽�е� 
private://�൱���룬�����ⲿ����
	double m_r;//���� ��Ա����
	double m_s;

public:
	double getR()//��Ա����
	{
		return m_r;
	}
	void setR(double r)
	{
		m_r = r;

	}
	double getS()
	{
		m_s = 3.14*m_r*m_r;
		return m_s;
	}
};

void main02()
{
	MyAdvCircle c1, c2;
	//c1.m_r = 10;
	c1.setR(10);
}
/*
struct AAA
{
	int a;//struct������ࡣ��д��Ĭ����public
public:
private:
protected:
}; 

*/