#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#include "string"
#include "algorithm"


//string�ĳ�ʼ��
void main21()
{
	string s1 = "aaa";
	string s2 = ("bbb");
	string s3 = s2;//ͨ���������캯������ʼ������s3
	string s4(10, 'a');

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;

}

//string�ı���
void main22()
{
	string s1 = "abcdef";

	//���鷽ʽ
	for (unsigned int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	
	//��������ʽ
	for (string::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	
	try
	{
		for (unsigned int i = 0; i < s1.length() + 3; i++)//������s1.length()+3�����������쳣
		{
			cout << s1.at(i) << " ";//at��[]���������ڣ�at�����׳��쳣
		}
	}
	catch (...)
	{
		cout << "�����쳣\n";
	}

	cout << "at֮��" << endl;
	/*
	try
	{
		for (int i = 0; i < s1.length()+3; i++)
		{
			cout << s1[i] << " ";//���ִ��󣬲������׳��쳣�����������ж�
		}
	}
	catch (...)
	{
		cout << "�����쳣\n";
	}*/
	return;
}

//�ַ�ָ���string��ת��
void main23()
{
	string s2 = "aaabbbb";

	//1.s1===>char *
	printf("s1:%s \n", s2.c_str());//

	//2.char *====>string

	//3.s1�����ݿ�����buf��
	char buf1[128] = {0};
	s2.copy(buf1, 3, 0);//ֻ���㿽��3���ַ���������c�����ַ��������Գ�ʼ��buf1��ʱ�򶼶���Ϊ0
	cout << "buf1: " << buf1 << endl;
	
	return;
}

//string�ַ���������
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

//�ַ����Ĳ��Һ��滻 *�ص㣬
void main25()
{
	string s1 = "wbm hello wbm 111 wbm 222 wbm 333";
	//���ҳ���wbm��index

	int index = s1.find("wbm", 0);//λ���±��0��ʼ
	cout << "index" << index << endl;

	//����1.��wbm���ֵĴ��� ÿһ�γ��ֵ������±�
	int offindex = s1.find("wbm", 0);
	while (offindex != string::npos)//����-1,˵���ҵ���
	{
		cout << "offindex: " << offindex << endl;
		offindex += 1;
		offindex = s1.find("wbm", offindex);//offindex�ǳ��ֵ��±�
	}

	//����2. ��Сдwbm�滻��WBM

	string s3 = "aaa bbb ccc";
	s3.replace(0, 3, "AAA");
	cout << "s3: " << s3 << endl;

	offindex = s1.find("wbm", 0);
	while (offindex != string::npos)
	{
		cout << "offindex: " << offindex << endl;
		s1.replace(offindex,3,"WBM");
		offindex += 1;
		offindex = s1.find("wbm", offindex);//offindex�ǳ��ֵ��±�
	}
	cout << "s1: " << s1<< endl;
}

//�ض�(����ɾ��)�Ͳ���
void main26()
{
	string s1 = "hello1 hello2 hello1";
	string::iterator it = find(s1.begin(), s1.end(), '1');//find�㷨����һ����������λ��
	if (it != s1.end())
	{
		s1.erase(it);
	}
	cout << "ɾ���Ժ�Ľ����" << s1 << endl;

	s1.erase(s1.begin(), s1.end());
	cout << "s1ȫ��ɾ����" << s1 << endl;
	cout << "s1���� " << s1.length() << endl;

	string s2 = "BBB";
	s2.insert(0, "AAA");//ͷ�巨������
	s2.insert(s2.length(), "CCC");//β�巨
	cout << s2 << endl;

}

void main27()
{
	string s1 = "AAAbbb";
	//��������ڵ�ַ �������� Ԥ����ĺ�������
	transform(s1.begin(), s1.end(),s1.begin(),toupper);//ȫ�����д
	cout <<"s1: "<< s1 << endl;

	string s2 = "AAAbbb";
	transform(s2.begin(), s2.end(), s2.begin(), tolower);//ȫ����Сд
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