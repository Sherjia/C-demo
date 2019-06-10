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


	cout << "ͷ��Ԫ�أ� " << dl.front() << endl; 
	cout << "β��Ԫ�أ� " << dl.back() << endl;
	printD(dl);

	cout << endl;

	dl.pop_front();
	dl.pop_back();
	printD(dl);

	//����-33�������±��ֵ
	deque<int>::iterator it = find(dl.begin(), dl.end(), -33);
	if (it != dl.end())
	{
		cout << "-33�����±���" << distance(dl.begin(), it) << endl;
	}
	else
	{
		cout << "û�ҵ�ֵΪ-33��Ԫ���±�" << endl;
	}

}

void main()
{
	main41();

	
	return;
}