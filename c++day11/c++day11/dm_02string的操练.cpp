#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#include "string"
#include "algorithm"


//string的初始化
void main21()
{
	string s1 = "aaa";
	string s2 = ("bbb");
	string s3 = s2;//通过拷贝构造函数来初始化对象s3
	string s4(10, 'a');

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;

}

//string的遍历
void main22()
{
	string s1 = "abcdef";

	//数组方式
	for (unsigned int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	
	//迭代器方式
	for (string::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	
	try
	{
		for (unsigned int i = 0; i < s1.length() + 3; i++)//有意让s1.length()+3，让它出现异常
		{
			cout << s1.at(i) << " ";//at和[]的区别在于，at可以抛出异常
		}
	}
	catch (...)
	{
		cout << "发生异常\n";
	}

	cout << "at之后" << endl;
	/*
	try
	{
		for (int i = 0; i < s1.length()+3; i++)
		{
			cout << s1[i] << " ";//出现错误，不向外抛出异常，引起程序的中断
		}
	}
	catch (...)
	{
		cout << "发生异常\n";
	}*/
	return;
}

//字符指针和string的转换
void main23()
{
	string s2 = "aaabbbb";

	//1.s1===>char *
	printf("s1:%s \n", s2.c_str());//

	//2.char *====>string

	//3.s1的内容拷贝到buf中
	char buf1[128] = {0};
	s2.copy(buf1, 3, 0);//只给你拷贝3个字符，不会变成c风格的字符串；所以初始化buf1的时候都定义为0
	cout << "buf1: " << buf1 << endl;
	
	return;
}

//string字符串的连接
void main24()
{
	string s1 = "aaa";
	string s2 = "bbb";
	s1 = s1 + s2;
	cout << "s1:"<<s1 << endl;

	string s3 = "333";
	string s4 = "444";
	s3.append(s4);
	cout << "s3: " << s3 << endl;

}

//字符串的查找和替换 *重点，
void main25()
{
	string s1 = "wbm hello wbm 111 wbm 222 wbm 333";
	//查找出现wbm的index

	int index = s1.find("wbm", 0);//位置下标从0开始
	cout << "index" << index << endl;

	//案例1.求wbm出现的次数 每一次出现的数组下标
	int offindex = s1.find("wbm", 0);
	while (offindex != string::npos)//不是-1,说明找到了
	{
		cout << "offindex: " << offindex << endl;
		offindex += 1;
		offindex = s1.find("wbm", offindex);//offindex是出现的下标
	}

	//案例2. 把小写wbm替换成WBM

	string s3 = "aaa bbb ccc";
	s3.replace(0, 3, "AAA");
	cout << "s3: " << s3 << endl;

	offindex = s1.find("wbm", 0);
	while (offindex != string::npos)
	{
		cout << "offindex: " << offindex << endl;
		s1.replace(offindex,3,"WBM");
		offindex += 1;
		offindex = s1.find("wbm", offindex);//offindex是出现的下标
	}
	cout << "s1: " << s1<< endl;
}

//截断(区间删除)和插入
void main26()
{
	string s1 = "hello1 hello2 hello1";
	string::iterator it = find(s1.begin(), s1.end(), '1');//find算法返回一个迭代器的位置
	if (it != s1.end())
	{
		s1.erase(it);
	}
	cout << "删除以后的结果：" << s1 << endl;

	s1.erase(s1.begin(), s1.end());
	cout << "s1全部删除：" << s1 << endl;
	cout << "s1长度 " << s1.length() << endl;

	string s2 = "BBB";
	s2.insert(0, "AAA");//头插法，插入
	s2.insert(s2.length(), "CCC");//尾插法
	cout << s2 << endl;

}

void main27()
{
	string s1 = "AAAbbb";
	//函数的入口地址 函数对象 预定义的函数对象
	transform(s1.begin(), s1.end(),s1.begin(),toupper);//全部变大写
	cout <<"s1: "<< s1 << endl;

	string s2 = "AAAbbb";
	transform(s2.begin(), s2.end(), s2.begin(), tolower);//全部变小写
	cout << "s2: " << s2 << endl;
}

void main()
{
	//main21();
	//main22();
	//main23();
	//main24();
	//main25();
	//main26();
	 main27();
	
	return;
}