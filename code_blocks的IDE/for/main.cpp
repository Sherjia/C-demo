#include <iostream>
/*��ӡ1997��7�µ�����
  8��21��*/

using namespace std;

int main()
{
    //ͨ���۲죬ÿ����Ҫ��ӡ/t����ʾ�������ڼ�
    //��Ϊ7�µĵ�һ�����ܶ������Եó����ɣ�/t������=���ڼ�-1
    cout <<"һ\t��\t��\t��\t��\t��\t��\t"<<endl;
    int dayofweek = 2;//���ڶ�
    for(int i = 0;i < dayofweek - 1; i++)//ֻ��ӡ��һ������֮ǰ��/t
    {
        cout << '\t';
    }
    //ѭ����ӡ31��
    for(int i = 0;i < 31;i++)
    {
        cout <<i + 1;
    //�۲췢�֣����պ�����Ҫ����\n����������Ҫ�ո�\t������Ҫ���֡�
        if((dayofweek + i)%7 == 0)//dayofweek���ܶ���ʼ��i��0��ʼ�����վͻ��С�
            cout << '\n';
        else
            cout << '\t';
    }

    return 0;
}
