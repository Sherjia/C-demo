#include <iostream>
using namespace std;

class A
{
public:
	A(int _a)
	{
		a = _a;
		cout << "���캯��"<<"a:" << a << endl;
	}
	~A()
	{
		
		cout <<"��������"<< "a:" << a << endl;
	}
private:
	int a;
protected:
};

class B
{
public:
	B(int _b1, int _b2) :a1(1), a2(2), c(0)
	{

	}
	B(int _b1, int _b2, int m, int n) :a1(m), a2(n),c(0)//���캯����ʼ���б� �������B���� �����һ��A�����A����˹��캯����
									 //�ݹ���д��A�Ĺ��죬��Ҫ�ã�û�л����ʼ��A
									 //�µ��﷨��Constructor::Constructor():m1(v1),m2(v1,v2),m3(v3)
									 //��const���ͱ���ʹ�ó�ʼ���б�����ʼ�� 
	{
		b1 = _b1; b2 = _b2; cout << "B�Ĺ��캯��" << endl;
	}
	~B()
	{
		cout << "B����������" << endl;
	}
private:
	int b1, b2;
	A a1, a2;
	const int c;
protected:
};

void obj10play()
{

	//A a1(10);
	//B objB(1,2);

	//1.��������
	B objB2(1, 2, 3, 4);

	//2.����˳�� ������ִ�б���϶���Ĺ��캯�������ж�������ն���˳�򣬲��ǰ��ճ�ʼ���б�˳��
	//          �����������͹��캯���ĵ���˳���෴
	return;
}

void main()
{
	obj10play();
	return;
}