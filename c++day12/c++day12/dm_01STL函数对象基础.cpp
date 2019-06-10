#include <iostream>
using namespace std;

#include "string"
#include "set"
#include "functional"
#include <vector>
#include <algorithm>
#include <list>

//�������� ��������()
template <typename T>
class ShowEle
{
public:
	ShowEle()
	{
		n = 0;
	}
	void operator()(T &t)
	{
		n++;
		//printN();
		cout << t << " ";
	}
	void printN()
	{
		cout << "n: " << n<<endl;
	}
protected:
private:
	int n;
};

//����ģ��==����
template <typename T>
void FuncShowElnment(T &t)
{
	cout << t << " ";
}

//��ͨ����
void FuncShowElnment2(int &t)
{
	cout << t << endl;
}


//����������:�����������ͨ��������ͬ
void main01()
{
	int a = 10;
	ShowEle<int> showele;
	showele(a);//���������ִ�к���һ�������������ֽзº���


	FuncShowElnment<int>(a);
	FuncShowElnment2(a);

}

//������������һ���������ͻ�ƺ����ĸ���ܱ��ֵ���״̬��Ϣ
//��������ĺô�
//for_each�㷨�У�������������������
//for_each�㷨�У���������������ֵ
void main02()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	//��ʵfor_each����һ��ģ�庯������forѭ������װ������ǰ�������������ǵ�������
	//������������ʹ��һ������ָ�루��º�����,�书���Ƕ�ÿһ����������ָ���ֵ���÷º�����
	for_each(v1.begin(), v1.end(), ShowEle<int>());//������������ �����º��� //���Ա���v1�������,
												  //��ΪShowEle<int>()����º����ĺ�����ʵ�ִ�ӡ����
	cout << endl;
	for_each(v1.begin(), v1.end(), FuncShowElnment2);//ͨ���ص����� ˭ʹ��for_each˭ȥ��д�ص���������ڵ�ַ

	ShowEle<int> show1;
	//��������show1����������
	/*
		template<class _InIt,
	class _Fn1> inline
	_Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
	{	// perform function for each element
	_DEBUG_RANGE_PTR(_First, _Last, _Func);
	_For_each_unchecked(_Unchecked(_First), _Unchecked(_Last), _Func);
	return (_Func);
	}
	*/
	//1.for_each�㷨�ĺ�������Ĵ��� ��Ԫ��ֵ���ݣ��������ô���
	for_each(v1.begin(), v1.end(), show1);
	show1.printN();

	cout << "ͨ��for_each�㷨�ķ���ֵ�����õĴ���" << endl;
	show1 = for_each(v1.begin(), v1.end(), show1);//����������ǰѵ��õĴ�����show1ȥ�ӣ��ѷ���ֵ����show1
	show1.printN();

	//����Ҫ�㣺����� stl�㷨���ص�ֵ�ǵ����� ����ν��(��������) ��STL�㷨������
	//for_each����ν��
}

//һԪν��
template <typename T>
class IsDiv
{
public:
	IsDiv(const T &divisor)
	{
		this->divisor = divisor;
	}
	bool operator()(T &t)
	{
		return(t%divisor == 0);
	}
protected:
private:
	T divisor;
};

void main03()
{
	vector<int> v2;
	for (int i = 10; i < 33; i++)
	{
		v2.push_back(i);
	}
	int a = 4;
	IsDiv<int> myDiv(a);

	//find_if(v2.begin(), v2.end(), myDiv);

	/*
		template<class _InIt,
	class _Pr> inline
	_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
	_DEBUG_RANGE_PTR(_First, _Last, _Pred);
	return (_Rechecked(_First,
		_Find_if_unchecked(_Unchecked(_First), _Unchecked(_Last), _Pred)));
	}
	//find_if���ص���һ��������
	*/
	vector<int>::iterator it;
	it = find_if(v2.begin(), v2.end(), myDiv);//��������[first,end)����ѰʹһԪ�ж�ʽpredΪtrue�ĵ�һ��Ԫ�ء�
	if (it == v2.end())
	{
		cout << "������û�б�4������Ԫ��" << endl;
	}
	else
	{
		cout << "��һ����4������Ԫ����" <<*it<< endl;
	}
}

//��Ԫ��������
template <typename T>
class SumAdd
{
public:
	T operator()(T t1, T t2)
	{
		return t1 + t2;
	}
protected:
private:
};

void main04()
{
	//v1 v2 ==> v3
	vector<int> v1, v2;
	vector<int> v3;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);

	/*
		template<class _InIt1,
	class _InIt2,
	class _OutIt,
	class _Fn2> inline
	_OutIt transform(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
	{	// transform [_First1, _Last1) and [_First2, ...) with _Func
	_DEFINE_DEPRECATE_UNCHECKED(transform);
	_USE_DEPRECATE_UNCHECKED(_First2);
	_USE_DEPRECATE_UNCHECKED(_Dest);
	return (_Transform_no_deprecate(_First1, _Last1, _First2, _Dest, _Func));
	}
	//transform���������ĵ������Ŀ�ʼλ�÷��س���
	*/
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;
}

//��Ԫν��
bool MyCompare(const int &a, const int &b)
{
	return a < b;//��С����
}


void main05()
{
	vector<int> v1(10);

	for (int i = 0; i < 10; i++)
	{
		int tmp = rand() % 100;
		v1[i] = tmp;
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << *it << " ";
	}

	//�������forѭ��Ч��һ��
	for_each(v1.begin(), v1.end(), FuncShowElnment2);
	cout << endl;
	
	//����
	sort(v1.begin(), v1.end(), MyCompare);
	for_each(v1.begin(), v1.end(), FuncShowElnment2);
}

class CompareNoCase
{
public:
	 bool operator()(const string &str1,const string &str2)const//��Ϊ������const������ operator()Ҳ����const��ĩβ��const
	{
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), tolower);//tolower��STLԤ����ĺ���

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);//tolower��STLԤ����ĺ���

		return (str1_ < str2_);//��С��������
	}
};

void main06()
{
	set<string> set1;
	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");
	set<string>::iterator it = set1.find("aaa");//find����Ĭ������������ִ�Сд��
	if (it == set1.end())
	{
		cout << "û�в��ҵ�aaa" << endl;
	}
	else
	{
		cout << "�����ִ�Сд�� ���ҵ� aaa" << endl;
	}

	set<string, CompareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");

	set<string, CompareNoCase>::iterator it1 = set2.find("aAa");
	if (it1 == set2.end())
	{
		cout << "û�в��ҵ�aaa" << endl;
	}
	else
	{
		cout << "���ִ�Сд ���ҵ� aaa" << endl;
	}


}

void main()
{
	//main01();
	//main02();

	//main03();//һԪν��
	//main04();//��Ԫ�������� ��Ԫν��
	//main05();//��Ԫ�������� ��Ԫν��
	main06();//��Ԫν����set�����е�Ӧ��

	return;
}
 