#include <iostream>
using namespace std;

//���ඨ��ľ�̬�������������������๲��

class A
{
public:
	A()
	{
		cout << "A�Ĺ��캯��" << endl;
	}
public:
	static int a;
	int	b;
	void get()
	{
		cout << " b " << b << endl;
	}
	void print()
	{
		cout << "AAAA" << endl;
	}
protected:
private:
};

int A::a = 100;//��ֻ�Ǽ򵥵ı�����ֵ����Ҫ�����ñ����������ڴ棬���ڼ̳������õ���a,����ᱨ���

class B : private A
{
public:
	B()
	{
		cout << "B�Ĺ��캯��" << endl;
	}
public:
	int b, c;
	void get_child()
	{
		cout << " b " << b << endl;
		cout << a << endl;
	}
	void print()
	{
		cout << "BBBB" << endl;
	}
protected:
private:
};

//1.static�ؼ�����Ȼ��ѭ������ķ��ʿ��ƹ���
//2.��ֻ�Ǽ򵥵ı�����ֵ����Ҫ�����ñ����������ڴ棬���ڼ̳������õ���a,����ᱨ���
//3.A������ӹ��캯�� ��д��public���Ĭ����˽�еĹ��캯�����������̳�ҪС�ģ�����������ϣ����˽�е�
void main()
{
	A a1;
	a1.print();

	B b1;
	b1.get_child();

	return;
}
