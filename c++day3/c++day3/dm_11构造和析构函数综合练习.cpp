#include <iostream>
using namespace std;

class ABCD
{
public:
	ABCD(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		printf("ABCD() construct,a:%d,b:%d,c:%d \n", this->a, this->b, this->c);
	}
	~ABCD()
	{
		printf("~ABCD() construct,a:%d,b:%d,c:%d \n", this->a, this->b, this->c);
	}
	int getA()
	{
		return this->a;
	}
protected:
private:
	int a;
	int b;
	int c;
};

class MyE
{
public:
	MyE() :abcd1(1, 2, 3), abcd2(4, 5, 6), m(100)
	{
		cout << "MyD()" << endl;
	}
	~MyE()
	{
		cout << "MyD()" << endl;
	}
	MyE(const MyE& obj) :abcd1(7, 8, 9), abcd2(10, 11, 12), m(100)
	{
		printf("MyD(const MyD & obj)\n");
	}
protected:
public:
	ABCD abcd1;
	ABCD abcd2;
	const int m;

};

int doTing(MyE myel)
{
	printf("doTing() myel.abcd1.a:%d \n", myel.abcd1.getA());
	return 0;
}

int run2()
{
	MyE myE;
	doTing(myE);
	return 0;
}

int run3()
{
	printf("run3 start..\n");

	ABCD(400,500,600);//��ʱ������������� �ʹ�������һ�仰��һ�����꣬���������Ͱ��������

	ABCD abcd = ABCD(100,200,300);//��������ʱ������ת��Ϊabcd�ˣ���ô���ǳ����˳����
	//

	printf("run3, end\n");

	return 0;
}

int main()
{
	run2();

	//run3();

	return 0;
}

/*
	�жϹ��캯�������������ĵ���˳��
	main����run2()�Ľ����
		ִ��MyE myE;���ù��캯�������չ��캯����ʼ���б�˳���ȳ�ʼ��abcd1��abcd2
		ABCD() construct,a:1,b:2,c:3
		ABCD() construct,a:4,b:5,c:6
		MyD()
		������ִ��doTing(myE);�������뵽int doTing(MyE myel)�ĺ�����
		��ΪmyE��myel����MyE�࣬��������ʵ��myE��ʼ���β�myel��������һ�������ʼ����һ������
		���Ե�����40�еĿ������캯�������չ��캯����ʼ���б�˳���ȳ�ʼ��abcd1��abcd2
		ABCD() construct,a:7,b:8,c:9
		ABCD() construct,a:10,b:11,c:12
		MyD(const MyD & obj)
		doTing() myel.abcd1.a:7
		���������������
		~ABCD() construct,a:10,b:11,c:12
		~ABCD() construct,a:7,b:8,c:9
		MyD()
		~ABCD() construct,a:4,b:5,c:6
		~ABCD() construct,a:1,b:2,c:3
		����õ���������������10 11 12��7 8 9MyD() 
		������4 5 6��1 2 3MyD()
*/