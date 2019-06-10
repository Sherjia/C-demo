#include <iostream>
using namespace std;

//����������̣�����һ��Ԥ�ȶ���õĽӿڱ�̣�
//�����....ģ��Ļ���

class Figure //������ �д��麯������ͽг�����
{
public:
	//Լ��һ��ͳһ�Ľ��棨�ӿڣ������������ȥʵ��
	virtual void getArea() = 0; //���麯��
protected:
private:
};

class Circle : public Figure
{
public:
	Circle(int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "Բ�ε����:" << 3.14*a*a << endl;
	}
protected:
private:
	int a;
	int b;
};

class Tri : public Figure
{
public:
	Tri(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "�����ε����:" << a*b/2 << endl;
	}
private:
	int a;
	int b;
};

void objplay(Figure *base)
{
	base->getArea(); //�ᷢ����̬
}

class Square : public Figure
{
public:
	Square(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "�ı��ε����:" << a*b << endl;
	}
protected:
private:
	int a;
	int b;
};

void main()
{
	//Figure f; //���󣬳����಻�ܱ�ʵ����

	Figure *base = NULL;//

	Circle c1(10, 20);
	Tri t1(20, 30);
	Square s1(50, 60);

	//����������̣�����һ��Ԥ�ȶ���õĽӿڱ�̣�

	objplay(&c1);
	objplay(&t1);
	objplay(&s1);

	//c1.getArea();

	cout << "hello..." << endl;
	return;
}