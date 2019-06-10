#include <iostream>
using namespace std;
/*
	c++提供了四种
	static_cast 静态类型转换
	reinterpret_cast 重新解释类型
	dynamic_cast 动态类型转换，如父类和子类之间的多态转换
	const_cast 字面上理解就是去掉const属性
*/
//结论：程序员要清楚地知道 变量在转换之前是什么类型，转换之后是什么类型
//一般下，不建议进行类型转换，避免进行类型转换

void printBuf(const char *p)//const char *p的const修饰，让p指向的内存空间 变成只读属性
{
	char *p1 = NULL;
	//程序员要清楚地知道 变量在转换之前是什么类型，转换之后是什么类型
	//const char* ===> char* //把只读属性去掉
	p1 = const_cast<char *>(p);

	p1[0] = 'Z';//通过p1， 去修改了内存空间
	cout << p << endl;
}

void main()
{
	char buf[] = "adsdssafdssd";
	//程序员 要确保p所指向的内存空间 确实能修改 ；如果不能修改，会带来灾难性后果
	printBuf(buf);//"adsdssafdssd"==>"Zdsdssafdssd"

	//下面这种就不能修改 因为这是字符指针类型 它的地址就是字符串，无法改
	//char *myp = "aanhmklmj";
	//printBuf(myp);

}

class Tree {};

class Animal
{
public:
	virtual void cry() = 0;
protected:
private:
};

class Dog : public Animal
{
public:
	virtual void cry()
	{
		cout << "汪汪" << endl;
	}
	void doHome()
	{
		cout << "看家" << endl;
	}
};

class Cat : public Animal
{
public:
	virtual void cry()
	{
		cout << "喵喵" << endl;
	}
	void doThings()
	{
		cout << "抓老鼠" << endl;
	}
};

void playobj(Animal* base)
{
	base->cry();//多态3个条件 1.有继承 2.有虚函数重写 3.父类指针指向子类对象===>多态

	//能识别子类对象
	//dynamic_cast运行时类型识别 RIIT

	Dog *pDog = dynamic_cast<Dog *>(base);//就是在主函数里父类指向Dog子类指针playobj(&d1)，就识别成功了，就不为NULL
	if (pDog != NULL)//不为NULL，说明识别成功
	{
		pDog->doHome();//让它做自己特有的工作
	}

	Cat *pCat = dynamic_cast<Cat *>(base);//父类对象 ===> 子类对象 向下转型
										  //把老子转成小子
	if (pCat != NULL)
	{
		pCat->doThings();
	}
}

void main12()
{
	Dog d1;
	Cat c1;
	playobj(&d1);
	playobj(&c1);
	
	Animal *pBase = NULL;

	//pBase = &d1;
	pBase = static_cast<Animal*>(&d1);//static_cast就是让编译器编译时，做类型检查,此处成功

	//强制类型转换
	pBase = reinterpret_cast<Animal*>(&d1);
	{
		Tree t1;
		//pBase = static_cast<Animal*>(&t1);//把Tree转成Animal类 c++编译器做类型检查 无效的
		pBase = reinterpret_cast<Animal*>(&t1);//reinterpret_cast 重新解释...强制类转换的味道
	}

	
	
	return;
}


void main11()
{
	double dpi = 3.1415926;

	int num1 = (int)dpi;//c风格的类型转化
	int num2 = static_cast<int>(dpi);//c++风格的静态类型转换
	int num3 = dpi;//c语言中 隐式类型转换的地方 均可使用static_cast<>()进行转换

	//char* ===> int *
	/*
	char *p1 = "hello";
	int *p2 = NULL;
	P2 = static_cast<int*>(p1);//使用static_cast<>()，编译器编译时，会做类型检查 若有错误 会提示错误
	*/
	
	char *p1 = "hello";
	int *p2 = NULL;
	p2 = reinterpret_cast<int*>(p1);//若不同类型之间 进行强制类型转换 用reinterpret_cast<>()进行重新解释
	cout << "p1: " << p1 << endl;//%s "hello"
	cout << "p2: " << p2 << endl;//%d "hello"的地址

	//总结：通过static_cast<>()和reinterpret_cast<>()把c++语言的强制类型转换覆盖了

	cout << "hello..." << endl;
	return;
}