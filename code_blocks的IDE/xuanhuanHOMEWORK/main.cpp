#include <iostream>

using namespace std;

int main()
{
   int a,b,c,sum = 0;
   double avgsum;
   cout << "请输入该班级的序号：";
   cin >> a;
   cout <<  "请输入该班级的学员总数：";
   cin >> b;
   char answer = 'Y';
   while(answer == 'Y')
   {
       answer = ' ';
       for(int i = 1;i <= b;i++)
       {
           cout <<"请输入学号" << i << "的成绩是：";
           cin >> c;
           sum += c;
       }
       avgsum = sum / b;
       cout << "该班级学员的平均成绩为：" << avgsum << endl;
       cout <<"\n"<<"是否输入另一个班级的成绩（Y/N）";
       cin >> answer;
   }

    return 0;
}
