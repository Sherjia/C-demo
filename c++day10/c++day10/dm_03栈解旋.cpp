#include <iostream>
using namespace std;

//�쳣���׳��󣬴ӽ��뵽try�𣬵��쳣��catchǰ�����ڼ���ջ�ϵĹ�������ж��󣬶��ᱻ�Զ������������͹����˳���෴����һ���̾�ջ����
class Test3
{
public:
	Test3(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
		cout << "���캯��do\n";
	}
	~Test3()
	{
		cout << "��������do\n";
	}
protected:
private:
	int a = 0;
	int b = 0;
};

void myDivide()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDivideҪ�����쳣��\n";
	throw 1;//��ʱthrow���һ��ִ�У�t1,t2�ͱ��Զ����õ����������������� 
}

/*
//ֻ���׳��������͵��쳣
void myDivide1() throw (int, char, char *)
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDivideҪ�����쳣��\n";
	throw 1;
}
*/

//��д�������׳��κ�����
void myDivide1()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDivideҪ�����쳣��\n";
	throw 1;
}

/*
//���׳�
void myDivide1() throw ()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDivideҪ�����쳣��\n";
	throw 1;
}
*/

void main()
{
	try
	{
		myDivide();
	}
	catch (int a)
	{
		cout << "int�����쳣��\n";
	}
	catch (...)
	{
		cout << "δ֪�����쳣��\n";
	}
}