#include <iostream>
using namespace std;

class Test3
{
public:
	void init(int _a, int _b)
	{
		a = _a;
		b = _b;
	}

protected:
private:
	int a;
	int b;	
};


void main()
{
	Test3 t1;//��û���ṩ���캯�������������Զ��ṩһ��Ĭ�ϵĹ��캯��
			 //��û���ṩ�������캯����������Ҳ���ṩһ��Ĭ�ϵ�

	int a = 10, b = 5;
	t1.init(a, b);//��ʾ�ĳ�ʼ���������Եú�����
	
	cout << "hello..." << endl;
	return;
}