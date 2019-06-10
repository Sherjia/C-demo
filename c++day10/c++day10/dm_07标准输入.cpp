#include <iostream>
using namespace std;
#include "string"

/*
��׼����������cin
	cin.get()//һ��ֻ�ܶ�ȡһ���ַ�
	cin.get(һ������)//��һ���ַ�
	cin.get(��������)//���Զ��ַ���
	cin.getline()
	cin.ignore()
	cin.peek()
	cin.putback()
*/

void main71()
{
	char mybuf[1024];
	int myInt;
	long myLong;
	
	cin >> myInt;
	cin >> myLong;
	cin >> mybuf;//�����ո�ֹͣ���� ����

	cout << "myInt" << mybuf << "myLong" << myLong << "mybuf" << mybuf << endl;

	cout << "hello..." << endl;
	return;
}

//cin.get
void main72()
{
	char ch;
	while ((ch = cin.get()) != EOF)
	{
		cout << ch << endl;
	}
}

void main73()
{
	char a, b, c;
	cout << "cin.get(a)���������û�����ݣ���������� \n";
	cin.get(a);
	cin.get(b);
	cin.get(c);

	cout << a << b << c << "��Ϊ�����������ݣ����Գ��򲻻�����\n";

	cin.get(a).get(b).get(c);

	cout << a << b << c;

}

//getline
void main74()
{
	char buf1[256];
	char buf2[256];

	cout << "������һ���ַ��������ж���ո����� aa bb cc\n";

	cin >> buf1;

	cin.getline(buf2, 256);

	cout << "buf1: " << buf1 << "buf2: " << buf2 << endl;

}

//cin.ignore()���Ի����������ݵ����� csdn������
void main75()
{
	char buf1[256];
	char buf2[256];

	cout << "������һ���ַ��������ж���ո����� aa  bbcc\n";

	cin >> buf1;
	cin.ignore(3);
	int myint = cin.peek();
	cout << "myint" << myint << endl;

	cin.getline(buf2, 256);

	cout << "buf1: " << buf1 << "\nbuf2: " << buf2 << endl;

}

//������������ַ����ֿ�����:putback�ǽ��ַ��Żص���������,һ�����������ַ��ĳ����ǲ���ġ� 
//putback���cin�ոա��ԡ��������ַ��١��¡���ȥ��Ҳ����˵���´�cin>>x��ʱ�򣬸ոյõ����Ǹ��ַ������������
int main76()
{
	cout << "please, enter a number or a word:";
	char c = cin.get();

	if ((c >= '0') && (c <= '9'))
	{
		int n;//���������� �м��пո� ʹ��cin>>n
		cin.putback(c);//����c��123456�������cin.putback����Ȼchar c = cin.get();��ô��ӡ�Ļ���123456���������23456
		cin >> n;
		cout << "you enter a number: " << n << '\n';
	}
	else
	{
		string str;
		cin.putback(c);
		getline(cin, str);
		cout << "you enter a word: " << str << '\n';
	}

	return 0;
}