#include <iostream>
using namespace std;

inline void printA()
{
	int a = 10;
	cout << "a" << a << endl;

}

void main101()
{
	printA();
	cout << "hello..." << endl;
	return;
}
//�������ĺ�
#define NYFUNC(a,b)((a) < (b) ? (a) : (b))

inline int myfunc(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int a = 1;
	int b = 3;
	//int c = NYFUNC(++a, b); ���滻��չ�� ����++a��< (b) ? (++a) : (b)�� a=3,b=3,c=3
	int c = myfunc(++a,b);//a=2,b=3,c=2 ���Ľ����ͬ

	printf("a = %d \n", a);
	printf("b = %d \n", b);
	printf("c = %d \n", c);

	return 0;
}