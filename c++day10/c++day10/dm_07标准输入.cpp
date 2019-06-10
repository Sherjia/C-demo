#include <iostream>
using namespace std;
#include "string"

/*
标准输入流对象cin
	cin.get()//一次只能读取一个字符
	cin.get(一个参数)//读一个字符
	cin.get(三个参数)//可以读字符串
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
	cin >> mybuf;//遇见空格停止接受 数据

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
	cout << "cin.get(a)如果缓冲区没有数据，则程序阻塞 \n";
	cin.get(a);
	cin.get(b);
	cin.get(c);

	cout << a << b << c << "因为缓冲区有数据，所以程序不会阻塞\n";

	cin.get(a).get(b).get(c);

	cout << a << b << c;

}

//getline
void main74()
{
	char buf1[256];
	char buf2[256];

	cout << "请输入一个字符串，含有多个空格。形如 aa bb cc\n";

	cin >> buf1;

	cin.getline(buf2, 256);

	cout << "buf1: " << buf1 << "buf2: " << buf2 << endl;

}

//cin.ignore()忽略缓冲区中数据的作用 csdn有文章
void main75()
{
	char buf1[256];
	char buf2[256];

	cout << "请输入一个字符串，含有多个空格。形如 aa  bbcc\n";

	cin >> buf1;
	cin.ignore(3);
	int myint = cin.peek();
	cout << "myint" << myint << endl;

	cin.getline(buf2, 256);

	cout << "buf1: " << buf1 << "\nbuf2: " << buf2 << endl;

}

//输入的整数和字符串分开处理:putback是将字符放回到输入流中,一般输入流中字符的长度是不变的。 
//putback会把cin刚刚“吃”进来的字符再“吐”回去，也就是说，下次cin>>x的时候，刚刚得到的那个字符还会参数输入
int main76()
{
	cout << "please, enter a number or a word:";
	char c = cin.get();

	if ((c >= '0') && (c <= '9'))
	{
		int n;//整数不可能 中间有空格 使用cin>>n
		cin.putback(c);//假如c是123456，如果用cin.putback，虽然char c = cin.get();那么打印的还是123456，否则就是23456
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