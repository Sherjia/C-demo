#include <iostream>
using namespace std;

class A
{
public:
	//������λ�ú� public��privateû��ϵ
	friend void modifyA(A *pA, int _a);//���˹ؼ���friend�� ����modifyA��� ��A�ĺ�����(��Ԫ����) ���Է���A���˽�����ԣ�a,b
	friend class B;//B����A��ĺ����ѣ���B�п��Է���A���˽�г�Ա�����
	A(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{ 
		return this->a;
	}
protected:
private:
	int a, b;
};
class B
{
public:
	void Set(int a)
	{
		Aobject.a = a;
	}
	void printB()
	{
		cout << Aobject.a << endl;
	}
private:
	A Aobject;
};

void modifyA(A *pA, int _a)//��Ԫ�����Ĳ����������һ��A *pA����Ϊ��Ҫͨ�����������˽������
{
	//pA->a = 100;
	 pA->a = _a;
}

void main()
{
	B b1;
	b1.Set(300);
	b1.printB();
	return;
}

void main01()
{
	A a1(1, 2);
	cout << a1.getA()<< endl;

	modifyA(&a1, 300);
	cout << a1.getA() << endl;
	
	
	cout << "hello..." << endl;
	return;
}