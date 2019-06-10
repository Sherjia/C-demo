#include <iostream>
using namespace std;
#include "vector"


//����Ԫ�ص� ��Ӻ�ɾ��
void main31()
{
	vector<int> v1;

	cout << "length: " << v1.size() << endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout << "length: " << v1.size() << endl;

	cout << "ͷ��Ԫ��: " << v1.front() << endl;

	//�޸�ͷ��Ԫ�ص�ֵ
	//��������ֵ����ֵ Ӧ�÷���һ������
	v1.front() = 11;
	v1.back() = 55;

	while (v1.size() > 0)
	{
		cout << "β��Ԫ�أ�" << v1.back() << endl;;//��ȡβ��Ԫ��
		v1.pop_back();//ɾ��β��Ԫ��
	}
}

//vector��ʼ��
void main32()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2 = v1;//�����ʼ��
	vector<int> v3(v1.begin(), v1.begin() + 2);//�����ʼ��
}

void printV(vector<int> &v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

//vector����
void main33()
{
	vector<int> v1(10);//д(10)��������10��Ԫ�أ���ǰ���ڴ����ã���Ȼ��崻�����Ϊ���õ�v1[i] = i + 1;�Ⱥŵķ�ʽ����Ԫ��
					   //push_back()�Ͳ�������
	//������ķ�ʽ
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

//push_back��ǿ������
void main34()
{
	vector<int> v1(10);//��ǰ���ڴ�׼����
	v1.push_back(100);//��β������100��200����ô��ǰ������ڴ�ȴû��ֵ��10���Ͷ�Ĭ��Ϊ0
	v1.push_back(200);
	cout << "size: " << v1.size() << endl;
	printV(v1);

}

//1.������begin() end()
//1 3 5
//��      begin()��ָ���һ��Ԫ��
//      �� end()��ָ�����һ��Ԫ�صĺ���
//��it == v1.end()ʱ��˵����������Ѿ����������
//2.������������
void main35()
{
	vector<int> v1(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	//��������ָ�� ��������� �������
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " " ;
	}
	//��������� �������
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++)
	{
		cout << *rit << " ";
	}
}

//vector ɾ��
void main36()
{
	vector<int> v1(10);
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 1;
	}

	//����ɾ��
	v1.erase(v1.begin(), v1.begin() + 3);
	printV(v1);

	
	//����Ԫ�ص�λ�ã�ָ��λ��ɾ��
	v1.erase(v1.begin());//��ͷ��ɾ��һ��Ԫ��
	printV(v1);

	
	//����Ԫ�ص�ֵɾ��
	v1[1] = 2;
	v1[3] = 2;
	printV(v1);

	
	for (vector<int>::iterator it = v1.begin(); it != v1.end();)
	{
		if (*it == 2)
		{
			it = v1.erase(it);//��ɾ����������ָ���Ԫ�ص�ʱ��erase����it�Զ����ƶ�������forѭ���ﲻ��дit++
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