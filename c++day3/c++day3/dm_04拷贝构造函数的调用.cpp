#include <iostream>
using namespace std;

class Test4
{
public:
	Test4()//�޲ι��캯��
	{
		m_a = 0;
		m_b = 0;
		cout << "�޲ι��캯��" << endl;
	}

	Test4(int a, int b)//�в����Ĺ��캯��
	{
		m_a = a; m_b = b;
		cout << "�в������캯��" << endl;
	}
	Test4(int c)//�в����Ĺ��캯��
	{
		m_c = c;
		cout << "�в������캯������һ������" << endl;
	}
	//��ֵ���캯�� (�������캯��)
	Test4(const Test4& obj)
	{
		cout << "��Ҳ�ǹ��캯��" << endl;
		m_b = obj.m_b + 100;
		m_a = obj.m_a + 100;
	}
public:
	void printT()
	{
		cout << "������ͨ����" << endl;
		cout << "m_a" << m_a << " "<< "m_b"<<m_b<< endl;

	}
private:
protected:
	int m_a;
	int m_b;
	int m_c;
};
//�������캯�� ��1������ȥ��ʼ������1������

void main()
{
	Test4 t1(1,2);
	Test4 t0(1,2);
	
	t0 = t1;//��t1��t0��ֵ,������ÿ������캯����������ĳ�ʼ����ͬ
	
	//��һ�ֵ��÷���
	//Test4 t2 = t1;//��t1����ʼ��t2,�������˿������캯�� Test4(const Test4& obj)
	//t2.printT();
	
	
	//�ڶ��ֵ��÷��� 
	Test4 t2(t1);//��t1 ��ʼ�� t2
	t2.printT();


	cout << "hello..." << endl;
	return;
}