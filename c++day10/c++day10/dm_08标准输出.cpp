#include <iostream>
using namespace std;
#include <iomanip>

/*
��׼���������cout
	cout.flush()
	cout.put()
	cout.write()
	cout.width()
	cout.fill()
	cout.setf(���)
*/
/*
manipulator(�����������Ʒ�)
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
	cout.write(p, strlen(p)+4) << endl;//�ڴ�Խ���ˣ����п���崻�

	//cout << "hello..." << endl;
	return;
}

void main()
{
	//ʹ�����Ա����
	cout << "<start>";
	cout.width(30);
	cout.fill('*');
	cout.setf(ios::showbase);//#include <iomanip>
	//cout.setf(ios::internal);//����
	cout << hex << 123 << endl;

	cout << endl;
	
	//ʹ�ÿ��Ʒ�
	cout << "<start>"
		<< setw(30)
		<< setfill('*')
		<< setiosflags(ios::showbase)//����
		<< setiosflags(ios::internal)
		<< hex
		<< 123
		<< "<End>\n"
		<< endl;
}
