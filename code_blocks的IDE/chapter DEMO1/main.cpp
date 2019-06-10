#include <iostream>

/**
    *打印图案
    *作者：薄文嘉
    *日期：2018年8月25日
    *版权：反正不是我的
    *打印的结果：
                   A
                  BBB
                 CCCCC
                DDDDDDD
                 AAAAA
                  BBB
                   C
*/

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
               cout << (char)('A'+i);//因为打印什么图案是由行来控制的，所以通过控制i来改变打印的图案。利用ASCII码来改变打印的字母
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
               cout << (char)('A'+i);
           }
           cout <<endl;
       }
        return 0;
}
