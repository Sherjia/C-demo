#include <iostream>
using namespace std;

//����ģ�屾�ʣ����Ͳ�����
//������
//���ַ����� int�����������

template <typename T, typename T2>
int mySort(T *array, T2 size)
{
	T2 i, j;
	T tmp;
	if (array == NULL)
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] < array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
	return 0;
}

template <typename T,typename T2>
int myPrint(T *array, T2 size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}

void main()
{
	//int ����
	/*{
		int myarray[] = { 11, 33, 44, 33, 32, 2, 3, 6, 9 };

		int size = sizeof(myarray) / sizeof(myarray[0]);
		mySort<int, int>(myarray, size);

		printf("����֮��\n");
		myPrint<int, int>(myarray, size);
	}*/
	//char ����
	{
		char buf[] = "wdfjjngfdswe";
		int len = strlen(buf);

		mySort<char, int>(buf, len);
		myPrint<char, int>(buf, len);
	}

	cout << "\nhello..." << endl;
	return;
}
