#include <iostream>
using namespace std;

class Test2
{
public:
	Test2()//�޲ι��캯��
	{
		m_a = 0;
		m_b = 0;
		cout << "�޲ι��캯��" << endl;
	}

	Test2(int a,int b)//�в����Ĺ��캯��
	{
		m_a = a; m_b = b;
		cout << "�в������캯��" << endl;
	}
	Test2(int c)//�в����Ĺ��캯��
	{
		m_c = c;
		cout << "�в������캯������һ������" << endl;
	}
	//��ֵ���캯�� (�������캯��)
	Test2(const Test2& obj)
	{
		cout << "��Ҳ�ǹ��캯��" << endl;
	}
private:
protected:
	int m_a;
	int m_b;
	int m_c;
};

void main21()
{
	Test2 t1;//�������Զ������޲ι��캯��


	cout << "hello..." << endl;
	return;
}

void main()
{
	Test2 t1(1,2);//�����вι��캯����   ���ŷ����������Զ�����

	
	Test2 t2 = (3, 4);//���õĵ��������вι��캯������ʱ","������������4     =�ŷ����������Զ�����
					  //c++�ԵȺŲ����������˹�����ǿ�������Ǹ�ֵ�Ĺ���

	
	
	Test2 t3 = Test2(5, 6);//�ֶ����÷�  �����һ��������������ȥ�����������������t3����ĳ�ʼ��
						   //��ͬ��t1 = t4 �����ǰ�t4��ֵ��t1,���ǳ�ʼ��

	
	
	cout << "hello..." << endl;
	return;
}