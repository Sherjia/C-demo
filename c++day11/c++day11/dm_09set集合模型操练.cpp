#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "set"
#include "functional"

//set�Ǽ��� Ԫ��Ψһ �Զ�����(Ĭ��������Ǵ�С����) ���ܰ���[]��ʽ����Ԫ��
//�����
void main91()
{
	set<int> set1;

	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();//�������һ��������
		set1.insert(tmp);
	}

	//����Ԫ�أ��ظ��ġ�����ʵֻ�����һ��100����ΪsetԪ����Ψһ��
	set1.insert(100);
	set1.insert(100);
	set1.insert(100);

	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}

	//ɾ������
	while (!set1.empty())
	{
		set<int>::iterator it = set1.begin();
		cout << *it << " ";
		set1.erase(set1.begin());
	}

	//
}

//��������������set�����Զ�����
void main92()
{
	set<int> set1; //set<int, less<int>> set1 Ĭ���Զ�����Ӵ�С
	set<int, greater<int>> set2;//�Ӵ�С

	for (int i = 0; i < 5; i++)
	{
		int tmp = rand();//�������һ��������
		set2.insert(tmp);
	}

	//�Ӵ�С
	for (set<int, greater<int>>::iterator it = set2.begin(); it != set2.end(); it++)
	{
		cout << *it << " ";
	}
}

//���ڸ�����������
class Student
{
public:
	Student(char* name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}

	char name[64];
	int age;
};

//�º��� ����ש���������ϸ��
struct FuncStuendt
{
	bool operator()(const Student &left, const Student &right)
	{
		if (left.age < right.age)//�����С���ͷ����棬���ǰ���������������
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


void main93()
{
	Student s1("S1", 31);
	Student s2("S2", 22);
	Student s3("S3", 44);
	Student s4("S4", 36);

	set<Student, FuncStuendt> set1;
	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);

	//����
	for (set<Student, FuncStuendt>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << it->age << "\t" << it->name << endl;
	}

	
}

//typedef pair<iterator, bool>_Pairib;
//����ж� sett1.insert�����ķ���ֵ
void main94()
{
	Student s1("S1", 36);
	Student s2("S2", 22);
	Student s3("S3", 44);
	Student s4("S4", 35);
	Student s5("S5", 36);//���������36�� ������ʵ�ǲ��ɹ���

	set<Student, FuncStuendt> set1;
	//���֪������Ľ��
	pair<set<Student, FuncStuendt>::iterator, bool> pair1 = set1.insert(s1);
	if (pair1.second == true)
	{
		cout << "����s1�ɹ�" << endl;
	}
	else
	{
		cout << "����s1ʧ��" << endl;
	}
	set1.insert(s2);
	pair<set<Student, FuncStuendt>::iterator, bool> pair5= set1.insert(s5);
	if (pair5.second == true)
	{
		cout << "����s5�ɹ�" << endl;
	}
	else
	{
		cout << "����s5ʧ��" << endl;
	}
	

	//����
	for (set<Student, FuncStuendt>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << it->age << "\t" << it->name << endl;
	}
}

//find equal_range 
//���ؽ����һ��pair
void main95()
{
	set<int> set1; 

	for (int i = 0; i < 10; i++)
	{
		set1.insert(i + 1);
	}

	//�Ӵ�С
	for (set<int, greater<int>>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int>::iterator it0 = set1.find(5);
	cout << "it0: " << *it0 << endl;

	int num1 = set1.count(5);
	cout << "num1:" << num1 << endl;

	set<int>::iterator it1 = set1.lower_bound(5);//���ص�һ�����ڵ���5��Ԫ�صĵ�������λ��
	cout << "it1: " << *it1<< endl;//5

	set<int>::iterator it2 = set1.upper_bound(5);//���ص�һ������5�ĵ�����λ��
	cout << "it2: " << *it2 << endl;//6
	//��5Ԫ��ɾ����
	set1.erase(5);
	//equal_range���������������б�ʾһ����ֵ�ĵ�һ�γ��������һ�γ��ֵĺ�һλ���õ����Ԫ�ص��ӷ�Χ
	pair<set<int>::iterator, set<int>::iterator> mypair = set1.equal_range(5);
	set<int>::iterator it3 = mypair.first;
	cout << "it3: " << *it3 << endl;//5 //��5Ԫ��ɾ���� 6

	set<int>::iterator it4 = mypair.second;
	cout << "it4: " << *it4 << endl;//6  //��5Ԫ��ɾ���� 6
}


void main()
{
	//main91();
	//main92();
	//main93();
	//main94();
	main95();

	cout << "hello..." << endl;
	return;
}