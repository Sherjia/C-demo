#include <iostream>
#include "GzDemo.h"//�������Ķ��嵥��д��һ��ͷ�ļ��У����ٽ���ͷ�ļ������뵽main.cpp��
#include "EWDemo.h"//ʹ�ö�ά����������
#include "MyCalc.h"

using namespace std;

//int sum(int,int);//����ԭ�͡�ע��Ҫ�Էֺý�β��
/*void change(int &num)//��ʱʹ����c++�е����ã����ĵײ���ʵ����ָ�룬��ô������������changeʱ�����͵ľ���change�ĵ�ַ����ôִ��num++�󣬽�����͵���������Ϊ11
{                    //���д����int num,��ô����������changeʱ�����͵�num���������ռ���£����Ϊ10��num++��change�ռ���£�����Ӱ���������ռ䡣
    num++;
}*/
void Swap1(int,int);//��һ����ͨ����������
void Swap2(int*, int*);//ʹ��ָ��������
void Swap3(int&, int&);//ʹ������������

int main()
{

    int num1 = 10, num2 = 5;
    Swap1(num1,num2);
    cout << "ִ��Swap1�������ֵ��" << num1 << '\t' << num2 << endl;
    Swap2(&num1,&num2);
    cout << "ִ��Swap2�������ֵ��" << num1 << '\t' << num2 << endl;
    Swap3(num1,num2);
    cout << "ִ��Swap3�������ֵ��" << num1 << '\t' << num2 << endl;



    /*
   double num1,num2;
   char op;
   //���庯��ָ��
   double (*ptrCalc)(double,double);
   cout << "��������������";
   cin >> num1 >> num2;
   cout << "�����������";
   cin >> op;
   switch(op)
   {
        case '+':
            ptrCalc = add;//�������ĺ���ָ��ָ�������Ա����
        break;
        case '-':
             ptrCalc = sub;
        break;
        case '*':
             ptrCalc = multi;
        break;
        case '/':
            ptrCalc = divison;
        break;

   }
   print_result(ptrCalc,num1,num2);
                                    */



   /*
   double arre[2][2] = {
        {22.5,88},
        {89.5,78}
   };
   show(arre,2);
   */



   /*
   int values[5];//����ǰ��������飬�����Ҫ���뺯��������
   input(values,5);
   print(values,5);
   */


    /*
    int num = 10;
    change (num);
    cout << num;
    */


    //���ú���
    /*
    int result = sum(5,6);
    cout << "������Ϊ��" << endl;
    */

    return 0;
}
void Swap1(int num1,int num2)
{
    int temp1;
    temp1 = num1;
    num1 = num2;
    num2 = temp1;
}
void Swap2(int* p1,int* p2)//&num1��&num2����ַ���͹�����p1��p2
{
    int temp2;
    temp2 = *p1;//��ʵ��������num1��num2��ַ�ռ��е�ֵ����Ϊ*p����ȡֵ���ʵnum1��num2ֵû��(��Ϊ������ָ���������������ַ����ַû����)
    *p1 = *p2;
    *p2 = temp2;
}
void Swap3(int& ref1,int& ref2)
{
    //ʹ�����õ�����
    //1.������д���Ӽ��
    //2.����ֱ�Ӵ���ĳ�����󣬶����ǰ�ĳ��������һ��
    //������ǽ�ֹ�������޸�num1��num2��ֵ������������ڲ�����ʹ��const
    //void Swap3(const int& ref1,const int& ref2)����ô��Ҫ�޸�num1��num2ʱ,�������ᱨ��
    int temp3;
    temp3 = ref1;
    ref1 = ref2;
    ref2 = temp3;

}

/*
int sum(int num1,int num2)
{
    //�����������ֵĺ�
    int result = num1 + num2;
    //���ؼ���ֵ
    return result;
}
*/
