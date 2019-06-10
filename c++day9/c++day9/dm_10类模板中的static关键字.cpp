/*
函数模板机制结论
编译器并不是把模板函数处理成能够处理任意类的函数
编译器从函数模板通过具体类型产生不同的函数
编译器会对函数模板进行两次编译：
1.在声明的地方对模板代码本身进行编译 2.在调用的地方对参数替换后的代码进行编译
*/

#include <iostream>
using namespace std;

template <typename T>
class AA
{
public:
	static T m_a;
protected:
private:
};

template <typename T>
T AA<T>::m_a = 0;

void main()
{
	AA<int> a1, a2, a3;
	a1.m_a = 10;
	a2.m_a++;
	a3.m_a++;
	cout << AA<int>::m_a << endl;

	AA<char> b1, b2, b3;
	b1.m_a = 'a';
	b2.m_a++;
	b3.m_a++;
	cout << AA<char>::m_a << endl;

	//静态变量m_a应该是每一种类型的类使用自己的m_a

	cout << "hello..." << endl;
	return;
}
