/**
    *��ӡͼ��
    *���ߣ����ļ�
    *���ڣ�2018��8��25��
    *��Ȩ�����������ҵ�
    *��ӡ�Ľ����
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
      for(int i = 0;i < 4;i++)//������Ҫ��ӡ����
       {
           for(int j = 0;j <= 2-i;j++)//�ȴ�ӡ�ո�
           {
               cout << " ";
           }
           for(int j = 0;j <= i*2;j++)//�ٴ�ӡͼ��
           {
               if(j == 0 || j == i*2 )
                    cout << "*";//ÿһ�еļ�ֵ����ӡͼ������������ӡ�ո񡣾��ǹ۲�õ���ÿһ�еĵ�һ�������һ����ͼ���������ǿո�
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
