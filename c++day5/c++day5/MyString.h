#include <iostream>
using namespace std;


//c��û���ַ��� �ַ����ࣨc�����ַ�����
class MyString
{
	//����<<
	friend ostream& operator<<(ostream& out, MyString& s);
	//����>>
	friend istream& operator>>(istream& in, MyString &s);
public:
	MyString(int len=0);
	MyString(const char *p);
	MyString(const MyString& s);
	~MyString();
	//����=�Ų�����
	MyString& operator=(const char *p);
	MyString& operator=(const MyString& s);
	//����[]
	char& operator[](int index);
	//����==
	bool operator==(const char *p)const;//const����thisָ�룬thisָ��ָ����ڴ�ռ䲻�ܸı�
	bool operator==(const MyString& p)const;
	//����!=
	bool operator!=(const char *p)const;
	bool operator!=(const MyString& p)const;
	//����< �� > 
	int operator<(const char* p);
	int operator>(const char* p);
	int operator<(const MyString& p);
	int operator>(const MyString& p);


	//��ν����ָ�� ¶����
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