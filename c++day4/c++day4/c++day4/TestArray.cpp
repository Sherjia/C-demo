#include <iostream>
using namespace std;
#include"MyArray.h"

//��Ŀ��������
//��Ĳ��԰���

void main()
{
	Array a1(10);

	for (int i = 0; i < a1.length(); i++)
	{
		//a1.setData(i, i);
		//2
		//����[]
		a1[i] = i;
		//��������ֵ����ֵ����Ҫ����һ������(Ԫ�ر���������һ��ֵ)������Ҫ֧����ʽ���
		//a1.operator[i]
	}

	cout << "��ӡ����a1" << endl;
	for (int i = 0; i <a1.length(); i++)
	{
		//cout << a1.getData(i)<< endl;
		//1
		cout<<a1[i]<<endl;
	}
	cout << endl;
	//int operator[](int i)

	
	
	Array a2 = a1;
	cout << "��ӡ����a2" << endl;
	
	for (int i = 0; i <a2.length(); i++)
	{
		cout << a2.getData(i) << endl;
	}

	
  //����=
  Array a3(5);
  {	
		a3 = a1;
		a3 = a2 = a1;
		//a3.operator=(a1);
		//Array& operator=(Array &a1)
		cout << "��ӡ����a3" << endl;
		for (int i = 0; i <a3.length(); i++)
		{
			//cout << a1.getData(i)<< endl;
			//1
			cout << a3[i] << " ";
		}
	}
   //����==
   //a3.operator(a1);
  //bool operator==(Array &a1)
  if (a3 == a1)
  {
	  printf("���\n");
  }
  else
  {
	  printf("�����\n");
  }
  
  
  //���� !=
  //a3.operator!=(a1)
  //bool operator!=(Array &a1);
  if (a3 != a1)
  {
	  printf("�����\n");
  }
  else
  {
	  printf("���\n");
  }
  
	cout << "hello..." << endl;
	return;
}