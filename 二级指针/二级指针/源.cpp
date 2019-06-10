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
	
	for (i = 0; i < num; i++)//冒泡排序
	{
		for (j = j + 1; j < num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)//比较两个字符串,若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数。	
			{
				strcpy_s(tmpBuf, myArray[i]);  //将后一个字符串数组的内存块交换到前一个中
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

	//打印
	printf("排序之前\n");

	printMyArray02(myArray, num);

	sortMyArray02(myArray, num);

	//排序后
	printf("排序之后\n");
	
	printMyArray02(myArray, num);



	return;
	
}