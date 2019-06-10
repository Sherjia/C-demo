#include <iostream>
using namespace std;
#include <iomanip>

/*
标准输出流对象cout
	cout.flush()
	cout.put()
	cout.write()
	cout.width()
	cout.fill()
	cout.setf(标记)
*/
/*
manipulator(操作符、控制符)
flush
endl
oct
hex
setbase
setw
setfill
setprecision
...
*/

void main81()
{
	cout << "hello..." << endl;
	cout.put('h').put('e').put('l');

	char *p = "hello itcast";
	cout.write(p, strlen(p)) << endl;
	cout.write(p, strlen(p)-4) << endl;
	cout.write(p, strlen(p)+4) << endl;//内存越界了，很有可能宕机

	//cout << "hello..." << endl;
	return;
}

void main()
{
	//使用类成员函数
	cout << "<start>";
	cout.width(30);
	cout.fill('*');
	cout.setf(ios::showbase);//#include <iomanip>
	//cout.setf(ios::internal);//设置
	cout << hex << 123 << endl;

	cout << endl;
	
	//使用控制符
	cout << "<start>"
		<< setw(30)
		<< setfill('*')
		<< setiosflags(ios::showbase)//基数
		<< setiosflags(ios::internal)
		<< hex
		<< 123
		<< "<End>\n"
		<< endl;
}
