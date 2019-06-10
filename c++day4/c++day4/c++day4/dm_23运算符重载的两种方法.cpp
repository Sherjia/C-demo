#include <iostream>
using namespace std;

class Complex
{	
public:
	//ȫ�ֺ�������+�������
	friend Complex operator+(Complex &c1, Complex &c2);
	//ȫ�ֺ�������ǰ��++
	friend Complex operator++(Complex &c1);
	//ȫ�ֺ������غ���++
	friend Complex operator++(Complex &c1, int);
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << " + " << b << " i " << endl;
	}
	//��Ա�������� ʵ��-�����������
	Complex operator-(Complex &c2)
	{
		Complex tmp(this->a-c2.a, this->b-c2.b);
		return tmp;
	}
	//ǰ��--���������ó�Ա����ʵ��
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}
	//����--���������ó�Ա����ʵ��
	Complex& operator--(int)//������Ҫ�������Ǻ���--�����Բ�������Ҫһ��ռλ��
	{
		Complex tmp = *this;////��Ϊ�Ǻ���++����ʹ�ã���������++
		this->a--;
		this->b--;
		return tmp;
	}
protected:
private:
	int a;
	int b;
};

//ȫ�ֺ�����ʵ��+�����������
Complex operator+(Complex &c1, Complex &c2)
{
	Complex tmp(c1.a+c2.a, c1.b+c2.b);
	return tmp;
}

//ȫ�ֺ�����ʵ�� ǰ��++���������
Complex operator++(Complex &c1)
{
	c1.a++;
	c1.b++;
	return c1;
}
//ȫ�ֺ�����ʵ�� ����++���������
Complex operator++(Complex &c1, int)
{
	//��Ϊ�Ǻ���++����ʹ�ã�����c1++
	Complex tmp = c1;
	c1.a++;
	c1.b++;
	return tmp;

}

/*
ȫ�ֺ��������Ա��������ʵ����������ز���
1.Ҫ���������������һ��������д����������
2.���ݲ�������д����������
3.����ҵ�����ƺ�������ֵ���������Ƿ������á�����ָ�� Ԫ�أ�����ʵ�ֺ���ҵ��

*/
void main()
{
	Complex c1(1, 2), c2(3, 4);
	
	//ȫ�ֺ�����ʵ��+�����������
	//Complex operator+(Complex &c1, Complex &c2);
	Complex c3 = c1 + c2;
	c3.printCom();

	
	//��Ա�������� ʵ��-�����������
	//c1.operator-(c2);
	//Complex operator-(Complex &c2)
	Complex c4 = c1 - c2;
	c4.printCom();

	
	//ǰ��++������ ��ȫ�ֺ���ʵ��
	//Complex operator++(Complex &c1)
	++c1;
	c1.printCom();

	
	//ǰ��--���������ó�Ա����ʵ��
	//Complex& operator--()
	--c1;
	c1.printCom();

	
	//����++����������ȫ�ֺ���ʵ��
	//Complex operator++(Complex &c1, int),������Ҫ�������Ǻ���--�����Բ�������Ҫһ��ռλ��
	c1++;
	c1.printCom();

	
	//��Ա�����ķ���������--ʵ��
	c1--;
	c1.printCom();
	

	cout << "hello..." << endl;
	return;
}