#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a, int b)//----> Test (Test *this,int a,int b) 
	{
		this->a = a;
		this->b = b;
	}
	void prinT()
	{
		cout << "a" << a << "b" << b << endl;
	}
protected:
private:
	int a;
	int b;
};


void main()
{
	
	Test t1(1, 2);
	t1.prinT();//prinT£¨&+1£©
	cout << "hello..." << endl;
	return;
}