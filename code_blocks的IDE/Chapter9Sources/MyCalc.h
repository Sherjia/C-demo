#ifndef MYCALC_H_INCLUDED
#define MYCALC_H_INCLUDED

#include <iostream>

using namespace std;

//������ԭ��
/**�ӷ�*/
double add(double,double);
/**����*/
double sub(double,double);
/**�˷�*/
double multi(double,double);
/**����*/
double divison(double,double);
/**��ӡ������*/
void print_result(double (*)(double,double),double,double);

//�����Ķ���
void print_result(double (*ptrCalc)(double,double),double num1,double num2)
{
    double result = ptrCalc(num1,num2);
    cout << "������Ϊ��" << result << endl;
}


double add(double num1,double num2)
{
    return num1 + num2;
}

double sub(double num1,double num2)
{
    return num1 - num2;
}

double multi(double num1,double num2)
{
    return num1 * num2;
}

double divison(double num1,double num2)
{
    if(num2 == 0)
    {
        cout << "��������Ϊ0������" <<endl;
        return 0;
    }
    return num1 / num2;
}



#endif // MYCALC_H_INCLUDED
