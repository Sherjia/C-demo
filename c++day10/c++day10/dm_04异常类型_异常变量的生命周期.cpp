#include <iostream>
using namespace std;

//��ͳ�Ĵ��������
//throw int�����쳣
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

	//copyʱ�� �������
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
	catch (int e)//e��д�ɲ�д
	{
		cout << e << "int�����쳣" << endl;//��ʱeΪ3
	}
	catch (...)
	{
		cout << "δ֪�����쳣" << endl;
	}

	cout << "hello..." << endl;
	return;
}

//throw char* �����쳣
void my_strcpy2(char *to, char *from)
{
	if (from == NULL)
	{
		throw "Դbuf����";
	}
	if (to == NULL)
	{
		throw "Ŀ��buf����";
	}

	//copyʱ�� �������
	if (*from == 'a')
	{
		throw "copy���̳���";
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
	catch (int e)//e��д�ɲ�д
	{
		cout << e<<"int�����쳣" << endl;//��ʱeΪ3
	}
	catch (char *e)
	{
		cout << e << "char* �����쳣" << endl;//��ʱeΪ"copy���̳���"
	}
	catch (...)
	{
		cout << "δ֪�����쳣" << endl;
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
		cout << "BadProcessType���캯��do \n";
	}
	~BadProcessType()
	{
		cout << "BadProcessType��������do \n";
	}
	BadProcessType(const BadProcessType &obj)
	{
		cout << "BadProcessType�������캯��do \n";
	}
protected:
private:
};
//throw ����� �����쳣
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

	//copyʱ�� �������
	if (*from == 'a')
	{
		printf("��ʼ BadProcessType�����쳣\n");
		throw BadProcessType();//�����һ����������
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
	catch (int e)//e��д�ɲ�д
	{
		cout << e << "int�����쳣" << endl;//��ʱeΪ3
	}
	catch (char *e)
	{
		cout << e << "char* �����쳣" << endl;//��ʱeΪ"copy���̳���"
	}
	
	//---
	catch (BadSrcType e)
	{
		cout <<"BadSrcType �����쳣" << endl;//��ʱeΪ"copy���̳���"
	}
	catch (BadDestType e)
	{
		cout <<"BadDestType �����쳣" << endl;//��ʱeΪ"copy���̳���"
	}
	//����1����������쳣��ʱ��ʹ��һ���쳣�������򿽱������쳣����
	/*
	catch (BadProcessType e)//�ǰ�throw�׳�����������copy��e 
	{
		cout <<"BadProcessType �����쳣" << endl;//��ʱeΪ"copy���̳���"
	}*/
	//����2��ʹ�����õĻ� ��ʹ��throwʱ��Ķ���
	catch (BadProcessType &e)
	{
		cout << "BadProcessType �����쳣" << endl;//��ʱeΪ"copy���̳���"
	}
	//����3��ָ����Ժ�Ԫ��������д��һ�𣬵�Ԫ�غ����ò���
	catch (BadProcessType *e)//Ҫ��catchһ��ָ�룬�����׳�һ��ָ������ throw new BadProcessType;���һ���newһ���ڴ棬
							 //������Զ���������������Ȼ�����Ұָ�롣���Կ�����catchָ�벻��
	{
		delete e;
		cout << "BadProcessType �����쳣" << endl;
	}
	//---
	//���ۣ�catchʱ��catch����	
	catch (...)
	{
		cout << "δ֪�����쳣" << endl;
	}

	cout << "hello..." << endl;
	return;
};


//��ͳ�Ĵ��������
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

	//copyʱ�� �������
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
			printf("Դbuf����\n");
			break;
		case 2:
			printf("Ŀ��buf����\n");
			break;
		case 3:
			printf("copy���̳���\n");
			break;
		default:
			printf("δ֪����\n");
			break;
		}
	}
	printf("buf2:%s \n", buf2);

	cout << "hello..." << endl;
	return;
};