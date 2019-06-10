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

	ABCD(400,500,600);//临时对象的生命周期 就存在于这一句话，一调用完，析构函数就把它清除了

	ABCD abcd = ABCD(100,200,300);//匿名（临时）对象转正为abcd了，那么就是常规的顺序了
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
	判断构造函数和析构函数的调用顺序
	main调用run2()的结果：
		执行MyE myE;调用构造函数，按照构造函数初始化列表顺序，先初始化abcd1和abcd2
		ABCD() construct,a:1,b:2,c:3
		ABCD() construct,a:4,b:5,c:6
		MyD()
		下面是执行doTing(myE);，并跳入到int doTing(MyE myel)的函数；
		因为myE和myel都是MyE类，这里是用实参myE初始化形参myel，就是用一个对象初始化另一个对象
		所以调用了40行的拷贝构造函数。按照构造函数初始化列表顺序，先初始化abcd1和abcd2
		ABCD() construct,a:7,b:8,c:9
		ABCD() construct,a:10,b:11,c:12
		MyD(const MyD & obj)
		doTing() myel.abcd1.a:7
		下面调用析构函数
		~ABCD() construct,a:10,b:11,c:12
		~ABCD() construct,a:7,b:8,c:9
		MyD()
		~ABCD() construct,a:4,b:5,c:6
		~ABCD() construct,a:1,b:2,c:3
		后调用的先析构，析构了10 11 12和7 8 9MyD() 
		析构了4 5 6和1 2 3MyD()
*/