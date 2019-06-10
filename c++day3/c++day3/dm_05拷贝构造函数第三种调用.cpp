#include <iostream>
using namespace std;

class Location
{
public:
	Location(int xx = 0, int yy = 0)
	{
		X = xx; Y = yy; 
		cout << "构造函数";
	}
	Location(const Location &p)//拷贝构造函数，用一个对象初始化另一个对象
	{
		X = p.X; Y = p.Y; 
		cout << "拷贝构造函数调用" << endl;
	}
	~Location()
	{
		cout << X << "," << Y << "对象清除" << endl;
	}
	int GetX() { return X; }     int GetY() { return Y; }

private:
	int X, Y;
};
//业务函数 形参是一个元素
void f(Location p)
{
	cout << p.GetX() << endl;
}
void playobj()
{
	Location a(1, 2);
	Location b = a;
	cout << "b对象已经初始化完毕" << endl;

	f(b);//b实参去初始化形参p，这时会调用拷贝构造函数
}

void main()
{
	
	playobj();
	cout << "hello..." << endl;
	return;
}