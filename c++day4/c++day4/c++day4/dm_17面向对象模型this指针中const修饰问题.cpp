#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b)//----> Test (Test *this,int a,int b) 
	{
		this->a = a;
		this->b = b;
	}
	void prinT()
	{
		cout << "a" << a << "b" << b << endl;
	}
	//constд��ʲô�ط���û��ϵ
	//const���ε���˭��
	//const���εĲ����β�a��b
	//const���ε���thisָ�룬��ָ����ڴ�ռ��ֵ���ᱻ�޸� this->a��this->b
	void OpVar(int a, int b) const // void const OpVar(int a, int b)--->>void OpVar(const Test *this,int a, int b)
	{
		cout << "a" << a << "b" << this->b << endl;
	}
protected:
private:
	int a;
	int b;
};


void main()
{

	Test t1(1, 2);
	t1.prinT();//prinT��&+1��
	cout << "hello..." << endl;
	return;
}