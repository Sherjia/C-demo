#include <iostream>
using namespace std;


class B//4个字节
{
public:
	B()
	{
		cout << "B构造函数执行\n" << endl;
	}
	int b;
protected:
private:
};

class B1 : virtual public B//12个字节
{
public:
	int b1;
protected:
private:
};

class B2 :  public B//8个字节
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
	cout << sizeof(B) << endl;//4
	cout << sizeof(B1) << endl;//12 加上virtual以后，编译器会给变量偷偷地增加属性，所以字节就变多了
	cout << sizeof(B2) << endl;//8
	//cout << sizeof(B) << endl;

	return;
}



void main1101()
{
	C c1;
	c1.b1 = 100;
	c1.b2 = 200;
	c1.c = 300;

	//c1.b = 500;错误。 因为B1，B2都从B中继承了b，但是C虽然又多继承了B1和B2，但C不知道是从B1还是B2中继承b，这就是二义性
	//c1.b = 500;//加了virtual关键字变为虚继承，来解决继承的二义性

	cout << "hello..." << endl;
	return;
}

class D1
{
public:
	int k;
protected:
private:
};

class D2
{
public:
	int k;
protected:
private:
};

class E : public D1, public D2
{
public:
protected:
private:
};

void main1102()
{
	E e1;
	e1.D1::k = 100;//virtual关键字无法解决有两个基类的多继承，必须这样手动来区分
	e1.D2::k = 200;

	return;
}



