#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		a = 0;
		b = 0;
	}
	Test(int _a)
	{
		a = _a;
		b = 0;
	}
	Test(const Test& obj)
	{
		a = obj.a + 100;
		b = obj.b + 100;
	}
	void printT()
	{
		cout << "a:" << a << "b:" << b << endl;
	}
	
private:
	int a, b;
};

//�����ж����˿������캯��ʱ�������������ṩ�޲ι��캯��
//���ඨ����һ���вι��캯��ʱ�����������ṹ���޲ι��캯��
//д�˹��캯������Ҫ��
void main()
{

	Test t1;//�����޲ι��캯��
	cout << "hello..." << endl;
	return;
}