#include <iostream>
using namespace std;
#include <list>

//list基本操作
void main71()
{
	list<int> l;
	cout << "list的大小： " << l.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);//尾部插入元素 尾插法
	}

	list<int>::iterator it = l.begin();

	while (it != l.end())
	{
		cout << *it << endl;
		it++;
	}

	//list不能随机访问
	it = l.begin();
	it++;
	it++;
	it++;
	//it = it+5; //不支持随机的访问容器
	//0 1 2 3 4 5
	//      △
	l.insert(it, 100);//请问100插在3的后面还是前面

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}//结果是插在了3的前面
	//结论：链表的结点index序号是从0号位置开始
	//     在3号位置插入元素，让原来的3号位置变成4号位置 原来的4号位置变成5号位置

}

//list删除
void main72()
{
	list<int> l;
	cout << "list的大小： " << l.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);//尾部插入元素 尾插法
	}
	cout << "list的大小： " << l.size() << endl;

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//0 1 2 3 4 5
	//      △

	list<int>::iterator it1 = l.begin();
	list<int>::iterator it2 = l.begin();
	it2++;
	it2++;
	it2++;

	l.erase(it1, it2);//删除的区间是左闭右开


	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	l.insert(l.begin(), 100);
	l.insert(l.begin(), 100);
	l.insert(l.begin(), 100);

	l.erase(l.begin());//删除开头第一个元素
	l.remove(100);//删除里面的100这个元素。把前面三个100都删了
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

void main()
{
	//main71();
	main72();


	return;
}