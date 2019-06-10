#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
		cout << "Parent a" << a << endl;
	}

	virtual void print()//����͸���ĺ�����һ��
	{
		cout << "Parent ��ӡa" << a << endl;
	}
protected:
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b) : Parent(10)
	{
		this->b = b;
		cout << "Child b" << b << endl;
	}

	void print()//virtual void print(); ����д��virtual,�����д�ɲ�д����һ�㶼д
	{
		cout << "Child ��ӡb" << b << endl;
	}
protected:
private:
	int b;
};

void howToPrint(Parent *base)
{
	base->print(); //һ�ֵ������ �ж��ֱ�����̬
}

void howToPrint2(Parent &base)
{
	base.print();
}

void main()
{
	Parent *base = NULL;
	Parent p1(20);
	Child c1(30);

	base = &p1;
	base->print();//ִ�и���Ĵ�ӡ����

	base = &c1;
	base->print();//������ִ�и���Ĵ�ӡ����  �Ǿ�Ҫ���������������� 
				  //��������������������Ҫ�ģ�1.����ʵ�ʵĶ����������ж����������ĵ���
				  //2.������ָ��ָ����Ǹ����������ø����ж���ĺ���
				  //3.�������ָ��ָ��������������������ඨ�����������
				  //�Ǿ���Ҫ��̬�������ʹ��virtual�ؼ�����ʵ��
	{
		Parent &base2 = p1;
		base2.print();

		Parent &base3 = c1;//base3��c1�ı����������Ǵ�ӡ����Ĵ�ӡ��������virtual֮��ͻ��ӡ����Ĵ�ӡ����
		base3.print();
	}

	//��������
	howToPrint(&p1);
	howToPrint(&c1);//��Ȼ�Ǵ�ӡ����Ĵ�ӡ���� ��virtual֮��ͻ��ӡ����Ĵ�ӡ����

	howToPrint2(p1);
	howToPrint2(c1);//��Ȼ�Ǵ�ӡ����Ĵ�ӡ���� ��virtual֮��ͻ��ӡ����Ĵ�ӡ����

	cout << "hello..." << endl;
	return;
}