#include <iostream>
#include<vector>/*ʹ��vector��������ͷ�ļ�*/
#include<algorithm>/*��ͷ�ļ���˼Ϊ�㷨*/

using namespace std;

int main()
{
    vector<double> vecDouble = {98.5,67.8,58.6,78.3};//��������
    vecDouble.push_back(100.8);//������β������һ������
    //����1
    for(int i = 0;i < vecDouble.size();i++)//size()��˼Ϊ���ش�����ĳ���
    {
        cout << vecDouble[i] << endl;
    }//�������ַ�������ͨ�ã�����ʹ���������ַ���
    cout << endl;

    //���ϵ�ͨ�ñ���������ʹ�õ����� iterator
    //�����ǵ������Ļ����÷�������Ԥ����
    vector<double>::iterator it;//�õ�����������-ʵ������һ��ָ�����
    //�ӵ�һ��Ԫ�ؿ�ʼ����
    for(it = vecDouble.begin(); it!=vecDouble.end();++it)//���begin��end����vector�еĺ����������൱�ڹ���
    {
        cout << *it << endl;
    }
    cout << endl;
    //����,���ǵ���ͷ�ļ���algorithm���㷨
    sort(vecDouble.begin(),vecDouble.end());
    //����
    reverse(vecDouble.begin(),vecDouble.end());
    for(it = vecDouble.begin(); it!=vecDouble.end();++it)
    {
        cout << *it << endl;
    }




    return 0;
}
