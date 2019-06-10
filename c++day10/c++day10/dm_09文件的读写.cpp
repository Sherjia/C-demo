#include <iostream>
using namespace std;
#include "fstream"



void main()
{
	char* fname = "f/2.txt";//此处放在哪个盘必须要小写
	ofstream fout(fname);//建一个 输出流对象 和文件关联
	fout << "hello...111" << endl;
	fout << "hello...222" << endl;
	fout << "hello...333" << endl;
	fout.close();

	//读文件
	ifstream fin(fname);//建立了一个输入流对象 和文件关联
	char ch;

	while (fin.get(ch))
	{
		cout << ch;
	}
	fin.close();


	cout << "hello..." << endl;
	return;
}