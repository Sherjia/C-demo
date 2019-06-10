#include <iostream>
using namespace std;
#include "MyString.h"
#pragma warning(disable:4996)

void main01()
{

	MyString s1;
	MyString s2("s2");
	MyString s2_2 = NULL;//如果传了空指针，那么就用带参数的构造函数传递一个空串
	MyString s3 = s2;
	MyString s4 = "s444444444";

	//测试运算符重载
	//重载=

	s4 = s2;
	s4 = "s2222";

	//MyString& operator=(const char *p);
	//MyString& operator=(const MyString& s);

	//重载[]
	s4[1] = '4';
	printf("%c", s4[1]);//%c表示字符，%s表示字符串
	//char& operator[](int index);

	//重载<< 且只能写成友元函数进行重载
	cout << s4 << endl;
	//ostream& operator<<(ostream& out, MyString& s);ostream& out是左操作数， MyString& s是右操作数
	//最后要支持链式编程，所以返回引用，ostream&


	cout << "hello..." << endl;
	return;
}
void main02()
{
	MyString s1;
	MyString s2("s2");
	
	//重载==
	//bool operator==(const char *p);
	//bool operator==(const MyString& p);
	
	if (s2 == "s222222")
	{
		printf("相等");
	}
	else
	{
		printf("不相等");
	}

	MyString s3 = s2;
	if (s3 == s2)
	{
		printf("相等");
	}
	else
	{
		printf("不相等");
	}
	//重载!=
	//bool operator!=(const char *p);
	//bool operator!=(const MyString& p);
	if (s2 != "s222222")
	{
		printf("不相等");
	}
	else
	{
		printf("相等");
	}

	MyString s4 = s3;
	if (s4 != s3)
	{
		printf("不相等");
	}
	else
	{
		printf("相等");
	}
}
void main03()
{
	MyString s1;
	MyString s2("s2");
	MyString s3 = s2;
	s3 = "aaa";

	//重载< 和 > 
	//int operator<(const char* p);
	//int operator>(const char* p);
	//int operator<(const MyString& p);
	//int operator>(const MyString& p);
	int tag = (s3 < "bbbb");
	if (tag < 0)
	{
		printf("a3 小于 bbbb");
	}
	else
	{
		printf("a3 大于 bbbb");
	}
	cout << endl;
	
	int tag1 = (s3 < s2);
	if (tag1 < 0)
	{
		printf("a3 小于 s2");
	}
	else
	{
		printf("a3 大于 s2");
	}
	cout << endl;
	
	//其他技巧，如何把私有属性露出来以便于访问
	MyString s4 = "aaaaffff";
	strcpy(s4.c_str(), "aa111");
	cout << s4 << endl;

}

void main()
{
	MyString s1(128);
	cout << "\n请输入字符串（回车结束）";
	//重载>>
	cin >> s1;
	//istream& operator>>(istream& in, MyString &s1);

	cout << s1;

	return;
}