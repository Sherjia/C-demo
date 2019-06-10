#include <iostream>
using namespace std;

#include "string"
#include "set"
#include "functional"
#include <vector>
#include <algorithm>
#include <list>

//函数对象 类重载了()
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

//函数模板==函数
template <typename T>
void FuncShowElnment(T &t)
{
	cout << t << " ";
}

//普通函数
void FuncShowElnment2(int &t)
{
	cout << t << endl;
}


//函数对象定义:函数对象和普通函数的异同
void main01()
{
	int a = 10;
	ShowEle<int> showele;
	showele(a);//函数对象的执行很像一个函数，所以又叫仿函数


	FuncShowElnment<int>(a);
	FuncShowElnment2(a);

}

//函数对象属于一个类对象，能突破函数的概念，能保持调用状态信息
//函数对象的好处
//for_each算法中，函数对象做函数参数
//for_each算法中，函数对象做返回值
void main02()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	//其实for_each就是一个模板函数，将for循环语句封装起来，前面两个参数都是迭代器，
	//第三个参数是使用一个函数指针（或仿函数）,其功能是对每一个迭代器所指向的值调用仿函数。
	for_each(v1.begin(), v1.end(), ShowEle<int>());//匿名函数对象 匿名仿函数 //可以遍历v1这个容器,
												  //因为ShowEle<int>()这个仿函数的函数体实现打印操作
	cout << endl;
	for_each(v1.begin(), v1.end(), FuncShowElnment2);//通过回调函数 谁使用for_each谁去填写回调函数的入口地址

	ShowEle<int> show1;
	//函数对象show1做函数参数
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
	//1.for_each算法的函数对象的传递 是元素值传递，不是引用传递
	for_each(v1.begin(), v1.end(), show1);
	show1.printN();

	cout << "通过for_each算法的返回值看调用的次数" << endl;
	show1 = for_each(v1.begin(), v1.end(), show1);//解决方法就是把调用的次数让show1去接，把返回值传给show1
	show1.printN();

	//结论要点：分清楚 stl算法返回的值是迭代器 还是谓词(函数对象) 是STL算法的入门
	//for_each返回谓词
}

//一元谓词
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
	//find_if返回的是一个迭代器
	*/
	vector<int>::iterator it;
	it = find_if(v2.begin(), v2.end(), myDiv);//它在区间[first,end)中搜寻使一元判断式pred为true的第一个元素。
	if (it == v2.end())
	{
		cout << "容器中没有被4整除的元素" << endl;
	}
	else
	{
		cout << "第一个被4整除的元素是" <<*it<< endl;
	}
}

//二元函数对象
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
	//transform把运算结果的迭代器的开始位置返回出来
	*/
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumAdd<int>());

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;
}

//二元谓词
bool MyCompare(const int &a, const int &b)
{
	return a < b;//从小到大
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

	//和上面的for循环效果一样
	for_each(v1.begin(), v1.end(), FuncShowElnment2);
	cout << endl;
	
	//排序
	sort(v1.begin(), v1.end(), MyCompare);
	for_each(v1.begin(), v1.end(), FuncShowElnment2);
}

class CompareNoCase
{
public:
	 bool operator()(const string &str1,const string &str2)const//因为参数是const，所以 operator()也得是const，末尾有const
	{
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), tolower);//tolower是STL预定义的函数

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);//tolower是STL预定义的函数

		return (str1_ < str2_);//从小到大排列
	}
};

void main06()
{
	set<string> set1;
	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");
	set<string>::iterator it = set1.find("aaa");//find函数默认情况下是区分大小写的
	if (it == set1.end())
	{
		cout << "没有查找到aaa" << endl;
	}
	else
	{
		cout << "不区分大小写的 查找到 aaa" << endl;
	}

	set<string, CompareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");

	set<string, CompareNoCase>::iterator it1 = set2.find("aAa");
	if (it1 == set2.end())
	{
		cout << "没有查找到aaa" << endl;
	}
	else
	{
		cout << "区分大小写 查找到 aaa" << endl;
	}


}

void main()
{
	//main01();
	//main02();

	//main03();//一元谓词
	//main04();//二元函数对象 二元谓词
	//main05();//二元函数对象 二元谓词
	main06();//二元谓词在set集合中的应用

	return;
}
 