#include <iostream>

using namespace std;

int main()
{
   int a,b,c,sum = 0;
   double avgsum;
   cout << "������ð༶����ţ�";
   cin >> a;
   cout <<  "������ð༶��ѧԱ������";
   cin >> b;
   char answer = 'Y';
   while(answer == 'Y')
   {
       answer = ' ';
       for(int i = 1;i <= b;i++)
       {
           cout <<"������ѧ��" << i << "�ĳɼ��ǣ�";
           cin >> c;
           sum += c;
       }
       avgsum = sum / b;
       cout << "�ð༶ѧԱ��ƽ���ɼ�Ϊ��" << avgsum << endl;
       cout <<"\n"<<"�Ƿ�������һ���༶�ĳɼ���Y/N��";
       cin >> answer;
   }

    return 0;
}
