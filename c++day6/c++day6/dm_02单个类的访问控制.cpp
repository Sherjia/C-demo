#include <iostream>
using namespace std;

//public���εĳ�Ա������������ⲿ���ڲ�������ʹ��
//private���εĳ�Ա������ֻ��������ڲ�ʹ��
//protected���εĳ�Ա����,������ڲ�ʹ�ã��ڼ̳е������п��ã���Ϊ���ڼ�����ʹ�ã���Ϊ�˼̳�
//��������ʿ��������
//1.protected���εĳ�Ա����,������ڲ�ʹ�ã��ڼ̳е������п��ã���Ϊ���ڼ�����ʹ�ã���Ϊ�˼̳�
//2.��Ŀ������ һ������� ��public
class Parent
{
public:
	int a;
protected:
	int b;
private:
	int c;
public:
	void printT()
	{
		cout << "printT" << endl;
	}
};

/*
c++�еļ̳з�ʽ��public��protected��private����Ӱ������Ķ����������
	�ж�ĳһ�仰���ܷ񱻷��ʵ�
	1.��������䣬��仰д��������ڲ����ⲿ
	2.��������δӸ���̳У�public��protected��private��
	3.������ķ��ʼ���public��protected��private��
*/

class Child : public Parent
{
public:
	void uesVar()
	{
		a = b = 0;
		//c = 0;//���ۺ��ּ̳У�����˽�����Զ��޷����ʣ�����
	}
protected:
private:
};

//public�̳�
void main21()
{
	Parent t1, t2;
	t1.a = 10;//
	//t1.b = 20;//����,�ڸ������Ǳ����ģ��޷����ⲿ����
	//t2.c = 30;//���ۺ��ּ̳У�����˽�����Զ��޷����ʣ�����

	cout << "hello..." << endl;
	return;
}
//private�̳�
class Child2 : private Parent
{
public:
	void uesVar()
	{
		//a = b = 0;�������б�Ϊprivate��Ա
		//c = 0;//���ۺ��ּ̳У�����˽�����Զ��޷����ʣ�����
	}
protected:
private:
};

void main22()
{
	Child2 c1,c2,c3;
	//c1.a = 10;//����,�������б�˽�У���д�������ⲿ�����ܷ���
	//c2.b = 10;//�����������б�˽�У���д�������ⲿ�����ܷ���
	//c3.b = 30;//���󣬱����Ϊ�����˽��

	cout << "hello..." << endl;
	return;
}
//protected�̳�
class Child3 : protected Parent
{
public:
	void uesVar()
	{
		a = b = 0;//�����඼��Ϊprotected��Ա��ֻ����������ڲ�����
		//c = 0;//���ۺ��ּ̳У�����˽�����Զ��޷����ʣ�����
	}
protected:
private:
};
void main()
{
	Child3 c3;
	//c3.a = 10;//�����඼��Ϊprotected��Ա��ֻ����������ڲ����ʣ�����
	//c3.b = 20;//�����඼��Ϊprotected��Ա��ֻ����������ڲ����ʣ�����
	//c3.c = 30;//���󣬱����Ϊ�����˽��

	cout << "hello..." << endl;
	return;
}
