#include <iostream>
#include "GzDemo.h"//将函数的定义单独写在一个头文件中，在再将此头文件，引入到main.cpp中
#include "EWDemo.h"//使用二维数组做参数
#include "MyCalc.h"

using namespace std;

//int sum(int,int);//函数原型。注意要以分好结尾。
/*void change(int &num)//此时使用了c++中的引用，它的底层其实就是指针，那么在主函数调用change时，发送的就是change的地址，那么执行num++后，结果发送到主函数，为11
{                    //如果写的是int num,那么主函数调用change时，发送的num是主函数空间的事，结果为10；num++是change空间的事，不会影响主函数空间。
    num++;
}*/
void Swap1(int,int);//用一个普通函数来交换
void Swap2(int*, int*);//使用指针来交换
void Swap3(int&, int&);//使用引用来交换

int main()
{

    int num1 = 10, num2 = 5;
    Swap1(num1,num2);
    cout << "执行Swap1交换后的值：" << num1 << '\t' << num2 << endl;
    Swap2(&num1,&num2);
    cout << "执行Swap2交换后的值：" << num1 << '\t' << num2 << endl;
    Swap3(num1,num2);
    cout << "执行Swap3交换后的值：" << num1 << '\t' << num2 << endl;



    /*
   double num1,num2;
   char op;
   //定义函数指针
   double (*ptrCalc)(double,double);
   cout << "请输入两个数：";
   cin >> num1 >> num2;
   cout << "请输入运算符";
   cin >> op;
   switch(op)
   {
        case '+':
            ptrCalc = add;//让声明的函数指针指向函数，以便调用
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
   int values[5];//调用前定义的数组，这就是要输入函数的数组
   input(values,5);
   print(values,5);
   */


    /*
    int num = 10;
    change (num);
    cout << num;
    */


    //调用函数
    /*
    int result = sum(5,6);
    cout << "计算结果为：" << endl;
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
void Swap2(int* p1,int* p2)//&num1和&num2将地址发送过来给p1、p2
{
    int temp2;
    temp2 = *p1;//其实交换的是num1和num2地址空间中的值，因为*p可以取值嘛。其实num1和num2值没变(因为他俩是指针变量，是两个地址，地址没交换)
    *p1 = *p2;
    *p2 = temp2;
}
void Swap3(int& ref1,int& ref2)
{
    //使用引用的理由
    //1.代码书写更加简便
    //2.可以直接传递某个对象，而不是把某个对象复制一份
    //如果我们禁止函数来修改num1和num2的值，解决方案：在参数中使用const
    //void Swap3(const int& ref1,const int& ref2)。那么想要修改num1和num2时,编译器会报错。
    int temp3;
    temp3 = ref1;
    ref1 = ref2;
    ref2 = temp3;

}

/*
int sum(int num1,int num2)
{
    //计算两个数字的和
    int result = num1 + num2;
    //返回计算值
    return result;
}
*/
