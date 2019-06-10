#include <iostream>
using namespace std;

class Complex
{
public:
	//friend void operator<<(ostream &cout, Complex &c1);//��Ԫ����
	friend ostream& operator<<(ostream &out, Complex &c1);
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << " + " << b << " i " << endl;
	}
	//ʵ��+�����������
	Complex operator+(Complex &c2)
	{
		Complex tmp(this->a+ c2.a, this->b+ c2.b);
		return tmp;
	}

	//��Ա������ʵ�� ǰ��++���������
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}
	//��Ա������ʵ�� ����++���������
	Complex& operator++(int)
	{
		//��Ϊ�Ǻ���++����ʹ�ã�����c1++
		Complex tmp = *this;
		this->a++;
		this->b++;
		return tmp;

	}
	//��Ա�������� ʵ��-�����������
	Complex operator-(Complex &c2)
	{
		Complex tmp(this->a - c2.a, this->b - c2.b);
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

/*
void operator<<(ostream &out, Complex &c1)
{
	out << c1.a << " + " << c1.b << " i "<<endl;
}
*/
//���������������ʽ���֧��
ostream& operator<<(ostream &out, Complex &c1)
{
	out << c1.a << " + " << c1.b << " i " << endl;
	return out;
}

void main01()
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

void main()
{
	int a = 10;
	Complex c1(1, 2), c2(3, 4);
	cout << a << endl;//���������������ж�
	
	
	//1.void operator<<(ostream &out, Complex &c1);��Ԫ����ʵ�����Ʋ�����������
	cout << c1;
	//2.ostream ���� ��ӳ�Ա���� .operator<<
	//cout.operator<<(c1);���ַ���ʵ�ֲ��ˣ���Ϊû��ostream���Դ����

	

	//2.��������ֵ����ֵ����Ҫ����һ������
	cout << c1 << "aaaddd";//���Ʋ������ĵ���˳���Ǵ�������


}