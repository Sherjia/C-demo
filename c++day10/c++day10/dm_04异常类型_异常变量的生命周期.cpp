#include <iostream>
using namespace std;

//传统的错误处理机制
//throw int类型异常
void my_strcpy1(char *to, char *from)
{
	if (from == NULL)
	{
		throw 1;
	}
	if (to == NULL)
	{
		throw 2;
	}

	//copy时的 场景检查
	if (*from == 'a')
	{
		throw 3;
	}

	while (from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';

}

void main42()
{
	int ret = 0;
	char buf1[] = "azbcde";
	char buf2[1024] = { 0 };

	try
	{
		my_strcpy1(buf2, buf1);
	}
	catch (int e)//e可写可不写
	{
		cout << e << "int类型异常" << endl;//此时e为3
	}
	catch (...)
	{
		cout << "未知类型异常" << endl;
	}

	cout << "hello..." << endl;
	return;
}

//throw char* 类型异常
void my_strcpy2(char *to, char *from)
{
	if (from == NULL)
	{
		throw "源buf出错！";
	}
	if (to == NULL)
	{
		throw "目的buf出错！";
	}

	//copy时的 场景检查
	if (*from == 'a')
	{
		throw "copy过程出错";
	}

	while (from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';

}

void main43()
{
	int ret = 0;
	char buf1[] = "azbcde";
	char buf2[1024] = {0};

	try
	{
		my_strcpy2(buf2, buf1);
	}
	catch (int e)//e可写可不写
	{
		cout << e<<"int类型异常" << endl;//此时e为3
	}
	catch (char *e)
	{
		cout << e << "char* 类型异常" << endl;//此时e为"copy过程出错"
	}
	catch (...)
	{
		cout << "未知类型异常" << endl;
	}
	
	cout << "hello..." << endl;
	return;
};

class BadSrcType{};
class BadDestType {};

class BadProcessType 
{
public:
	BadProcessType()
	{
		cout << "BadProcessType构造函数do \n";
	}
	~BadProcessType()
	{
		cout << "BadProcessType析构函数do \n";
	}
	BadProcessType(const BadProcessType &obj)
	{
		cout << "BadProcessType拷贝构造函数do \n";
	}
protected:
private:
};
//throw 类对象 类型异常
void my_strcpy3(char *to, char *from)
{
	if (from == NULL)
	{
		throw BadSrcType();
	}
	if (to == NULL)
	{
		throw BadDestType();
	}

	//copy时的 场景检查
	if (*from == 'a')
	{
		printf("开始 BadProcessType类型异常\n");
		throw BadProcessType();//会产生一个匿名对象
	}
	if (*from == 'b')
	{
		throw new BadProcessType;
	}

	while (from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';

}
void main()
{
	int ret = 0;
	char buf1[] = "bazbcde";
	char buf2[1024] = { 0 };

	try
	{
		my_strcpy3(buf2, buf1);
	}
	catch (int e)//e可写可不写
	{
		cout << e << "int类型异常" << endl;//此时e为3
	}
	catch (char *e)
	{
		cout << e << "char* 类型异常" << endl;//此时e为"copy过程出错"
	}
	
	//---
	catch (BadSrcType e)
	{
		cout <<"BadSrcType 类型异常" << endl;//此时e为"copy过程出错"
	}
	catch (BadDestType e)
	{
		cout <<"BadDestType 类型异常" << endl;//此时e为"copy过程出错"
	}
	//结论1：如果接收异常的时候，使用一个异常变量，则拷贝构造异常变量
	/*
	catch (BadProcessType e)//是把throw抛出的匿名对象copy给e 
	{
		cout <<"BadProcessType 类型异常" << endl;//此时e为"copy过程出错"
	}*/
	//结论2：使用引用的话 会使用throw时候的对象
	catch (BadProcessType &e)
	{
		cout << "BadProcessType 类型异常" << endl;//此时e为"copy过程出错"
	}
	//结论3：指针可以和元素与引用写在一起，但元素和引用不行
	catch (BadProcessType *e)//要想catch一个指针，必须抛出一个指针类型 throw new BadProcessType;并且还得new一块内存，
							 //否则会自动调用析构函数，然后出现野指针。所以看出来catch指针不好
	{
		delete e;
		cout << "BadProcessType 类型异常" << endl;
	}
	//---
	//结论：catch时候，catch引用	
	catch (...)
	{
		cout << "未知类型异常" << endl;
	}

	cout << "hello..." << endl;
	return;
};


//传统的错误处理机制
int my_strcpy(char *to, char *from)
{
	if (from == NULL)
	{
		return 1;
	}
	if (to == NULL)
	{
		return 2;
	}

	//copy时的 场景检查
	if (*from == 'a')
	{
		return 3;
	}

	while (from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';

	return 0;
}

void main41()
{
	int ret = 0;
	char buf1[] = "zbcde";
	char buf2[1024] = {0};

	ret = my_strcpy(buf2, buf1);
	if (ret != 0)
	{
		switch (ret)
		{
		case 1:
			printf("源buf出错！\n");
			break;
		case 2:
			printf("目的buf出错！\n");
			break;
		case 3:
			printf("copy过程出错！\n");
			break;
		default:
			printf("未知错误！\n");
			break;
		}
	}
	printf("buf2:%s \n", buf2);

	cout << "hello..." << endl;
	return;
};