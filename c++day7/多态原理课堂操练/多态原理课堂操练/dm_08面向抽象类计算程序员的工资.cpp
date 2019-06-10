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

//计算函数 简单的框架
void CalProgSal(Programmer *base)
{
	base->getSal();
}

void main()
{
	junior_programmer jp("小王", "初级", 4000);
	mid_programmer mp("小张", "中级", 8600);
	adv_programmer ap("小李", "高级", 15000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);

	//系统扩展
	architect ar("高水平学员", "架构师", 24000);
	CalProgSal(&ar);


	cout << "hello..." << endl;
	return;
}