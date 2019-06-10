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
	//����������ֶ���дһ���������캯����ʹ�����
	Name(const Name& obj1)
	{
		m_len = obj1.m_len;
		m_p = (char*)malloc(m_len + 1);//�����ֶ�����һ��ռ�
		strcpy(m_p, obj1.m_p);
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

	//Name obj2 = obj1;//Ĭ�ϵĿ������캯��,�������ṩ�ģ���Ϊ����ûд����ִ�е���ǳ����:ֻ����ָ���ֵ��û����ָ��ָ���ڴ�ռ��ֵ
					 //����������ֶ���дһ���������캯����ʹ�����

	Name obj3("obj3");
	obj3 = obj1;//�ȺŲ������������Ѷ���1�����Կ����ɶ���3�����ԣ�����ǳ�������ͳ�ʼ���ǲ�ͬ�ĸ��������������صȺŲ����������潲

	cout << "hello..." << endl;
	return;
}

void main()
{

	objplaymain();
	cout << "hello..." << endl;
	return;
}