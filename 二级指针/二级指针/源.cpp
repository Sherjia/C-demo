#include <stdio.h>
#include <stdlib.h>
#include <cstring>

void printMyArray02(char myArray[10][30], int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", *(myArray + i));
	}
}

void sortMyArray02(char myArray[10][30], int num)
{
	int i = 0, j = 0;
	char tmpBuf[30];
	
	for (i = 0; i < num; i++)//ð������
	{
		for (j = j + 1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)//�Ƚ������ַ���,��str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�������	
			{
				strcpy_s(tmpBuf, myArray[i]);  //����һ���ַ���������ڴ�齻����ǰһ����
				strcpy_s(myArray[i], myArray[j]);
				strcpy_s(myArray[j], tmpBuf);
			}
		}
	}
}

void main()
{
	int i = 0, j = 0;
	int num = 4;
	char myBuf[30];
	char tmpBuf[30];
	char myArray[10][30] = { "aaaa", "ccccc", "bbbbb", "1111111" };

	//��ӡ
	printf("����֮ǰ\n");

	printMyArray02(myArray, num);

	sortMyArray02(myArray, num);

	//�����
	printf("����֮��\n");
	
	printMyArray02(myArray, num);



	return;
	
}