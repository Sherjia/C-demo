/**
    *打印图案
    *作者：薄文嘉
    *日期：2018年8月25日
    *版权：反正不是我的
    *打印的结果：
                       *
                      * *
                     *   *
                    *     *
                     *   *
                      * *
                       *
*/
#include <iostream>
using namespace std;

int main()
{
      for(int i = 0;i < 4;i++)//控制需要打印几行
       {
           for(int j = 0;j <= 2-i;j++)//先打印空格
           {
               cout << " ";
           }
           for(int j = 0;j <= i*2;j++)//再打印图案
           {
               if(j == 0 || j == i*2 )
                    cout << "*";//每一行的极值处打印图案，其它都打印空格。就是观察得到，每一行的第一个和最后一个是图案，其余是空格
               else
                    cout << ' ';
            }
           cout <<endl;
       }
       for(int i = 0;i < 3;i++)
       {
           for(int j = 0;j <= i;j++)
           {
               cout << " ";
           }
           for(int j = 0;j <= 4-i*2;j++)
           {
               if(j == 0 || j == 4-i*2)
                    cout << "*";
               else
                    cout << ' ';
           }
           cout <<endl;
       }
        return 0;

}
