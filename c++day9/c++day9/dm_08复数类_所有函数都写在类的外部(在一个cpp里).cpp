#include <iostream>
using namespace std;


template <typename T>
class Complex;//类的前置声明

template <typename T>
Complex<T> MySub(Complex<T> &c1, Complex<T> &c2);

template <typename T>
class Complex
{
	friend Complex<T> MySub<T>(Complex<T> &c1, Complex<T> &c2);//滥用友元函数

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

//构造函数写在了类的外部
template <typename T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

template <typename T>
void Complex<T>::printCom()
{
	cout << "a" << a << " b" << b << endl;
}

//本质是 模板是两次 编译生成的 第一此生成的是函数头 和第二次生产的函数头不一样 
//成员函数 实现+运算符重载
template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c2)//注意此时函数的返回值需要<T>，因为返回的是一个元素；函数的参数也需要<T>
{
	Complex tmp(a + c2.a, b + c2.b);//Complex<T> tmp(a + c2.a, b + c2.b);里面的参数化列表<T>可以不加，因为外面已经加了
	return tmp;
}

//成员函数 实现-运算符重载
template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c2)
{
	Complex tmp(a - c2.a, b - c2.b); //Complex tmp(this->a - c2.a, this->b - c2.b);
	return tmp;
}

/*
dm_08复数类_所有函数都写在类的外部(在一个cpp里).obj : error LNK2019: 无法解析的外部符号
"class std::basic_ostream<char,struct std::char_traits<char> > & __cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> > &,class Complex<int> &)" (??6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@AAV?$Complex@H@@@Z)
该符号在函数 _main 中被引用

解决方法是在类中的函数声明中的左移运算符<<右边加上参数化列表<T>,就是13行那样
*/
//友元函数 实现<<运算符重载
template <typename T>
ostream& operator<<(ostream& out, Complex<T>& c3)
{
	out << c3.a << " + " << c3.b << "i" << endl;
	return out;
}

////////////////////////////////////////////////////////////////////
//滥用友元函数 会报错
//解决方法有截图 就是5—9行以及14行的写法；但是并不会解决所有滥用友元函数的问题
template <typename T>
Complex<T> MySub(Complex<T> &c1, Complex<T> &c2)//滥用友元函数
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
//结论：不要滥用友元函数



//运算符重载的正规写法
//重载<<和>>只能用友元函数，其他运算符重载，都要写为成员函数,不要滥用友元函数
/*
ostream& operator<<(ostream& out, Complex& c3)
{
out << "a: " << c3.a << " b:" << c3.b << endl;
return out;
}
*/
void main()
{
	//需要把模板类具体化以后，才能定义对象， c++编译器需要分配内存
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;
	//Complex operator+(Complex &c2);成员函数实现+号运算符重载

	cout << c3 << endl;
	//ostream& operator<<(ostream& out, Complex& c3);<<只能用全局函数实现重载，并且还要设定为类的友元函数

	//滥用友元函数
	{
		Complex<int> c4 = MySub(c1, c2);
		cout << c4 << endl;
	}

	cout << "hello..." << endl;
	return;
}