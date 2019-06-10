#include <iostream>

using namespace std;

int main()
{
   string stu_names[] {"刘备","关羽","张飞"};
   string course_names[] {"语文","数学","英语"};
   const int row = 3;
   const int col = 3;
   double score_names[row][col];

   for(int i = 0;i < row;i++)
   {
       for(int j = 0;j < col; j++)
       {
           cout <<stu_names[i]<<"的"<<course_names[j]<<"成绩：";
           cin >> score_names[i][j];
       }
   }
    //打印的结果
    cout << "\t";
    for(int i = 0;i < col; i++)
    {
        cout << course_names[i] <<"\t";
    }
    cout << endl;
    for(int i = 0;i < row; i++)
    {
        cout << stu_names[i] << "\t";
        for(int j = 0; j < col;j++)
        {
            cout << score_names[i][j] << "\t";
        }
        cout << endl;
    }



    return 0;
}
