#ifndef MYCALC_H_INCLUDED
#define MYCALC_H_INCLUDED

#include <iostream>

using namespace std;

//函数的原型
/**加法*/
double add(double,double);
/**减法*/
double sub(double,double);
/**乘法*/
double multi(double,double);
/**除法*/
double divison(double,double);
/**打印计算结果*/
void print_result(double (*)(double,double),double,double);

//函数的定义
void print_result(double (*ptrCalc)(double,double),double num1,double num2)
{
    double result = ptrCalc(num1,num2);
    cout << "计算结果为：" << result << endl;
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
        cout << "除数不能为0！！！" <<endl;
        return 0;
    }
    return num1 / num2;
}



#endif // MYCALC_H_INCLUDED
