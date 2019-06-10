#include <iostream>
using namespace std;

class Parent1
{
public:
	Parent1(int a = 0)
	{
		this->a = a;
	}
	void print() 
	{
		cout << "���ǵ�" << endl;
	}
private:
	int a;
};

class Parent2
{
public:
	Parent2(int a = 0)
	{
		this->a = a;
	}
	virtual void print() //1.���ֽŵĵط� ��дvirtual�ؼ��� �����⴦�� //�麯����
	{
		cout << "���ǵ�" << endl;
	}
private:
	int a;
};

void main()
{
	printf("sizeof(Parent1):%d sizeof(Parent2):%d \n", sizeof(Parent1), sizeof(Parent2));
	//Parent1 4���ֽڣ� Parent2 8���ֽ�

	cout << "hello..." << endl;
	return;
}