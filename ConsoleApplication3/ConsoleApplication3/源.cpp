#include <iostream>
#include<stdlib.h>


void pointer1(int** p1, int* p2)
{
	*p1 = p2;
}

void main()
{
	int pvalue = 20;
	int* p = (int*)malloc(sizeof(int));
	pointer1(&p, &pvalue);
	printf("the pvalue is %d \n", *p);

	system("pause");

}