/*��������
ѭ��¼��5��Ԫ�أ����н������к�������

ʱ�䣺2018/9/5                 */
#include <iostream>

using namespace std;

int main()
{
    /*   //����һ��ð������
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
    cout << "���Ϊ��" <<endl;
    for( int i = 0; i < 5;i++)//ʹ��ѭ���������ӡ����
    {
        cout << nums[i] << "\t";
    }                             */
    /*  //��������ѡ������
    int nums[]{15,25,90,23,9};
    int min = nums[0];//�����һ��Ԫ��Ϊ��С��
    int minIndex = 0;//��һ���±�Ԫ��Ϊ0
    int temp;
    int length = sizeof(nums)/sizeof(int);

    for(int i = 0;i < length - 1; i++)
    {
        min = nums[i];
        minIndex = i;
        for(int j = i + 1;j < length ;j++)//����ÿ��Ԫ�ز���������Ƚϣ�����ÿһ��Ԫ�ض������ıȽϣ�������j=i+1.��Ȼ��1��ʼ����ôj<length.
        {
            if(nums[j] < min)
            {
                min = nums[j];
                minIndex = j;
            }
        }
        if(minIndex > i)//��������������Ԫ�رȼ����Ԫ�ػ�С����ô��Ҫ����Ԫ��λ�����ţ��ﵽ�����Ŀ��
        {
            temp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = temp;
        }
    }
    cout <<"���Ϊ��" << endl;
        for(int i = 0;i < length;i++)
        {
            cout << nums[i] << endl;
        }

    //��������
    for(int i = 0;i < length/2; i++)//�����i < length����ô��һ�������һ�������󣬵�ͷ�����һ���ֻ�͵�һ������������ʹһ����±꽻�����ɡ�
    {
       temp = nums[i];//�õ�һ�������һ���������ڶ����뵹���ڶ����������Դ�����
       nums[i] = nums[length - i - 1];
       nums[length - i - 1] = temp;

    }
    cout <<"������Ϊ��" << endl;
        for(int i = 0;i < length;i++)
        {
            cout << nums[i] << endl;
        } */
    //ʵ�������ɾ���Ͳ���
    double power[99];//���鳤��һ��ȷ�����޷����ģ�����
    int powercount = 0;//��ǰ������Ԫ�صĸ���
    power[powercount++] = 42322.35;
    power[powercount++] = 45782;
    power[powercount++] = 40907;
    power[powercount++] = 40706.58;//��ʱpowercountΪ4

    double temp;

    for(int i = 0;i < powercount; i++)//ð������
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
    cout <<"�����";
    for(int i = 0; i < powercount;i++)
    {
        cout << power[i] <<"\t";
    }
    cout << endl;
    //����Ԫ��
    double insertpower;
    int insertindex = 0;//Ĭ�ϲ����λ��Ϊ��һ��

    cout <<"������Ҫ�����Ԫ��"<<endl;
    cin >> insertpower;
    insertindex = powercount;/*����������ֱ�ԭ��������Ԫ�ض�С����ô�ͻ�������һλ��
                                   ����д��һ�䣬ǰ��Insertindex=0��Ĭ�Ϸ��ڵ�һλ������ô���ᱻ���ڵ�һλ*/
    //1.�ҵ���һ���Ȳ������ִ��λ��insertindex
    for(int i=0;i < powercount;i++)
    {
        if(insertpower > power[i])
        {
            insertindex = i;
            break;
        }
    }
    //2.�����һ��Ԫ�ؿ�ʼ�������ָ��Ƶ�����һ��Ԫ����
    for(int i = powercount - 1;i >= insertindex;i--)
    {
        power[i+1] = power[i];
    }
    //3.��Ҫ��������ָ�ֵ���±�Ϊinsertindex��Ԫ��
    power[insertindex] = insertpower;
    //4.���鳤��+1
    powercount++;

    cout <<"�����Ľ��Ϊ��";
    for(int i =0;i < powercount;i++)
    {
        cout <<power[i]<<"\t";
    }
    cout <<endl;
    //ɾ��
    double deletpower;
    int deletindex = INT_MIN;
    cout <<"��������Ҫɾ�������֣�";
    cin >> deletpower;
    //1.�ҵ�Ҫɾ����Ԫ���±�
    for(int i = 0;i < powercount; i++)
    {
        if(deletpower == power[i])
        {
            deletindex = i;
            break;
        }
    }
    if(deletindex == INT_MIN)//����һ�������Ժ����û�ҵ�,��ô�±����INT_MIN
    {
        cout << "û���ҵ�Ҫɾ�������֣�ɾ��ʧ�ܣ�����";
    }
    else
    {
        //2.���ҵ����±꿪ʼ��������һ��Ԫ�ظ�ֵ��ǰ��һ��Ԫ��
          for(int i = deletindex;i < powercount - 1;i++)
        {
            power[i] = power[i+1];
        }
        //3.���鳤��-1
        powercount--;
    }

    cout <<"ɾ����Ľ��Ϊ��";
    for(int i =0;i < powercount;i++)
    {
        cout <<power[i]<<"\t";
    }
    cout <<endl;










    return 0;
}
