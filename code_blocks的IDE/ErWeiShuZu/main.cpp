#include <iostream>

using namespace std;

int main()
{
   string stu_names[] {"����","����","�ŷ�"};
   string course_names[] {"����","��ѧ","Ӣ��"};
   const int row = 3;
   const int col = 3;
   double score_names[row][col];

   for(int i = 0;i < row;i++)
   {
       for(int j = 0;j < col; j++)
       {
           cout <<stu_names[i]<<"��"<<course_names[j]<<"�ɼ���";
           cin >> score_names[i][j];
       }
   }
    //��ӡ�Ľ��
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
