#include <iostream>
using namespace std;


//c中没有字符串 字符串类（c风格的字符串）
class MyString
{
	//重载<<
	friend ostream& operator<<(ostream& out, MyString& s);
	//重载>>
	friend istream& operator>>(istream& in, MyString &s);
public:
	MyString(int len=0);
	MyString(const char *p);
	MyString(const MyString& s);
	~MyString();
	//重载=号操作符
	MyString& operator=(const char *p);
	MyString& operator=(const MyString& s);
	//重载[]
	char& operator[](int index);
	//重载==
	bool operator==(const char *p)const;//const修饰this指针，this指针指向的内存空间不能改变
	bool operator==(const MyString& p)const;
	//重载!=
	bool operator!=(const char *p)const;
	bool operator!=(const MyString& p)const;
	//重载< 和 > 
	int operator<(const char* p);
	int operator>(const char* p);
	int operator<(const MyString& p);
	int operator>(const MyString& p);


	//如何将类的指针 露出来
	char *c_str()
	{
		return m_p;
	}
	const char *c_str2()
	{
		return m_p;
	}
	int length()
	{
		return m_len;
	}
protected:
private:
	int m_len;
	char* m_p;
};