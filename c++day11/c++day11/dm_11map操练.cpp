#include <iostream>
using namespace std;
#include "map"
#include "string"

//map元素的添加/遍历/删除基本操作
void main1101()
{
	map<int, string> map1;

	//方法1
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	//方法2
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));

	//方法3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	//方法4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << "\t" << endl;
	}
	cout << "遍历结束" << endl;

	//容器删除元素
	while (!map1.empty())
	{
		map<int, string>::iterator it = map1.begin();
		cout << it->first << "\t" << it->second << "\t" << endl;
		map1.erase(it);
	}

}

//四种插入方法的异同
//前三种方法返回的是pair<iterator,bool> 若key已经存在，则报错
//第四种方法若key已经存在，则覆盖前一个
void main1102()
{
	map<int, string> map1;

	//typedef pair<iterator, bool>_Pairib;

	//方法1
	pair<map<int, string>::iterator, bool> mypair1 = map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	//方法2
	pair<map<int, string>::iterator, bool> mypair3 = map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));

	//方法3
	pair<map<int, string>::iterator, bool> mypair5 = map1.insert(map<int, string>::value_type(5, "teacher05"));
	if (mypair5.second != true)//pair来判断是否插入成功
	{
		cout << "key5插入失败" << endl;
	}
	else
	{
		cout << mypair5.first->first << "\t" << mypair5.first->second << endl;
	}
	pair<map<int, string>::iterator, bool> mypair6 = map1.insert(map<int, string>::value_type(5, "teacher55"));
	if (mypair6.second != true)
	{
		cout << "key6插入失败" << endl;
	}
	else
	{
		cout << mypair6.first->first << "\t" << mypair6.first->second << endl;
	}

	//方法4
	map1[7] = "teacher07";
	map1[7] = "teacher77";//它会将map1[7] = "teacher07";覆盖

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << "\t" << endl;
	}
	cout << "遍历结束" << endl;
}

void main1103()
{
	map<int, string> map1;

	//方法1
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	//方法2
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));

	//方法3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	//方法4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << "\t" << endl;
	}
	cout << "遍历结束" << endl;

	//map的查找
	map<int, string>::iterator it2 = map1.find(100);
	if (it2 == map1.end())
	{
		cout << "key100的值不存在" << endl;
	}
	else
	{
		cout << it2->first << " " << it2->second << endl;
	}

	//equal_range //异常处理
	pair<map<int, string>::iterator, map<int, string>::iterator > mypair = map1.equal_range(5);
	//第一个迭代器是>=5的位置
	//第二个迭代器是>5的位置

	if (mypair.first == map1.end())//如果第一个迭代器的是map1的结尾，说明没找到
	{
		cout << "第一个迭代器>=5的位置不存在" << endl;
	}
	else
	{
		cout << mypair.first->first << "\t" << mypair.first->second << endl;
	}

	//使用第二个迭代器
	if (mypair.second == map1.end())//如果第二个迭代器的是map1的结尾，说明没找到
	{
		cout << "第二个迭代器>5的位置" << endl;
	}
	else
	{
		cout << mypair.second->first << "\t" << mypair.second->second << endl;
	}
}


void main()
{
	//main1101();
	//main1102();
	main1103();

	cout << "hello..." << endl;
	return;
}