#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int myadd(int a, int b)//�������ʵ����
{
	printf("func add...\n");
	return a + b;
}
int myadd2(int a, int b)//�������ʵ����
{
	printf("func add2...\n");
	return a + b;
}
int myadd3(int a, int b)//�������ʵ����
{
	printf("func add3...\n");
	return a + b;
}
int myadd4(int a, int b)//�������ʵ����
{
	printf("func add4...\n");
	return a + b;
}

//����һ������
typedef int(*MyTypeFuncAdd)(int a, int b);

//����ָ������������
int MainOp(MyTypeFuncAdd myFuncAdd)
{
	int c = myFuncAdd(5, 6);
	return c;
}

//Ҳ�Ǻ���ָ������������
//int(*MyPointerFuncAdd)(int a, int b);
int MainOp2(int(*MyPointerFuncAdd)(int a, int b))
{
	int c =  MyPointerFuncAdd(5, 6);//��ӵ���
	return c;
}

//��ӵ���
//����ĵ��ú�����ı�д���Էֿ�
void main()
{
	/*
	MyTypeFuncAdd myFuncAdd = NULL;
	myadd(1, 2);//ֱ�ӵ���

	myFuncAdd = myadd;
	myFuncAdd(3, 4);//��ӵ���

	MainOp(myadd);
	MainOp2(myadd);
	*/

	//��MainOpû�з����κα仯������£����԰Ѻ�����д�Ĵ����������
	MainOp(myadd2);//����ָ�����������������������Ǻ�������ڵ�ַ
	MainOp(myadd3);
	MainOp(myadd4);

	printf("hello...\n");
	return;
}