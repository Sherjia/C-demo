#include <iostream>
using namespace std;

//ԭ�� �ȹ��츸�࣬�ٹ����Ա������������Լ�
//      �������Լ�����������Ա�����������������//�ȹ���Ķ��󣬺��ͷ�
class Object
{
public:
	Object(int a, int b)
	{
		this->a = a, this->b = b;
		cout << "object���캯��ִ��" <<" a "<<a<<" b "<<b<< endl;
	}
	~Object()
	{
		cout << "object��������\n";
	}
protected:
	int a;
	int b;
private:
};

class Parent : public Object
{
public:
	Parent(char *p) : Object(1,2)
	{
		this->p = p;
		cout << "���๹�캯��...\n" <<p<< endl;
	}

	void printP(int a, int b)
	{
		cout << "���ǵ�...\n" << endl;
	}
	~Parent()
	{
		cout << "��������...\n" << p<<endl;
	}
protected:
	char *p;
};

class child : public Parent
{
public:
	child(char *p) : Parent(p), obj1(3,4), obj2(5,6)//���캯���ĳ�ʼ���б�
	{
		this->myp = p;
		cout << "����Ĺ��캯��...\n" <<myp<< endl;
	}
	~child()
	{
		cout << "���������...\n" << myp<<endl;
	}
	void printC()
	{
		cout << "���Ƕ���" << endl;
	}
protected:
	char* myp;
	Object obj1;
	Object obj2;
};

void objplay()
{
child c1("�̳в���");
}
void main()
{
	objplay();

	cout << "hello..." << endl;
	return;
}