#include <iostream>
using namespace std;

class Test
{
public:
	int a, b;
public:
	Test(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
	}
	//t3 = t1.TestAdd(t2);
	Test TestAdd(Test &t2)//����һ��Ԫ��
	{
		Test tmp(this->a + t2.a, this->b + t2.b);
		return tmp;
	}
	//t1 = t1 + t2
	//����һ�����ã��൱�ڷ���һ��������������t1���Ԫ�� this����&t1
	Test& TestAdd2(Test &t2)
	{
		this->a = this->a + t2.a;
		this->b = this->b + t2.b;

		return *this;//�� *��&t1���ֻص���t1Ԫ��
	}
	void prinT()
	{
		cout << "a" << a << "b" << b << endl;
	}
	~Test()
	{
		cout << "a" << a << "b" << b;
		cout << "��������" << endl;
	}
protected:
private:
};
//�ѳ�Ա���� ת�� ȫ�ֺ��� ����һ������
void prinT(Test *pT)
{
	cout << "a:" << pT->a << "b:" << pT->b << endl;
}

//ȫ�ֺ����ķ���
//ȫ�ֺ��� ת��Ա���� ��һ������
Test TestAdd(Test &t1, Test &t2)
{
	Test tmp(t1.a + t2.a, t1.b + t2.b);
	return tmp;
}
void main()
{
	Test t1(1, 2);
	Test t2(3, 4);

	//t1 = t1 + t2
	t1.TestAdd2(t2);
	t1.prinT();
	
	Test t3;
	t3 = TestAdd(t1, t2);
	prinT(&t3);
}

void main181()
{
	Test t1(1, 2);
	Test t2(3, 4);
	
	Test t3;

	//ȫ�ֺ�������
	t3 = TestAdd(t1, t2);

	//��Ա��������	
	{
		//�ȰѲ��԰���д����
		Test t4 = t1.TestAdd(t2);//��������ֱ��ת��Ϊt4
		t4.prinT();
		Test t5;
		t5 = t1.TestAdd(t2);//���������Ƹ�t5
		t5.prinT();
	}

	cout << "hello..." << endl;
	return;
}
