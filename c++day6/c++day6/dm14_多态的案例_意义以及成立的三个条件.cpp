#include <iostream>
using namespace std;

//HeroFihgter AdvHeroFighter EnemyFighter

class HeroFighter
{
public:
	virtual int power()//有virtual关键字，c++会对这个函数特殊处理
	{
		return 10;
	}
};

class EnemyFighter
{
public:
	int attack()
	{
		return 15;
	}
};

class AdvHeroFighter : public HeroFighter
{
public:
	virtual int power()
	{
		return 20;
	}
};

class AdvAdvHeroFighter : public HeroFighter
{
public:
	virtual int power()
	{
		return 30;
	}
};

//多态的威力
//1.PlayObj给对象搭建舞台 把他看成一个框架
void PlayObj(HeroFighter *hf, EnemyFighter *ef)
{
	//不写virtual关键字会是静态联编 c++编译器根据HeroFighter类，去执行这个类的power函数 在编译器编译阶段就决定了函数的调用
	//动态联编，迟绑定：在运行的时候，根据具体对象（具体的类型），执行不同对象的函数，表现成多态
	if (hf->power() > ef->attack()) //hf->power()函数调用会有多态发生
	{
		printf("主角win\n");
	}
	else
	{
		printf("主角挂了\n");
	}
}

//多态的思想
//面向对象的3大概念
//封装：突破了c语言函数的概念...用类做函数参数的时候，可以使用对象的属性，和对象的方法
//继承：A类 B类继承A类可以代码复现
//多态：不但继承，还可以使用未来

//多态很重要
//c语言 间接赋值 是指针存在的最大意义
//是c语言特有的现象（1.定义两个变量 2.建立关联 3.*p在被调用函数中去间接地修改实参的值）


//实现多态的3个条件（所有面向对象都适用的条件）
//1.要有继承
//2.要有虚函数重写
//3.用父类指针（父类引用）指向子类对象

void main()
{
	HeroFighter		hf;
	AdvHeroFighter	Advhf;
	EnemyFighter	ef;

	PlayObj(&hf, &ef);
	PlayObj(&Advhf, &ef);

	AdvAdvHeroFighter advadvhf;
	
	PlayObj(&advadvhf, &ef);//这个框架可以把我们后来人写的代码，给调用起来
	

	cout << "hello..." << endl;
	return;

}

void main1401()
{
	HeroFighter		hf;
	AdvHeroFighter	Advhf;
	EnemyFighter	ef;

	if (hf.power() > ef.attack())
	{
		printf("主角win\n");
	}
	else
	{
		printf("主角挂了\n");
	}

	if (Advhf.power() > ef.attack())
	{
		printf("Advhf主角win\n");
	}
	else
	{
		printf("Advhf主角挂了\n");
	}

	cout << "hello..." << endl;
	
	return;
}
