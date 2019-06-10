#include <iostream>
using namespace std;

#include "string"
#include "set"
#include "functional"
#include <vector>
#include <algorithm>
#include <list>

//Ԥ����õĺ�����������ʵ�ֲ�ͬ���͵����ݵļӷ�����
//ʵ�����������ͺ��㷨�ķ���===��ͨ������������ʵ�ֵ�

//˼�������֪��plus<type> ����������
void main21()
{
	/*
		template<class _Ty = void>
	struct plus
	{	// functor for operator+
	typedef _Ty first_argument_type;
	typedef _Ty second_argument_type;
	typedef _Ty result_type;

	constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	// apply operator+ to operands
		return (_Left + _Right);
		}
	};
	*/
	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z= intAdd(x, y);//x+y
	cout << "z: " << z << endl;

	plus<string>stringAdd;

	string s1 = "aaa";
	string s2 = "bbb";
	string s3 = stringAdd(s1, s2);
	cout << "s3:" << s3 << endl;

	vector<string> v1;
	v1.push_back("bbb");
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("zzz");
	v1.push_back("ccc");
	v1.push_back("ccc");

	sort(v1.begin(), v1.end(), greater<string>());
	for (vector<string>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << *it << " ";
	}

	//��ccc���ֵĸ���
	string sc = "ccc";

	//equal_to<string>()���������� left������������ right��������sc
	//bind2nd���Ǻ���������, ��Ԥ���庯������͵ڶ������������˰�
	int num = count_if(v1.begin(), v1.end(),bind2nd (equal_to<string>(),sc));
	cout << "num: " << num << endl;
}
class IsGreat
{
public:
	IsGreat(int i)
	{
		m_num = i;
	}
	bool operator()(int &num)
	{
		if (num > m_num)
		{
			return true;
		}
		return false;
	}
private:
	int m_num;
};

void main22()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i+1);
	}
	for (vector<int>::iterator it = v1.begin(); it !=v1.end(); ++it)
	{
		cout << *it << endl;
	}

	int num1 = count(v1.begin(), v1.end(), 3);
	cout << "num1: " << num1 << endl;

	//ͨ��ν�������2�ĸ���
	int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
	cout << "num2: " << num2 << endl;


	/*
		template<class _Fn2,
	class _Ty> inline
	binder2nd<_Fn2> bind2nd(const _Fn2& _Func, const _Ty& _Right)
	{	// return a binder2nd functor adapter
	typename _Fn2::second_argument_type _Val(_Right);
	return (binder2nd<_Fn2>(_Func, _Val));
	}
	*/
	//ͨ��Ԥ���庯�������2�ĸ���
	//bind2nd ���������� ���������������Ԫ�أ��Ҳ����̶���2 
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(),2));
	cout << "num3: " << num3 << endl;

	//�������ĸ���
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "�����ĸ���num4: " << num4 << endl;

	//��ż���ĸ���
	int num5 = count_if(v1.begin(), v1.end(),not1( bind2nd(modulus<int>(), 2)));
	cout << "ż���ĸ���num5: " << num5 << endl;
}

void main()
{
	//main21();
	main22();//����֧�����ۺϰ���
	
	return;
}