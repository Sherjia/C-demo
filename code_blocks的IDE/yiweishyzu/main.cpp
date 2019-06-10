#include <iostream>

using namespace std;

int main()
{
    //循环打印出数组中的元素
    int nums[]{3,5,9,78,89,465};
    int length = sizeof(nums)/sizeof(int);
    int sum = 0;

    for(int i = 0; i < length; i++)
    {
        cout << nums[i] << '\t';
        sum += nums[i];

    }
    cout << endl;


    cout << "和为：" << sum << "\t平均值为：" << sum/length << endl;
    //利用循环，像打擂台一样，先假设一个最大的元素，再循环比较，最终赋值最大的元素为max，打印出来

    int max = nums[0];//先假设数组中第一个元素为最大值
    int maxindex = 0;//最大值的下标也为0

    for(int i = 1; i < length; i++)
    {
        if(max < nums[i])
         {
             max = nums[i];//赋值最大值元素
             maxindex = i;//最大值下标
         }
    }

    cout << "数组中最大为：" << max << "\t" << nums[maxindex] << endl;
    cout << "最大值的下标为：" << maxindex <<endl;

    //求出数组中元素的奇数个数和偶数个数
    int jCount = 0, oCount = 0;//奇数计数和偶数计数

    for(int i = 0; i < length; i++)
    {
        if(nums[i] % 2 == 0)
        {
            oCount++;
        }
        else
        {
            jCount++;
        }
    }

    cout << "偶数的个数为：" << oCount << "\t" <<  "奇数的个数为：" << jCount << endl;

    //查找数组中所需要的数字，并记录下标
    int searchnums;//先定义你要查找的数字
    int searchindex = INT_MIN;//如果没有你要查找的数字，下标为INT_MIN,意思是整型中小的数字，其实就是先假设不存在

    cout << "亲输入你要查找的数字：" << endl;
    cin >> searchnums;

    for(int i = 0; i < length; i++)
    {
        if(nums[i] == searchnums)
        {
            searchindex = i;
            break;//找到以后再跳出循环
        }

    }
    if(searchindex == INT_MIN)
    {
        cout << "没有你要的数字" << endl;
    }else
    {
        cout << "数组下标为：" << searchindex << endl;
    }

    return 0;
}
