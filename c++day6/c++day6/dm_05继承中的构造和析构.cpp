#include <iostream>
using namespace std;


//����
//�ȵ��ø��๹�캯�� �ٵ������๹�캯��
//���������ĵ���˳���෴

/*
1.��������ڴ���ʱ�����ȵ��ø���Ĺ��캯��
2.���๹�캯��ִ�н�����ִ������Ĺ��캯��
3.������Ĺ��캯���в���ʱ����Ҫ������ĳ�ʼ���б�����ʾ����
4.�����������õ��Ⱥ�˳���빹�캯���෴
*/
class Parent
{
public:
	Parent(int a, int b)
	{
		this->a = a, this->b = b;
		cout << "���๹�캯��...\n" << endl;
	}
	
	void printP(int a, int b)
	{
		this->a = a, this->b = b;
		cout << "���ǵ�...\n" << endl;
	}
	~Parent()
	{
		cout << "��������...\n" << endl;
	}
private:
	int a;
	int b;
};

class child : public Parent
{
public:
	child(int a, int b, int c) : Parent(a,b)//���캯���ĳ�ʼ���б�
	{
		this->c = c;
		cout << "����Ĺ��캯��...\n" << endl;
	}
	~child()
	{
		cout << "���������...\n" << endl;
	}
	void printC()
	{
		cout << "���Ƕ���" << endl;
	}
protected:
private:
	int c;
};
void playObj()
{
	child c1(1, 2, 3);
}
void main()
{
	//Parent p(1, 2);

	playObj();

	cout << "hello..." << endl;
	return;
}