#include <iostream>

using namespace std;

int main()
{
    //ѭ����ӡ�������е�Ԫ��
    int nums[]{3,5,9,78,89,465};
    int length = sizeof(nums)/sizeof(int);
    int sum = 0;

    for(int i = 0; i < length; i++)
    {
        cout << nums[i] << '\t';
        sum += nums[i];

    }
    cout << endl;


    cout << "��Ϊ��" << sum << "\tƽ��ֵΪ��" << sum/length << endl;
    //����ѭ���������̨һ�����ȼ���һ������Ԫ�أ���ѭ���Ƚϣ����ո�ֵ����Ԫ��Ϊmax����ӡ����

    int max = nums[0];//�ȼ��������е�һ��Ԫ��Ϊ���ֵ
    int maxindex = 0;//���ֵ���±�ҲΪ0

    for(int i = 1; i < length; i++)
    {
        if(max < nums[i])
         {
             max = nums[i];//��ֵ���ֵԪ��
             maxindex = i;//���ֵ�±�
         }
    }

    cout << "���������Ϊ��" << max << "\t" << nums[maxindex] << endl;
    cout << "���ֵ���±�Ϊ��" << maxindex <<endl;

    //���������Ԫ�ص�����������ż������
    int jCount = 0, oCount = 0;//����������ż������

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

    cout << "ż���ĸ���Ϊ��" << oCount << "\t" <<  "�����ĸ���Ϊ��" << jCount << endl;

    //��������������Ҫ�����֣�����¼�±�
    int searchnums;//�ȶ�����Ҫ���ҵ�����
    int searchindex = INT_MIN;//���û����Ҫ���ҵ����֣��±�ΪINT_MIN,��˼��������С�����֣���ʵ�����ȼ��費����

    cout << "��������Ҫ���ҵ����֣�" << endl;
    cin >> searchnums;

    for(int i = 0; i < length; i++)
    {
        if(nums[i] == searchnums)
        {
            searchindex = i;
            break;//�ҵ��Ժ�������ѭ��
        }

    }
    if(searchindex == INT_MIN)
    {
        cout << "û����Ҫ������" << endl;
    }else
    {
        cout << "�����±�Ϊ��" << searchindex << endl;
    }

    return 0;
}
