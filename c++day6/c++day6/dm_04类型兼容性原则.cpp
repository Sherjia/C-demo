#include <iostream>
using namespace std;

class Parent
{
public:
	void printP()
	{
		cout << "���ǵ�...\n" << endl;
	}
	Parent()
	{
		cout << "parent���캯��" << endl;
	}
	Parent(const Parent &obj)
	{
		cout << "copy���캯��" << endl;
	}
private:
	int a;
};

class child : public Parent
{
public:
	void printC()
	{
		cout << "���Ƕ���" << endl;
	}
protected:
private:
	int c;
};
/*
���ݹ�������ָ����������������
	���������Ե����������ʹ��
	����������ֱ�Ӹ�ֵ���������
	����������ֱ�ӳ�ʼ���������
	����ָ�����ֱ��ָ���������
	�������ÿ���ֱ�������������
*/

//c++�������ǲ��ᱨ���
void howToPrint(Parent *base)
{
	base->printP();//����� ��Ա����
}

void howToPrint2(Parent &base)
{
	base.printP();//����� ��Ա����
}
void main()
{

	Parent p1;
	p1.printP();

	child c1;
	c1.printC();
	c1.printP();

	//��ֵ������ԭ��
	//1-1 ����ָ�� �����ã�ָ�� �������

	Parent *p = NULL;
	p = &c1;
	p->printP();

	//1-2 ָ������������
	howToPrint(&p1);
	howToPrint(&c1);//���԰��������ĵ�ַ�Ӹ�����ָ��

	//1-3 ��������������
	howToPrint2(p1);
	howToPrint2(c1);//���԰���������Ӹ���������

	//�ڶ��㺬��
	//�����ø�������ʼ���������
	//�������һ������ĸ���
	Parent p3 = c1;

		 
	cout << "hello..." << endl;
	return;
}

