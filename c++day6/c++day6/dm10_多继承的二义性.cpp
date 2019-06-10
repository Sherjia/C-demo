#include <iostream>
using namespace std;


class B
{
public:
	int b;
protected:
private:
};

class B1 : virtual public B
{
public:
	int b1;
protected:
private:
};

class B2 : virtual public B
{
public:
	int b2;
protected:
private:
};

class C : public B1, public B2
{
public:
	int c;
protected:
private:
};



void main()
{
	C c1;
	c1.b1 = 100;
	c1.b2 = 200;
	c1.c = 300;
	
	//c1.b = 500;错误。 因为B1，B2都从B中继承了b，但是C虽然又多继承了B1和B2，但C不知道是从B1还是B2中继承b，这就是二义性
	c1.b = 500;//加了virtual关键字变为虚继承，来解决继承的二义性

	cout << "hello..." << endl;
	return;
}