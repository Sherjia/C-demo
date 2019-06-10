#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "set"

//multiset与set的区别在于,multiset中同一值可以出现多次
void main1001()
{
	multiset<int> set1;
	int tmp = 0;

	printf("请输入multiset的值： ");
	scanf("%d", &tmp);
	while (tmp != 0)
	{
		set1.insert(tmp);
		printf("请输入multiset的值： ");
		scanf("%d", &tmp);
	}

	for (multiset<int>::iterator it = set1.begin(); it != set1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	while (!set1.empty())
	{
		multiset<int>::iterator it = set1.begin();
		cout << *it << endl;
		set1.erase(it);
	}
}

void main()
{
	main1001();

	cout << "hello..." << endl;
	return;
}