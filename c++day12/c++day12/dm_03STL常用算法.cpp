#include <iostream>
using namespace std;

#include "string"
#include "set"
#include "functional"
#include <vector>
#include <algorithm>
#include <list>
#include "iterator"
#include <numeric>

void printV(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
}

void printList(list<int> &v)
{
	for (list<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
}

void showele(int &n)
{
	cout << n << " ";
}

class CMyShow
{
public:
	CMyShow()
	{
		num = 0;
	}
	void operator()(int &n)
	{
		num++;
		cout << n << " ";
	}
	void printNum()
	{
		cout << "num: " << num << endl;
	}
protected:
private:
	int num;
};

void main41_foreach()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);

	//�ص���������ڵ�ַ
	for_each(v1.begin(), v1.end(), showele);

	//�������󣬹���Ч��ͬ��
	//CMyShow()������������������Ҫ��my1ȥ����������������������ھʹ�������һ�䣬�������������num:0
	CMyShow my1 = for_each(v1.begin(), v1.end(), CMyShow());
	my1.printNum();
}

int increase(int i)
{
	return i + 100;
}

void main42_transform()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);

	//ʹ���˻ص�����
	transform(v1.begin(), v1.end(), v1.begin(), increase);
	printV(v1);

	//ʹ��Ԥ����ĺ�������
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
	printV(v1);

	//ʹ�ú����������ͺ�������
	list<int> mylist;
	mylist.resize(v1.size());
	transform(v1.begin(), v1.end(), mylist.begin(),bind2nd(multiplies<int>(),10));//functor for operator*
	printList(mylist);
	cout << endl;

	//transformҲ���԰������� ֱ���������Ļ
	transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "), negate<int>());
}

int showele2(int n)
{
	cout << n << " ";
	return n;
}

void main43_transform_pk_foreach()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2 = v1;

	//һ������£�for_each��ʹ�õĺ������󣬲��������ã�û�з���ֵ���ٶȿ죬�����
	for_each(v1.begin(), v1.end(), showele);//
	
	//��ʹ�õĺ������󣬲���һ�㲻ʹ�����ã����һ��з���ֵ����for_each��ͬ���ٶ������ǳ���
	transform(v2.begin(), v2.end(),v2.begin(), showele2);

}

void main44_adjacent_find()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);

	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if (it == v1.end())
	{
		cout << "û���ҵ��ظ���Ԫ��" << endl;
	}
	else
	{
		cout << *it << endl;
	}
	int index = distance(v1.begin(), it);
	cout << index << endl;
}
//���ַ�����
void main45_binary_search()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);

	bool b = binary_search(v1.begin(), v1.end(), 7);
	if (b == true)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
	
}

void main46_count()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);	
	v1.push_back(9);
	v1.push_back(9);

	int num = count(v1.begin(), v1.end(), 9);
	cout << "num: " << num << endl;
}

bool GreatThree(int iNum)
{
	if (iNum > 3)
	{
		return true;
	}
	return false;
}

void main47_count_if()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(9);

	int num = count_if(v1.begin(), v1.end(), GreatThree);//GreatThree�Ǹ�ν��
	cout << "num: " << num << endl;
}

void main48_find()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(9);

	vector<int>::iterator it =find(v1.begin(), v1.end(), 3);
	cout << *it << endl;
}

void main49_find_if()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(9);

	//��һ������5��λ��
	vector<int>::iterator it2 = find_if(v1.begin(), v1.end(), GreatThree);
	cout << *it2 << endl;
}

//�����㷨
void main_merge()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);
}

//����
class Student
{
public:
	Student(string name, int id)
	{
		m_name = name;
		m_id = id;
	}
	void printT()
	{
		cout << "name: "<<m_name << " ID: "<<m_id<<endl;
	}
public:	
	string m_name;
	int m_id;	
};

bool CompareS(Student &s1, Student &s2)
{
	return (s1.m_id < s2.m_id);
}

void main_sort()
{
	Student s1("�ϴ�", 1);
	Student s2("�϶�", 2);
	Student s3("����", 3);
	Student s4("����", 4);
	vector<Student> v1;
	v1.push_back(s4);
	v1.push_back(s1);
	v1.push_back(s2);
	v1.push_back(s3);

	for (vector<Student>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		it->printT();
	}
	cout << endl;
	
	//sort�����Զ��庯������ �����Զ����������͵�����
	//�滻 �㷨��ͳһ��(ʵ�ֵ��㷨���������͵ķ���)===>�����ֶκ�������
	sort(v1.begin(), v1.end(), CompareS);
	for (vector<Student>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		it->printT();
	}
	
}

//�������˳��
void main_random_shuffle()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	random_shuffle(v1.begin(), v1.end());

	string str = "abcdfrg";
	random_shuffle(str.begin(), str.end());
	cout << "str: " << str << endl;
	
	printV(v1);
}

//����
void main_reverse()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	reverse(v1.begin(), v1.end());
	printV(v1);
}

void main_copy()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2;
	v2.resize(v1.size());

	copy(v1.begin(), v1.end(), v2.begin());
	printV(v2);
}

bool great_equal_5(int &n)
{
	if (n >= 5)
	{
		return true;
	}
	return false;
}

void main_replace()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(3);
	replace(v1.begin(), v1.end(), 3, 8);
	printV(v1);

	replace_if(v1.begin(), v1.end(), great_equal_5, 6);
	printV(v1);
}

void main_swap()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	swap(v1, v2);
	printV(v1);
}

void main55_accumulate()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	int tmp = accumulate(v1.begin(), v1.end(), 100);//�����ǵü�ͷ�ļ� #include <numeric>
	cout << tmp << endl;
}

void main56_fill()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	fill(v1.begin(), v1.end(), 8);
	printV(v1);
}

void main57_union()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(9);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printV(v3);
}

void main()
{
	//main41_foreach();
	//main42_transform();
	//main43_transform_pk_foreach();
	//main44_adjacent_find();
	//main45_binary_search();
	//main46_count();
	//main47_count_if();
	//main48_find();
	//main49_find_if();


	//main_merge();
	//main_sort();
	//main_random_shuffle();
	//main_reverse();


	//main_copy();
	//main_replace();
	//main_swap();

	//main55_accumulate();
	//main56_fill();

	main57_union();

	return;
}