#ifndef EWDEMO_H_INCLUDED
#define EWDEMO_H_INCLUDED
#include <iostream>

using namespace std;

//ʹ�ö�λ������Ϊ��������
void show(double (*)[2], int);//�����ά�������Ԫ�ز��뱻������ģ��Ǿ�д�� void show(const double (*)[2], int);

void show(double (*arrs)[2], int len)//void show(const double (*arrs)[2], int);
{
    for(int i =0;i < len;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            cout << arrs[i][j] << "\t";
        }
        cout << endl;
    }
}


#endif // EWDEMO_H_INCLUDED
