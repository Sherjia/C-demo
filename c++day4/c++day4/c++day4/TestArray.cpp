#include <iostream>
using namespace std;
#include"MyArray.h"

//类的框架设计完毕
//类的测试案例

void main()
{
	Array a1(10);

	for (int i = 0; i < a1.length(); i++)
	{
		//a1.setData(i, i);
		//2
		//重载[]
		a1[i] = i;
		//函数返回值当左值，需要返回一个引用(元素本身，而不是一个值)，还是要支持链式编程
		//a1.operator[i]
	}

	cout << "打印数组a1" << endl;
	for (int i = 0; i <a1.length(); i++)
	{
		//cout << a1.getData(i)<< endl;
		//1
		cout<<a1[i]<<endl;
	}
	cout << endl;
	//int operator[](int i)

	
	
	Array a2 = a1;
	cout << "打印数组a2" << endl;
	
	for (int i = 0; i <a2.length(); i++)
	{
		cout << a2.getData(i) << endl;
	}

	
  //重载=
  Array a3(5);
  {	
		a3 = a1;
		a3 = a2 = a1;
		//a3.operator=(a1);
		//Array& operator=(Array &a1)
		cout << "打印数组a3" << endl;
		for (int i = 0; i <a3.length(); i++)
		{
			//cout << a1.getData(i)<< endl;
			//1
			cout << a3[i] << " ";
		}
	}
   //重载==
   //a3.operator(a1);
  //bool operator==(Array &a1)
  if (a3 == a1)
  {
	  printf("相等\n");
  }
  else
  {
	  printf("不相等\n");
  }
  
  
  //重载 !=
  //a3.operator!=(a1)
  //bool operator!=(Array &a1);
  if (a3 != a1)
  {
	  printf("不相等\n");
  }
  else
  {
	  printf("相等\n");
  }
  
	cout << "hello..." << endl;
	return;
}