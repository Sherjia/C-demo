#include <iostream>
using namespace std;

class Location
{
public:
	Location(int xx = 0, int yy = 0)
	{
		X = xx; Y = yy;
		cout << "���캯��";
	}
	Location(const Location &p)//�������캯������һ�������ʼ����һ������
	{
		X = p.X; Y = p.Y;
		cout << "�������캯������" << endl;
	}
	~Location()
	{
		cout << X << "," << Y << "�������" << endl;
	}
	int GetX() { return X; }     int GetY() { return Y; }

private:
	int X, Y;
};
//g���� ����һ��Ԫ��(�������͵�)
//����1����ʵ���ص���һ���µ�����������ΪA�Ǹ��ֲ����󣬲��ܹ������أ����Ծͳ�ʼ��һ���������Ե����˿������캯��

//����2�����������ȥ����
//������������󣬳�ʼ�� ��һ��ͬ���͵Ķ�����������ת���������󣬲�������
//������������󣬸�ֵ�� ��һ��ͬ���͵Ķ���������������

//����д���룬�������ͻ᷵��һ���¶����������Ķ���
Location g()
{
	Location A(1, 2);
	return A;
}
//
void objplay1()
{
	g();
}
void objplay2()
{
	//�����������ʼ��m����ʱ������ֱ�Ӱ�����ת��m(����)�������������������m����һ��
	Location m = g();
	cout << "�������󱻷��������ᱻ������\n" << endl;
	cout << m.GetX() << endl;
}
void objplay3()
{
	Location m2(1,2);//�ڶ���
	m2 = g();
	cout << "��Ϊ����������=��m2���������󣬱�����\n" << endl;
	cout << m2.GetX() << endl;
}
void main()
{

	//objplay2();
	objplay3();
	cout << "hello..." << endl;
	return;
}