#include <iostream>
/*打印1997年7月的日历
  8月21号*/

using namespace std;

int main()
{
    //通过观察，每个月要打印/t来表示这是星期几
    //因为7月的第一天是周二，所以得出规律：/t的数量=星期几-1
    cout <<"一\t二\t三\t四\t五\t六\t日\t"<<endl;
    int dayofweek = 2;//星期二
    for(int i = 0;i < dayofweek - 1; i++)//只打印第一个日子之前的/t
    {
        cout << '\t';
    }
    //循环打印31天
    for(int i = 0;i < 31;i++)
    {
        cout <<i + 1;
    //观察发现，周日后面需要换行\n，而其他需要空格\t，所以要区分。
        if((dayofweek + i)%7 == 0)//dayofweek从周二开始，i从0开始。周日就换行。
            cout << '\n';
        else
            cout << '\t';
    }

    return 0;
}
