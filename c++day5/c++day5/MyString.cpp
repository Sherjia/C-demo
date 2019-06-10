#include "MyString.h"
#pragma warning(disable:4996)


MyString::MyString(int len)
{
	if (len == 0)
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p,"");
	}
	else
	{
		m_len = len;
		m_p = new char[m_len + 1];
		memset(m_p, 0, m_len);//作用是将某一块内存中的内容全部设置为指定的值， 这个函数通常为新申请的内存做初始化工作。
							  //将m_p的内容全部变为空（0），m_p的长度为m_len
	}
	
}
MyString::MyString(const char *p)
{
	if (p == NULL)//MyString s2_2 = NULL;
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];
		strcpy(m_p, p);
	}
}
//拷贝构造函数 MyString s3 = s2;
MyString::MyString(const MyString& s)
{
	m_len = s.m_len;
	m_p = new char[m_len + 1];//不能写成 m_p = s.m_p 要重新分配内存，不是把s的内存地址赋给新对象 
	strcpy(m_p, s.m_p);
}
MyString::~MyString()
{
	if (m_p != NULL)
	{
		delete []m_p;
		m_p = NULL;//避免出现野指针
		m_len = 0;
	}
}

//重载<<
ostream& operator<<(ostream& out, MyString& s)
{
	out << s.m_p;
	return out;
}

//重载>>
istream& operator>>(istream& in, MyString &s)
{
	in >> s.m_p;
	return in;
}

//重载=号 s4 = "s2222";
MyString& MyString::operator=(const char *p)
{
	//旧的内存释放掉
	if (this->m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}
	//根据p分配内存，并且拷贝内容
	if (p == NULL)//如果p是个空串
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];//+1是因为char*是以/0结尾的
		strcpy(m_p, p);
	}
	return *this;
}
//重载=号 s3 = s2
MyString& MyString::operator=(const MyString& s)
{
	//旧的内存释放掉
	if (this->m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}
	//根据s分配内存，并且拷贝内容
	m_len = s.m_len;
	m_p = new char[m_len + 1];//+1是因为char*是以/0结尾的
	strcpy(m_p, s.m_p);
	
		return *this;
}
//重载[]
char& MyString::operator[](int index)
{
	return m_p[index];
}

//重载== 返回值类型都是bool，所以返回值必须是true,才会执行第一种判断情况
//if (s2 == "s222222")
bool MyString::operator==(const char *p)const
{
	if (p == NULL)//p有可能是空串
	{
		if (m_len == 0)//若本体长度也是0，那么肯定和空串p相等
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (m_len == strlen(p))
		{
			return !strcmp(m_p, p);//设这两个字符串为str1，str2，若str1 = str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数。
		}
		else
		{
			return false;
		}
	}
}
bool MyString::operator==(const MyString& p)const
{
	if (m_len != p.m_len)
	{
		return false;
	}
	return !strcmp(m_p, p.m_p);
}
//重载!=
//if (s2 != "s222222")
bool MyString::operator!=(const char *p)const
{
	return !(*this == p);//因为上面已经重载过==了，所以可以直接用
}
bool MyString::operator!=(const MyString& p)const
{
	return !(*this == p);//return ture
}

//重载< 和 > 
//int tag = (s3 < "bbbb"); if (tag < 0)
int MyString::operator<(const char* p)
{
	return strcmp(this->m_p, p);
}

int MyString::operator>(const char* p)
{
	return strcmp(p, this->m_p);
}
//int tag1 = (s3 < s2);if (tag1 < 0)
int MyString::operator<(const MyString& p)
{
	return strcmp(this->m_p, p.m_p);
}

int MyString::operator>(const MyString& p)
{
	return strcmp(p.m_p, this->m_p);
}
