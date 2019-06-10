#include <iostream>
using namespace std;

template <typename T>
class MyVetcor
{
	friend ostream& operator<< <T>(ostream& out, const MyVetcor<T> &obj);//声明的时候operator<<后面加<T>别忘了
public:
	MyVetcor(int size = 0);//构造函数
	MyVetcor(const MyVetcor &obj);//拷贝构造函数
	~MyVetcor();//析构函数

	T& operator[](int index);//a1.operator[i]函数返回值当左值，需要返回一个引用(元素本身，而不是一个值)，还是要支持链式编程
	//a3 = a2 = a1;
	MyVector& operator=(const MyVetcor &obj);//函数返回值当左值，需要返回一个引用(元素本身，而不是一个值)，还是要支持链式编程

	int getLen()
	{
		return size;
	}
protected:
	T *m_space;
	T m_len;
	int size;
private:
};