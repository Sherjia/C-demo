#include <iostream>
using namespace std;
#include "MyString.h"
#pragma warning(disable:4996)

void main01()
{

	MyString s1;
	MyString s2("s2");
	MyString s2_2 = NULL;//������˿�ָ�룬��ô���ô������Ĺ��캯������һ���մ�
	MyString s3 = s2;
	MyString s4 = "s444444444";

	//�������������
	//����=

	s4 = s2;
	s4 = "s2222";

	//MyString& operator=(const char *p);
	//MyString& operator=(const MyString& s);

	//����[]
	s4[1] = '4';
	printf("%c", s4[1]);//%c��ʾ�ַ���%s��ʾ�ַ���
	//char& operator[](int index);

	//����<< ��ֻ��д����Ԫ������������
	cout << s4 << endl;
	//ostream& operator<<(ostream& out, MyString& s);ostream& out����������� MyString& s���Ҳ�����
	//���Ҫ֧����ʽ��̣����Է������ã�ostream&


	cout << "hello..." << endl;
	return;
}
void main02()
{
	MyString s1;
	MyString s2("s2");
	
	//����==
	//bool operator==(const char *p);
	//bool operator==(const MyString& p);
	
	if (s2 == "s222222")
	{
		printf("���");
	}
	else
	{
		printf("�����");
	}

	MyString s3 = s2;
	if (s3 == s2)
	{
		printf("���");
	}
	else
	{
		printf("�����");
	}
	//����!=
	//bool operator!=(const char *p);
	//bool operator!=(const MyString& p);
	if (s2 != "s222222")
	{
		printf("�����");
	}
	else
	{
		printf("���");
	}

	MyString s4 = s3;
	if (s4 != s3)
	{
		printf("�����");
	}
	else
	{
		printf("���");
	}
}
void main03()
{
	MyString s1;
	MyString s2("s2");
	MyString s3 = s2;
	s3 = "aaa";

	//����< �� > 
	//int operator<(const char* p);
	//int operator>(const char* p);
	//int operator<(const MyString& p);
	//int operator>(const MyString& p);
	int tag = (s3 < "bbbb");
	if (tag < 0)
	{
		printf("a3 С�� bbbb");
	}
	else
	{
		printf("a3 ���� bbbb");
	}
	cout << endl;
	
	int tag1 = (s3 < s2);
	if (tag1 < 0)
	{
		printf("a3 С�� s2");
	}
	else
	{
		printf("a3 ���� s2");
	}
	cout << endl;
	
	//�������ɣ���ΰ�˽������¶�����Ա��ڷ���
	MyString s4 = "aaaaffff";
	strcpy(s4.c_str(), "aa111");
	cout << s4 << endl;

}

void main()
{
	MyString s1(128);
	cout << "\n�������ַ������س�������";
	//����>>
	cin >> s1;
	//istream& operator>>(istream& in, MyString &s1);

	cout << s1;

	return;
}