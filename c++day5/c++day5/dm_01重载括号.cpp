#include <iostream>
using namespace std;

class F
{
public:
	int operator()(int a, int b)
	{
		return a*a + b*b;
	}
protected:
private:
};
class F2
{
public:
	int MemFuv(int a, int b)
	{
		return a*a + b*b;
	}
protected:
private:
};


void main()
{
	//����()
	F f;
	f(2, 4);
	//operator()(int a, int b);
	
	
	//����������ʵ��������()һ���Ĺ��ܣ�ʵ�����кܴ������
	F2 f2;
	f2.MemFuv(2, 4);
		

	cout << "hello..." << endl;
	return;
}
