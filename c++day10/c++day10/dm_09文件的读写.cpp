#include <iostream>
using namespace std;
#include "fstream"



void main()
{
	char* fname = "f/2.txt";//�˴������ĸ��̱���ҪСд
	ofstream fout(fname);//��һ�� ��������� ���ļ�����
	fout << "hello...111" << endl;
	fout << "hello...222" << endl;
	fout << "hello...333" << endl;
	fout.close();

	//���ļ�
	ifstream fin(fname);//������һ������������ ���ļ�����
	char ch;

	while (fin.get(ch))
	{
		cout << ch;
	}
	fin.close();


	cout << "hello..." << endl;
	return;
}