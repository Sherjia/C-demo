#ifndef EWDEMO_H_INCLUDED
#define EWDEMO_H_INCLUDED
#include <iostream>

using namespace std;

//使用二位数组作为函数参数
void show(double (*)[2], int);//如果二维数组里的元素不想被随意更改，那就写成 void show(const double (*)[2], int);

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
