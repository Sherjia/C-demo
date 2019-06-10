#include <iostream>
using namespace std;

//A���ģ�� ��
//ģ���� ���Ͳ�����

//��ģ��Ķ���
//��ģ���ʹ��
//��ģ������������

//ģ����
template <typename T>
class A
{
public:
	A(T a = 0)
	{
		this->a = a;
	}
	void PrintA()
	{
		cout << "a:" << a << endl;
	}
protected:
	T a;
private:
	
};

//ģ���� ���� ��ͨ��
//��ģ��������ʱ����Ҫ���廯ģ���࣬��������Ҫ֪�� ������������;�����ʲô����
//====>Ҫ֪��������ռ���ڴ��С�Ƕ��� ֻ���������͹̶���������֪����η����ڴ�
class B : public A<int>
{
public:
	B(int a=0, int b = 20) :A<int>(a)//B(int b = 20) :A<int>(0)
	{
		this->b = b;
	}
	void printB()
	{
		cout << "a: " << a << " b: " << b << endl;
	}
protected:
private:
	int b;
};

//��ģ��������ģ����
template <typename T>
class C : public A<T>
{
public:
	C(T a, T c) :A<T>(a)
	{
		this->c = c;
	}
	void printC()
	{
		cout << "a:"<<a<<" c: " << c << endl;
	}
protected:
	T c;
};
void main()
{
	C<int> c1(1, 2);
	c1.printC();

}

void main62()
{
	B b1(1,2);
	b1.printB();

}

//��ģ�� ����������
//������������Ҫ�������࣬����ҪA<int>
void UseA(A<int> &a)
{
	a.PrintA();
}
void main61()
{
	//ģ���ࣨ����������ͻ��ģ�===�������===>�������ı���
	A<int> a1(11), a2(20), a3(30);//ģ�����ǳ���� =====>��Ҫ�������;���
	a1.PrintA();

	UseA(a1);
	UseA(a2);
	UseA(a3);

	cout << "hello..." << endl;
	return;
}