#include <iostream>
#include<vector>/*使用vector必须加入此头文件*/
#include<algorithm>/*此头文件意思为算法*/

using namespace std;

int main()
{
    vector<double> vecDouble = {98.5,67.8,58.6,78.3};//定义数组
    vecDouble.push_back(100.8);//在数组尾部插入一个数组
    //遍历1
    for(int i = 0;i < vecDouble.size();i++)//size()意思为返回此数组的长度
    {
        cout << vecDouble[i] << endl;
    }//但是这种方法并不通用，所以使用下面这种方法
    cout << endl;

    //集合的通用遍历方法：使用迭代器 iterator
    //以下是迭代器的基本用法，高能预警！
    vector<double>::iterator it;//得到迭代器对象-实际上是一个指针对象
    //从第一个元素开始迭代
    for(it = vecDouble.begin(); it!=vecDouble.end();++it)//这个begin和end都是vector中的函数，作用相当于工具
    {
        cout << *it << endl;
    }
    cout << endl;
    //排序,就是调用头文件中algorithm的算法
    sort(vecDouble.begin(),vecDouble.end());
    //逆序
    reverse(vecDouble.begin(),vecDouble.end());
    for(it = vecDouble.begin(); it!=vecDouble.end();++it)
    {
        cout << *it << endl;
    }




    return 0;
}
