/*
���������ȫ������Ƶ�û������ģ�������ʱһֱ�д�Ŀǰ�޷�������������󣻵�����˼����߼�����ȷ�ģ���ȫ���԰����������
2019/3/15
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//1.�����ڴ����Ԫ�ر����ܹ�������(�����ṩ�������캯��)
#include "MyVector.cpp"

//1.�Ż�Teacher�࣬ ���Ա�� char *panme�����ú������� �����ڴ�
//2.�Ż�Teacher�࣬�������� �ͷ�panmeָ����ڴ�ռ�
//3.�Ż�Teacher�࣬����ǳ���� ����= ��д�������캯��
//4.�Ż�Teacher�࣬ ��Teacher��������<<
//5.��ģ�������У��� int char Teacher Teacher*(ָ������)

//=====>stl ��������


class Teacher
{
public:
	Teacher()
	{
		age = 33;
		m_p = new char[1];
		strcpy(m_p, "");
	}
	Teacher(char *name, int age)
	{
		this->age = age;
		m_p = new char[strlen(name) + 1];
		strcpy(m_p, name);
	}
	Teacher(const Teacher& obj)
	{
		m_p = new char[strlen(obj.m_p) + 1];
		strcpy(m_p, obj.m_p);
		age = obj.age;
	}
	~Teacher()
	{
		if (m_p != NULL)
		{
			delete m_p;
			m_p = NULL;
		}
	}
	void printT()
	{
		cout << m_p << "��" << age << endl;
	}

	//����<<
	friend ostream& operator<<(ostream& out, Teacher &t);
	//����=
	Teacher& operator=(const Teacher &obj)
	{
		//1.�ж�ԭ���Ŀռ��ڴ��Ƿ��ͷ�
		if (m_p != NULL)
		{
			delete[] m_p;
			m_p = NULL;
			age = 33;
		}
		//2.����obj�����µ��ڴ�ռ�
		m_p = new char[strlen(obj.m_p) + 1];
		age = obj.age;
		//3.��������
		strcpy(m_p, obj.m_p);
		
		return *this;
	}
protected:
private:
	int age;
	//char name[32];
	char *m_p;
};
//����<<
ostream& operator<<(ostream& out, Teacher &t)
{
	out << t.age << ", " << t.m_p << endl;
	return out;
}
void main()
{
	Teacher t1("t1", 31), t2("t2", 32), t3("t3", 33), t4("t4", 34);

	MyVetcor<Teacher*> tArray[4];

	tArray[0] = &t1;
	tArray[1] = &t2;
	tArray[2] = &t3;
	tArray[3] = &t4;

	for (int i = 0; i < 4; i++)
	{
		Teacher *tmp = tArray[i];
		tmp->printT();
	}

}

void main03()
{
	Teacher t1("t1", 31), t2("t2", 32), t3("t3", 33), t4("t4", 34);
	
	MyVetcor<Teacher> tArray[4];

	tArray[0] = t1;
	tArray[1] = t2;
	tArray[2] = t3;
	tArray[3] = t4;

	for (int i = 0; i < 4; i++)
	{
		Teacher tmp = tArray[i];
		tmp.printT();
	}

}


void main02()
{
	MyVetcor<char> myv1(10);
	myv1[0] = 'a';
	myv1[1] = 'b';
	myv1[2] = 'c';
	myv1[3] = 'd';

	cout << myv1;
}

void main01()
{
	MyVetcor<int> myv1(10);

	for (int i = 0; i < myv1.getLen(); i++)
	{
		myv1[i] = i + 1;
		cout << myv1[i] << " ";
	}
	cout << endl;

	MyVetcor<int> myv2 = myv1;
	
	for (int i = 0; i < myv2.getLen(); i++)
	{
		myv1[i] = i + 1;
		cout << myv2[i] << " ";
	}
	cout << myv2 << endl;
	ostream& operator<<(ostream& out, const MyVetcor<int> &obj);



	cout << "hello..." << endl;
	return;
}