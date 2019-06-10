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
//g函数 返回一个元素(复杂类型的)
//结论1：其实返回的是一个新的匿名对象，因为A是个局部对象，不能够被返回，所以就初始化一个对象，所以调用了拷贝构造函数

//结论2：匿名对象的去和留
//如果用匿名对象，初始化 另一个同类型的对象，匿名对象转成有名对象，不被析构
//如果用匿名对象，赋值给 另一个同类型的对象，匿名对象被析构

//这样写代码，编译器就会返回一个新对象，是匿名的对象。
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
	//用匿名对象初始化m，此时编译器直接把匿名转成m(扶正)；从匿名变成了有名字m。第一种
	Location m = g();
	cout << "匿名对象被扶正，不会被析构掉\n" << endl;
	cout << m.GetX() << endl;
}
void objplay3()
{
	Location m2(1,2);//第二种
	m2 = g();
	cout << "因为用匿名对象=给m2，匿名对象，被析构\n" << endl;
	cout << m2.GetX() << endl;
}
void main()
{

	//objplay2();
	objplay3();
	cout << "hello..." << endl;
	return;
}