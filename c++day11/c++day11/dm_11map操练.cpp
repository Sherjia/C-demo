#include <iostream>
using namespace std;
#include "map"
#include "string"

//mapԪ�ص����/����/ɾ����������
void main1101()
{
	map<int, string> map1;

	//����1
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	//����2
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));

	//����3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	//����4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << "\t" << endl;
	}
	cout << "��������" << endl;

	//����ɾ��Ԫ��
	while (!map1.empty())
	{
		map<int, string>::iterator it = map1.begin();
		cout << it->first << "\t" << it->second << "\t" << endl;
		map1.erase(it);
	}

}

//���ֲ��뷽������ͬ
//ǰ���ַ������ص���pair<iterator,bool> ��key�Ѿ����ڣ��򱨴�
//�����ַ�����key�Ѿ����ڣ��򸲸�ǰһ��
void main1102()
{
	map<int, string> map1;

	//typedef pair<iterator, bool>_Pairib;

	//����1
	pair<map<int, string>::iterator, bool> mypair1 = map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	//����2
	pair<map<int, string>::iterator, bool> mypair3 = map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));

	//����3
	pair<map<int, string>::iterator, bool> mypair5 = map1.insert(map<int, string>::value_type(5, "teacher05"));
	if (mypair5.second != true)//pair���ж��Ƿ����ɹ�
	{
		cout << "key5����ʧ��" << endl;
	}
	else
	{
		cout << mypair5.first->first << "\t" << mypair5.first->second << endl;
	}
	pair<map<int, string>::iterator, bool> mypair6 = map1.insert(map<int, string>::value_type(5, "teacher55"));
	if (mypair6.second != true)
	{
		cout << "key6����ʧ��" << endl;
	}
	else
	{
		cout << mypair6.first->first << "\t" << mypair6.first->second << endl;
	}

	//����4
	map1[7] = "teacher07";
	map1[7] = "teacher77";//���Ὣmap1[7] = "teacher07";����

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << "\t" << endl;
	}
	cout << "��������" << endl;
}

void main1103()
{
	map<int, string> map1;

	//����1
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	//����2
	map1.insert(make_pair(3, "teacher03"));
	map1.insert(make_pair(4, "teacher04"));

	//����3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	//����4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << "\t" << endl;
	}
	cout << "��������" << endl;

	//map�Ĳ���
	map<int, string>::iterator it2 = map1.find(100);
	if (it2 == map1.end())
	{
		cout << "key100��ֵ������" << endl;
	}
	else
	{
		cout << it2->first << " " << it2->second << endl;
	}

	//equal_range //�쳣����
	pair<map<int, string>::iterator, map<int, string>::iterator > mypair = map1.equal_range(5);
	//��һ����������>=5��λ��
	//�ڶ�����������>5��λ��

	if (mypair.first == map1.end())//�����һ������������map1�Ľ�β��˵��û�ҵ�
	{
		cout << "��һ��������>=5��λ�ò�����" << endl;
	}
	else
	{
		cout << mypair.first->first << "\t" << mypair.first->second << endl;
	}

	//ʹ�õڶ���������
	if (mypair.second == map1.end())//����ڶ�������������map1�Ľ�β��˵��û�ҵ�
	{
		cout << "�ڶ���������>5��λ��" << endl;
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