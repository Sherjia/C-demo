#include <iostream>
using namespace std;

class Complex
{
public:
	int a;
	int b;
public:
	Complex(int a = 0,int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << " + " << b << " i " << endl;
	}
protected:
private:
};
//1.������ȫ�ֺ���
Complex myAdd(Complex &c1, Complex &c2)
{
	Complex tmp(c1.a + c2.b, c1.a + c2.b);
	return tmp;
}
//2.������ ����
Complex operator+(Complex &c1, Complex &c2)
{
	Complex tmp(c1.a + c2.b, c1.a + c2.b);
	return tmp;
}

void main()
{
	int a = 0, b = 0;
	int c;
	c = a + b;//�������������ͣ�������֪���������

	Complex c1(1, 2), c2(3, 4);
	
	
	Complex c3;//��Ҳ��һ���������ͣ��û��Զ����������ͣ���������֪����ν�������
	//c3 = c1 + c2;
	//������Ӧ���ṩһ�ֻ��ƣ����Զ������������л��ᣬ�������������--->��������ػ���

	//��������ػ���

	//����1
	//Complex c4 = myAdd(c1, c2);
	//c4.printCom();
	
	//����2  //��������ʽComplex c4 = c1 + c2;
	//Complex c4 = operator+(c1, c2);
	//c4.printCom();

	//����3
	Complex c4 = c1 + c2;
	c4.printCom();

	//�ܽ᣺1.��������صı�����һ������


	cout << "hello..." << endl;
	return;
}