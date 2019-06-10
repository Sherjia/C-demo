#include <iostream>
using namespace std;

class Programmer
{
public:
	virtual void getSal() = 0;
};

class junior_programmer : public Programmer
{
public:
	junior_programmer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " : " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

class mid_programmer : public Programmer
{
public:
	mid_programmer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " : " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

class adv_programmer : public Programmer
{
public:
	adv_programmer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " : " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

class architect : public Programmer
{
public:
	architect(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " : " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;
};

//���㺯�� �򵥵Ŀ��
void CalProgSal(Programmer *base)
{
	base->getSal();
}

void main()
{
	junior_programmer jp("С��", "����", 4000);
	mid_programmer mp("С��", "�м�", 8600);
	adv_programmer ap("С��", "�߼�", 15000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);

	//ϵͳ��չ
	architect ar("��ˮƽѧԱ", "�ܹ�ʦ", 24000);
	CalProgSal(&ar);


	cout << "hello..." << endl;
	return;
}