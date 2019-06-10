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
	//重载()
	F f;
	f(2, 4);
	//operator()(int a, int b);
	
	
	//函数调用来实现与重载()一样的功能，实质是有很大区别的
	F2 f2;
	f2.MemFuv(2, 4);
		

	cout << "hello..." << endl;
	return;
}
