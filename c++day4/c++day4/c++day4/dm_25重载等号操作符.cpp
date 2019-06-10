#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class Name
{
public:
	Name(const char*myp)
	{
		m_len = strlen(myp);
		m_p = (char*)malloc(m_len + 1);
		strcpy(m_p, myp);
	}
	//解决方案，手动编写一个拷贝构造函数，使用深拷贝
	Name(const Name& obj1)
	{
		m_len = obj1.m_len;
		m_p = (char*)malloc(m_len + 1);//给它手动分配一块空间
		strcpy(m_p, obj1.m_p);
	}
	Name& operator=(Name &obj1)//函数返回一个引用，可以支持链式编程这种obj1 = obj2 = obj3;
	{
		//先把旧的内存释放掉
		if (this->m_p != 0)
		{
			delete[] m_p;
			m_len = 0;
		}
		//根据obj1分配内存大小
		this->m_len = obj1.m_len;
		this->m_p = new char[m_len + 1];
		
		//把obj1复制
		strcpy(m_p, obj1.m_p);
		return *this;
	}
	~Name()
	{
		if (m_p != NULL)
		{
			free(m_p);
			m_p = NULL;
			m_len = 0;
		}
	}
private:
	char *m_p;
	int m_len;
protected:
};


void objplaymain()
{

	Name obj1("abcdef");

	Name obj2 = obj1;//默认的拷贝构造函数,编译器提供的，因为我们没写；但执行的是浅拷贝:只拷贝指针的值，没拷贝指针指向内存空间的值
	//解决方案，手动编写一个拷贝构造函数，使用深拷贝

	Name obj3("obj3");
	obj1 = obj2 = obj3;//等号操作，编译器把对象1的属性拷贝成对象3的属性，这是浅拷贝；和初始化是不同的概念。解决方法是重载等号操作符，后面讲
	//obj3.operator=(obj);
	//operator=(Name &obj1);


	cout << "hello..." << endl;
	return;
}

void main()
{

	objplaymain();
	cout << "hello..." << endl;
	return;
}
/*结论 1.要先把旧的内存释放掉
	   2.返回一个引用
*/
