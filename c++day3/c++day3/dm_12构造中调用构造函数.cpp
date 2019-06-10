#include <iostream>
using namespace std;

//在构造函数中调用构造函数，是一种危险的行为
class MyTest
{
public:
	MyTest(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	MyTest(int a, int b)
	{
		this->a = a;
		this->b = b;

		MyTest(a, b, 100);//这里会产生一个匿名对象，生命周期就在这一句，之后立即被析构函数清除，所以c最终不是100，是个乱码
	}
	~MyTest()
	{
		printf("~MyTest:%d, %d,%d\n", a, b, c);
	}
protected:
private:
	int a, b, c;
public:
	int getC() const { return c; }
	void setC(int val) { c = val; }
};

int main()
{
	MyTest t1(1, 2);

	cout <<"c:%d"<< t1.getC() << endl;//c是多少？解析在上面
	return 0;
}