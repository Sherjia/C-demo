#include <iostream>
using namespace std;


class Parent
{
public:
	void print()
	{
		a = b = 0;
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
	}
	int a;
	int b;
protected:
private:
	
};

//class Child : private Parent
//class Child : protected Parent
class Child : public Parent
{
public:
protected:
private:
	int c;
};


void main01()
{

	Child c1;
	c1.a = 1;
	c1.b = 2;
	c1.print();

	cout << "hello..." << endl;
	return;
}

