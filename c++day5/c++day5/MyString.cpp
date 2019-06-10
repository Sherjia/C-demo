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
		memset(m_p, 0, m_len);//�����ǽ�ĳһ���ڴ��е�����ȫ������Ϊָ����ֵ�� �������ͨ��Ϊ��������ڴ�����ʼ��������
							  //��m_p������ȫ����Ϊ�գ�0����m_p�ĳ���Ϊm_len
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
//�������캯�� MyString s3 = s2;
MyString::MyString(const MyString& s)
{
	m_len = s.m_len;
	m_p = new char[m_len + 1];//����д�� m_p = s.m_p Ҫ���·����ڴ棬���ǰ�s���ڴ��ַ�����¶��� 
	strcpy(m_p, s.m_p);
}
MyString::~MyString()
{
	if (m_p != NULL)
	{
		delete []m_p;
		m_p = NULL;//�������Ұָ��
		m_len = 0;
	}
}

//����<<
ostream& operator<<(ostream& out, MyString& s)
{
	out << s.m_p;
	return out;
}

//����>>
istream& operator>>(istream& in, MyString &s)
{
	in >> s.m_p;
	return in;
}

//����=�� s4 = "s2222";
MyString& MyString::operator=(const char *p)
{
	//�ɵ��ڴ��ͷŵ�
	if (this->m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}
	//����p�����ڴ棬���ҿ�������
	if (p == NULL)//���p�Ǹ��մ�
	{
		m_len = 0;
		m_p = new char[m_len + 1];
		strcpy(m_p, "");
	}
	else
	{
		m_len = strlen(p);
		m_p = new char[m_len + 1];//+1����Ϊchar*����/0��β��
		strcpy(m_p, p);
	}
	return *this;
}
//����=�� s3 = s2
MyString& MyString::operator=(const MyString& s)
{
	//�ɵ��ڴ��ͷŵ�
	if (this->m_p != NULL)
	{
		delete[] m_p;
		m_len = 0;
	}
	//����s�����ڴ棬���ҿ�������
	m_len = s.m_len;
	m_p = new char[m_len + 1];//+1����Ϊchar*����/0��β��
	strcpy(m_p, s.m_p);
	
		return *this;
}
//����[]
char& MyString::operator[](int index)
{
	return m_p[index];
}

//����== ����ֵ���Ͷ���bool�����Է���ֵ������true,�Ż�ִ�е�һ���ж����
//if (s2 == "s222222")
bool MyString::operator==(const char *p)const
{
	if (p == NULL)//p�п����ǿմ�
	{
		if (m_len == 0)//�����峤��Ҳ��0����ô�϶��Ϳմ�p���
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
			return !strcmp(m_p, p);//���������ַ���Ϊstr1��str2����str1 = str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�������
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
//����!=
//if (s2 != "s222222")
bool MyString::operator!=(const char *p)const
{
	return !(*this == p);//��Ϊ�����Ѿ����ع�==�ˣ����Կ���ֱ����
}
bool MyString::operator!=(const MyString& p)const
{
	return !(*this == p);//return ture
}

//����< �� > 
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
