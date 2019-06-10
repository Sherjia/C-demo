#ifndef GZDEMO_H_INCLUDED
#define GZDEMO_H_INCLUDED
//使用函数升级《小公主养成记》中的基本属性的录入及排序功能
//基本属性：体力、智力、魅力、道德、气质
#include <iostream>

using namespace std;
//函数定义
void input(int [],int);//输入五项属性的函数
void print(int [],int);//打印五项属性的函数


//函数实现
void input(int values[],int len)//因为传递数组时，其实传递的是数组的指针，那么就不知道数组里有几个元素，所以把数组的长度也传递上
{
    if(len > 5)
    {
        cout <<"数组长度只能是5以内"<<endl;
        return;//退出返回值为void的函数
    }
    string valueNames[] = {"体力","智力","魅力","道德","气质"};
    for(int i = 0;i < len;i++)
    {
        cout << valueNames[i] << ":";
        cin >> values[i];
    }
}
void print(int values[],int len)
{
    string valueNames[] = {"体力","智力","魅力","道德","气质"};
    for(int i = 0;i < len;i++)
    {
        cout << valueNames[i] << ":" << values[i] <<endl;
    }
}

#endif // GZDEMO_H_INCLUDED
