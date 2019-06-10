#include <iostream>
#include <iomanip>

using namespace std;
//string chatTo(const string& toName,const string& content);

/*
void Sort(int[],int);//重载，函数名相同，参数列表(特征标)不同
void Sort(float[],int);
void Sort(double[],double);
void show(int[],int);
void show(float[],int);
void show(double[],double);
*/
template<typename T>void Sort (T [],int);//使用函数模板技术声明函数
template<typename G>void show (G [],int);
int main()
{
    int iNums[] = {56,54,12,89,43};
    float fNums[] = {78.0f,5.7f,42.8f,99.1f};
    double dNums[] = {45.5,66.23,89.41,52.31};

    cout << "排序前";
    show(iNums,sizeof(iNums)/sizeof(int));//调用时只写函数名即可
    Sort(iNums,sizeof(iNums)/sizeof(int));
    cout << "排序后";
    show(iNums,sizeof(iNums)/sizeof(int));


    /*
    cout << "排序前：" ;
    show(iNums,sizeof(iNums)/sizeof(int));
    Sort(iNums,sizeof(iNums)/sizeof(int));
    cout << "排序后：";
    show(iNums,sizeof(iNums)/sizeof(int));

    cout << "排序前：" ;
    show(fNums,sizeof(fNums)/sizeof(int));
    Sort(fNums,sizeof(fNums)/sizeof(int));
    cout << "排序后：";
    show(fNums,sizeof(fNums)/sizeof(int));

    cout << "排序前：" ;
    show(dNums,sizeof(dNums)/sizeof(dNums[0]));
    Sort(dNums,sizeof(dNums)/sizeof(dNums[0]));
    cout << "排序后：";
    show(dNums,sizeof(dNums)/sizeof(dNums[1]));
    */
    /*
    string toName,content,chatMsg;
    cout << "请输入对方的名字：";
    getline(cin,toName);//从标准输入流中（键盘输入）读取一个字符串，存储到字符串string(对象)中

    cout <<"请输入对话内容：";
    getline(cin,content);

    chatMsg = chatTo(toName,content);
    cout << endl << chatMsg << endl;
    */

    return 0;
}
template<typename T> void Sort (T arr[],int len)//定义函数
{
    T temp;//不知道传递的是什么类型的参数，所以temp也是T型
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - 1 - i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] =  temp;
            }
        }
    }
}
template<typename G> void show (G arr[],int len)
{
    for(int i = 0;i < len;i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}
//参数是数组时，会自动将为指针！！！！
void Sort(int nums[],int len)
{
    int temp;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - 1 - i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] =  temp;
            }
        }
    }
}
void show(int nums[],int len)
{
    for(int i = 0;i < len;i++)
    {
        cout << nums[i] << ",";
    }
    cout << endl;
}
void Sort(float nums[],int len)
{
     int temp;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - 1 - i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] =  temp;
            }
        }
    }
}
void show(float nums[],int len)
{
    for(int i = 0;i < len;i++)
    {
        cout << nums[i] << ",";
    }
    cout << endl;
}
void Sort(double nums[],double len)
{
    int temp;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = 0;j < len - 1 - i;j++)
        {
            if(nums[j]>nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] =  temp;
            }
        }
    }
}
void show(double nums[],double len)
{
    for(int i = 0;i < len;i++)
    {
        cout << setprecision(4) << nums[i] << ",";
    }
    cout << endl;
}
/*
string chatTo(const string& toName,const string& content)
{
    string message = "你悄悄地对["+ toName + "]说：" + content;//字符串拼接时直接用+号，string类型好强大！！
    return message;
}
*/
