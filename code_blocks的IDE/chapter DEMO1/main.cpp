#include <iostream>

/**
    *��ӡͼ��
    *���ߣ����ļ�
    *���ڣ�2018��8��25��
    *��Ȩ�����������ҵ�
    *��ӡ�Ľ����
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
       for(int i = 0;i < 4;i++)//������Ҫ��ӡ����
       {
           for(int j = 0;j <= 2-i;j++)//�ȴ�ӡ�ո�
           {
               cout << " ";
           }
           for(int j = 0;j <= i*2;j++)//�ٴ�ӡͼ��
           {
               cout << (char)('A'+i);//��Ϊ��ӡʲôͼ�������������Ƶģ�����ͨ������i���ı��ӡ��ͼ��������ASCII�����ı��ӡ����ĸ
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
