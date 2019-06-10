#include <iostream>
using namespace std;
#include "vector"


//数组元素的 添加和删除
void main31()
{
	vector<int> v1;

	cout << "length: " << v1.size() << endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout << "length: " << v1.size() << endl;

	cout << "头部元素: " << v1.front() << endl;

	//修改头部元素的值
	//函数返回值当左值 应该返回一个引用
	v1.front() = 11;
	v1.back() = 55;

	while (v1.size() > 0)
	{
		cout << "尾部元素：" << v1.back() << endl;;//获取尾部元素
		v1.pop_back();//删除尾部元素
	}
}

//vector初始化
void main32()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2 = v1;//对象初始化
	vector<int> v3(v1.begin(), v1.begin() + 2);//对象初始化
}

void printV(vector<int> &v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

//vector遍历
void main33()
{
	vector<int> v1(10);//写(10)表明插入10个元素，提前把内存分配好，不然会宕机。因为你用的v1[i] = i + 1;等号的方式加入元素
					   //push_back()就不用这样
	//用数组的方式
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}
	/*
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", v1[i]);
	}
	*/
	printV(v1);

}

//push_back的强化记忆
void main34()
{
	vector<int> v1(10);//提前把内存准备好
	v1.push_back(100);//在尾部插入100和200，那么提前分配好内存却没赋值的10个就都默认为0
	v1.push_back(200);
	cout << "size: " << v1.size() << endl;
	printV(v1);

}

//1.迭代器begin() end()
//1 3 5
//△      begin()是指向第一个元素
//      △ end()是指向最后一个元素的后面
//当it == v1.end()时，说明这个容器已经遍历完毕了
//2.迭代器的种类
void main35()
{
	vector<int> v1(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	//迭代器是指针 正向迭代器 正向遍历
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " " ;
	}
	//逆向迭代器 逆序遍历
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++)
	{
		cout << *rit << " ";
	}
}

//vector 删除
void main36()
{
	vector<int> v1(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	//区间删除
	v1.erase(v1.begin(), v1.begin() + 3);
	printV(v1);

	
	//根据元素的位置，指定位置删除
	v1.erase(v1.begin());//在头部删除一个元素
	printV(v1);

	
	//根据元素的值删除
	v1[1] = 2;
	v1[3] = 2;
	printV(v1);

	
	for (vector<int>::iterator it = v1.begin(); it != v1.end();)
	{
		if (*it == 2)
		{
			it = v1.erase(it);//当删除迭代器所指向的元素的时候，erase会让it自动下移动。所以for循环里不用写it++
		}
		else
		{
			it++;
		}
	}
	printV(v1);

	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 200);
	printV(v1);


}

void main()
{
	//main31();
	//main32();
	//main33();
	//main34();
	//main35();
	main36();

	return;
}