#include <iostream>
using namespace std;

//�������ͻ����﷨֪ʶ����
//����һ����������
//int a[10];

//����һ��ָ����������

//����һ��ָ�� �������͵�ָ�� �������ָ��

void main01()
{
	int a[10];//a�������������Ԫ�صĵ�ַ &a������������ĵ�ַ a+1��4�� &a+1��40��������һ��

	//
	{
		//����һ����������
		typedef int(myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("%d\n", myArray[0]);
	}

	
	{
		//����һ��ָ����������
		typedef int(*PTypeAraay)[10];  //int *p;

		PTypeAraay myPArray; //sizeof(int) * 10;
		myPArray = &a;

		(*myPArray)[0] = 20;
		printf("a[0]: %d\n", a[0]);

	}

	{
		//����һ��ָ�� �������͵�ָ�� �������ָ��
		int(*MyPointer)[10];
		MyPointer = &a;
		(*MyPointer)[0] = 40;
		printf("a[0]: %d\n", a[0]);
	}

	cout << "hello..." << endl;
	return;
}

//����ָ������﷨֪ʶ����
//1.��ζ���һ����������
//2.��ζ���һ������ָ������
//3.��ζ���һ������ָ�루ָ��һ����������ڵ�ַ��

int add(int a, int b)
{
	printf("func add...\n");
	return a + b;
}

void main()
{
	add(1, 2); //ֱ�ӵ��� //���������Ǻ�������ڵ�ַ

	//1.��ζ���һ����������
	{
		typedef int(MyFuncType)(int a, int b); //������һ������
		MyFuncType *myPointFunc = NULL; //������һ��ָ�룬 ָ��ĳһ����ĺ���

		myPointFunc = &add;//ϸ��
		myPointFunc(3, 4);//��ӵ���

		myPointFunc = add;//ϸ�� //c�������Ƶģ�������ʷ�汾��ԭ����������������
		myPointFunc(3, 4);//��ӵ���


	}

	//2.��ζ���һ������ָ������
	{
		typedef int(*MyPointFuncType)(int a, int b);//int *a = NULL;
		MyPointFuncType myPointerFunc;//����һ��ָ��
		myPointerFunc = add;
		myPointerFunc(5, 6);


	}

	//3.��ζ���һ������ָ�루ָ��һ����������ڵ�ַ��
	{
		int(*MyPointerFunc)(int a, int b); //������һ������
		MyPointerFunc = add;
		MyPointerFunc(7, 8);
	}
}