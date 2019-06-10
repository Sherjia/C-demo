/*数组排序
循环录入5个元素，进行降序排列后输出结果

时间：2018/9/5                 */
#include <iostream>

using namespace std;

int main()
{
    /*   //方案一：冒泡排序
    int nums[] = {15,25,90,23,9};
    int temp,j;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4 - i; j++ )
        {
            if(nums[j] < nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }

        }
    }
    cout << "结果为：" <<endl;
    for( int i = 0; i < 5;i++)//使用循环将结果打印出来
    {
        cout << nums[i] << "\t";
    }                             */
    /*  //方案二：选择排序
    int nums[]{15,25,90,23,9};
    int min = nums[0];//假设第一个元素为最小的
    int minIndex = 0;//第一个下标元素为0
    int temp;
    int length = sizeof(nums)/sizeof(int);

    for(int i = 0;i < length - 1; i++)
    {
        min = nums[i];
        minIndex = i;
        for(int j = i + 1;j < length ;j++)//避免每号元素不再与自身比较，并且每一个元素都与后面的比较，所以是j=i+1.既然从1开始，那么j<length.
        {
            if(nums[j] < min)
            {
                min = nums[j];
                minIndex = j;
            }
        }
        if(minIndex > i)//交换，如果后面的元素比假设的元素还小，那么就要交换元素位置与标号，达到排序的目的
        {
            temp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = temp;
        }
    }
    cout <<"结果为：" << endl;
        for(int i = 0;i < length;i++)
        {
            cout << nums[i] << endl;
        }

    //逆序排列
    for(int i = 0;i < length/2; i++)//如果是i < length，那么第一个与最后一个交换后，到头来最后一个又会和第一个交换。所以使一半的下标交换即可。
    {
       temp = nums[i];//让第一个与最后一个交换，第二个与倒数第二个交换，以此类推
       nums[i] = nums[length - i - 1];
       nums[length - i - 1] = temp;

    }
    cout <<"逆序结果为：" << endl;
        for(int i = 0;i < length;i++)
        {
            cout << nums[i] << endl;
        } */
    //实现数组的删除和插入
    double power[99];//数组长度一旦确定就无法更改！！！
    int powercount = 0;//当前数组中元素的个数
    power[powercount++] = 42322.35;
    power[powercount++] = 45782;
    power[powercount++] = 40907;
    power[powercount++] = 40706.58;//此时powercount为4

    double temp;

    for(int i = 0;i < powercount; i++)//冒泡排序
    {
        for(int j = 0; j < powercount - i - 1;j++)
        {
            if(power[j] < power[j+1])
            {
                temp = power[j];
                power[j] = power[j+1];
                power[j+1] = temp;
            }

        }
    }
    cout <<"排序后：";
    for(int i = 0; i < powercount;i++)
    {
        cout << power[i] <<"\t";
    }
    cout << endl;
    //插入元素
    double insertpower;
    int insertindex = 0;//默认插入的位置为第一个

    cout <<"请输入要插入的元素"<<endl;
    cin >> insertpower;
    insertindex = powercount;/*若插入的数字比原数组所有元素都小，那么就会插在最后一位。
                                   若不写这一句，前面Insertindex=0（默认放在第一位），那么它会被插在第一位*/
    //1.找到第一个比插入数字大的位置insertindex
    for(int i=0;i < powercount;i++)
    {
        if(insertpower > power[i])
        {
            insertindex = i;
            break;
        }
    }
    //2.从最后一个元素开始，将数字复制到后面一个元素中
    for(int i = powercount - 1;i >= insertindex;i--)
    {
        power[i+1] = power[i];
    }
    //3.将要插入的数字赋值给下标为insertindex的元素
    power[insertindex] = insertpower;
    //4.数组长度+1
    powercount++;

    cout <<"插入后的结果为：";
    for(int i =0;i < powercount;i++)
    {
        cout <<power[i]<<"\t";
    }
    cout <<endl;
    //删除
    double deletpower;
    int deletindex = INT_MIN;
    cout <<"请输入你要删除的数字：";
    cin >> deletpower;
    //1.找到要删除的元素下标
    for(int i = 0;i < powercount; i++)
    {
        if(deletpower == power[i])
        {
            deletindex = i;
            break;
        }
    }
    if(deletindex == INT_MIN)//在上一步找完以后，如果没找到,那么下标就是INT_MIN
    {
        cout << "没有找到要删除的数字，删除失败！！！";
    }
    else
    {
        //2.从找到的下标开始，将后面一个元素赋值给前面一个元素
          for(int i = deletindex;i < powercount - 1;i++)
        {
            power[i] = power[i+1];
        }
        //3.数组长度-1
        powercount--;
    }

    cout <<"删除后的结果为：";
    for(int i =0;i < powercount;i++)
    {
        cout <<power[i]<<"\t";
    }
    cout <<endl;










    return 0;
}
