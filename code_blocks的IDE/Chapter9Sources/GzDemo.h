#ifndef GZDEMO_H_INCLUDED
#define GZDEMO_H_INCLUDED
//ʹ�ú���������С�������ɼǡ��еĻ������Ե�¼�뼰������
//�������ԣ����������������������¡�����
#include <iostream>

using namespace std;
//��������
void input(int [],int);//�����������Եĺ���
void print(int [],int);//��ӡ�������Եĺ���


//����ʵ��
void input(int values[],int len)//��Ϊ��������ʱ����ʵ���ݵ��������ָ�룬��ô�Ͳ�֪���������м���Ԫ�أ����԰�����ĳ���Ҳ������
{
    if(len > 5)
    {
        cout <<"���鳤��ֻ����5����"<<endl;
        return;//�˳�����ֵΪvoid�ĺ���
    }
    string valueNames[] = {"����","����","����","����","����"};
    for(int i = 0;i < len;i++)
    {
        cout << valueNames[i] << ":";
        cin >> values[i];
    }
}
void print(int values[],int len)
{
    string valueNames[] = {"����","����","����","����","����"};
    for(int i = 0;i < len;i++)
    {
        cout << valueNames[i] << ":" << values[i] <<endl;
    }
}

#endif // GZDEMO_H_INCLUDED
