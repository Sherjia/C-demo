#include <iostream>
using namespace std;
#include "deque"
#include "algorithm"


void printD(deque<int> &d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void main41()
{
	deque<int> dl;
	dl.push_back(1);
	dl.push_back(3);
	dl.push_back(5);

	dl.push_front(-11);
	dl.push_front(-33);
	dl.push_front(-55);


	cout << "头部元素： " << dl.front() << endl; 
	cout << "尾部元素： " << dl.back() << endl;
	printD(dl);

	cout << endl;

	dl.pop_front();
	dl.pop_back();
	printD(dl);

	//查找-33在数组下标的值
	deque<int>::iterator it = find(dl.begin(), dl.end(), -33);
	if (it != dl.end())
	{
		cout << "-33数组下标是" << distance(dl.begin(), it) << endl;
	}
	else
	{
		cout << "没找到值为-33的元素下标" << endl;
	}

}

void main()
{
	main41();

	
	return;
}