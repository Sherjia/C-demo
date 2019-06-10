#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		//print();
	}
	virtual void print()
	{
		cout << "���ǵ�" << endl;
	}
private:
	int a;
};

//�ɹ���һ��żȻ�ĳɹ����ȱ�Ȼ��ʧ�ܸ�����:�����Child�м������b����ô����ͻ���65��崻�
//��Ϊ�����������һ����Ա����b�����Բ�����һ���ˡ�ָ����һ���������ͣ����Ĳ������������������йء�
//���ۣ���̬���ø���ָ��ָ��������� �� ���ಽ��++����������ͬ�ĸ���
class Child : public Parent
{
public:
	
	/*
	Child(int a = 0, int b = 0) :Parent(a)
	{
		this->b = b;
		print();
	}
	*/
	Child(int b = 0) :Parent(0)
	{
		//this->b = b;
	}
	virtual void print()
	{
		cout << "���Ƕ���" << endl;
	}
private:
	//int b;
};

void HowToPlay(Parent *base)
{
	base->print();
}

void main()
{
	Child c1;//
	//c1.print();
	Child  *pC = NULL;
	Parent *pP = NULL;

	Child array[] = { Child(1), Child(2), Child(3) };
	
	pP = array;
	pC = array;
	pP->print();
	pC->print();//��̬����

	pP++;
	pC++;
	pP->print();
	pC->print();//��̬����

	pP++;
	pC++;
	pP->print();
	pC->print();//��̬����


	cout << "hello..." << endl;
	return;
}