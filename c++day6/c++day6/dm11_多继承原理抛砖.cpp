#include <iostream>
using namespace std;


class B//4���ֽ�
{
public:
	B()
	{
		cout << "B���캯��ִ��\n" << endl;
	}
	int b;
protected:
private:
};

class B1 : virtual public B//12���ֽ�
{
public:
	int b1;
protected:
private:
};

class B2 :  public B//8���ֽ�
{
public:
	int b2;
protected:
private:
};

class C : public B1, public B2
{
public:
	int c;
protected:
private:
};

void main()
{
	cout << sizeof(B) << endl;//4
	cout << sizeof(B1) << endl;//12 ����virtual�Ժ󣬱������������͵͵���������ԣ������ֽھͱ����
	cout << sizeof(B2) << endl;//8
	//cout << sizeof(B) << endl;

	return;
}



void main1101()
{
	C c1;
	c1.b1 = 100;
	c1.b2 = 200;
	c1.c = 300;

	//c1.b = 500;���� ��ΪB1��B2����B�м̳���b������C��Ȼ�ֶ�̳���B1��B2����C��֪���Ǵ�B1����B2�м̳�b������Ƕ�����
	//c1.b = 500;//����virtual�ؼ��ֱ�Ϊ��̳У�������̳еĶ�����

	cout << "hello..." << endl;
	return;
}

class D1
{
public:
	int k;
protected:
private:
};

class D2
{
public:
	int k;
protected:
private:
};

class E : public D1, public D2
{
public:
protected:
private:
};

void main1102()
{
	E e1;
	e1.D1::k = 100;//virtual�ؼ����޷��������������Ķ�̳У����������ֶ�������
	e1.D2::k = 200;

	return;
}



