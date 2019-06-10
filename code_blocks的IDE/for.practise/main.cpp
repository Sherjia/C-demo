/*for循环打印图案
时间：2018/9/4
答案：
*********
*       *
*       *
*       *
*       *
*       *
*       *
*       *
*********                   */


#include <iostream>

using namespace std;

int main()
{
    for(int i = 0;i < 9;i++)//控制需要打印几行
       {
           for(int j = 0;j <9;j++)//先打印空格
           {
                    while (i == 0 || i == 8)//这个循环就是第一行和最后一行全部打满图案，达到第8个就跳出循环
                    {
                        cout << "*";
                        j++;
                        if(j > 8)
                            break;
                    }
                        if(j == 0 || j == 8 )//其余的几行都是第一个和最后一个有图案，剩下都空着
                            cout << "*";
                        else
                            cout << ' ';




           }
           cout << endl;
       }

        return 0;

}
