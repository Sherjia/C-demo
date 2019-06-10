#include <iostream>
using namespace std;

template <typename T>
class Complex
{
	//friend Complex<T> MySub<T>(Complex<T> &c1, Complex<T> &c2);//滥用友元函数

	friend ostream& operator<< <T>(ostream& out, Complex& c3);//变为友元函数，因为做<<运算符重载时，要访问Complex类的私有属性：a,b
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