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
//ҵ���� �β���һ��Ԫ��
void f(Location p)
{
	cout << p.GetX() << endl;
}
void playobj()
{
	Location a(1, 2);
	Location b = a;
	cout << "b�����Ѿ���ʼ�����" << endl;

	f(b);//bʵ��ȥ��ʼ���β�p����ʱ����ÿ������캯��
}

void main()
{
	
	playobj();
	cout << "hello..." << endl;
	return;
}