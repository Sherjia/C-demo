#include <iostream>
#include <stdlib.h>
using namespace std;

namespace A
{
	int x = 2;
	void fun()
	{
		cout <<"A"<<endl;
	}
}

namespace B
{
	int x = 3;
	void fun2()
	{
		cout <<"B"<<endl;
	}
}

int main (void)
{
	cout <<A::x<<endl;
	B::fun2();
	system("pause");
	return 0;
}