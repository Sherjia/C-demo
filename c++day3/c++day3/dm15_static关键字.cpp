#include <iostream>
using namespace std;

class BB
{
public:
	void AddC()
	{
		c += 1;
	}
	void printC()
	{
		cout << "c:" << c << endl;
	}
	static void getC()//��̬��Ա����
	{
		cout << "c:" << c << endl;
		//�����ھ�̬��Ա�����п��Ե�����ͨ��Ա���Ի�����ͨ��Ա������
		//cout << "a:" << a << endl;//error C2597: �ԷǾ�̬��Ա��BB::a���ķǷ�����
	}
protected:
private:
	int a;
	int b;
	static int c;//��̬��Ա����

};
//��̬������ ����ʹ����ͨ��Ա������ ��ͨ��Ա����
int BB::c = 10;

void main()
{
	BB b1, b2, b3;
	b1.printC();
	b2.AddC();
	b3.printC();

	//��̬��Ա�����ĵ��÷���
	b3.getC();//�ö���.
	BB::getC();//��::

	cout << "hello..." << endl;
	return;
}
