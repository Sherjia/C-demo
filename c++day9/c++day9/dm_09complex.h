#include <iostream>
using namespace std;

template <typename T>
class Complex
{
	//friend Complex<T> MySub<T>(Complex<T> &c1, Complex<T> &c2);//������Ԫ����

	friend ostream& operator<< <T>(ostream& out, Complex& c3);//��Ϊ��Ԫ��������Ϊ��<<���������ʱ��Ҫ����Complex���˽�����ԣ�a,b
public:
	Complex(T a, T b);
	void printCom();
	Complex operator+(Complex &c2);
	Complex operator-(Complex &c2);
protected:
private:
	T a;
	T b;
};