#include <iostream>
#include <iomanip>//io�������������manip��manipulator��������������д����Ҫ�Ƕ�cin,cout֮���һЩ���������ӣ�����setfill,setw,setbase,setprecision�ȵ�
#include <ctime>//ctime������ �����ں�ʱ��ת��Ϊ�ַ���
#include <vector>
#include <array>
#include <cstdlib>//��Ϊ����srand,������Ҫ��һ��ͷ�ļ�

using namespace std;

int main()
{

    int chioce,temp1,temp2,temp3;
    /**���׵�����*/
    string value_father_name;
    /**Ů��������*/
    string value_daughter_name;
    /**Ů���ĳ����·�*/
    int value_birth_month;
    /**Ů���ĳ�������*/
    int value_birth_date;
    /**Ů��������*/
    string value_daughter_constell;
    /**Ů���Ļ���������Ϣ:���������������������£�����*/
    array<int,5> value_array_baseinfo;
    /**Ů���ĳ�ʼ���*/
    int value_daughter_gold = 500;
    /**�������������*/
    array<string,5> value_array_baseinfo_names = {"����","����","����","����","����"};
    /**�����Ķ�ά����*/
    string constell_names[12][2]={

    {"ɽ����","ˮƿ��"},//һ��
    {"ˮƿ��","˫����"},//����
    {"˫����","������"},//����
    {"������","��ţ��"},//����
    {"��ţ��","˫����"},//����
    {"˫����","��з��"},//����
    {"��з��","ʨ����"},//����
    {"ʨ����","��Ů��"},//����
    {"��Ů��","�����"},//����
    {"�����","��Ы��"},//ʮ��
    {"��Ы��","������"},//ʮһ��
    {"������","ɽ����"} //ʮ����

    };
    cout <<"���׵�����:";
    cin >> value_father_name;
    cout << "Ů����������";
    cin >> value_daughter_name;
    cout << "Ů�������գ�(M D)";
    cin >> value_birth_month >> value_birth_date;


    /**���·ݵĿ���������*/
    int constell_dates[]{20,19,21,20,21,22,23,23,23,24,23,22};//ÿ���������任����һ�죬����1��20�ű�Ϊˮƿ��

    //cout << constell_ names[value_birth_month-1][value_birth_date/constell_dates[value_birth_month-1]] <<endl;
                                                                                                                /*���������Ķ�ά���������������������
                                                                                                                �жϲ����������[value_birth_month-1]��ʾ�����������һ�У�
                                                                                                                [value_birth_date/constell_dates[value_birth_month-1]]��ʾ�����������һ��
                                                                                                                �������������һ�������任����һ�죬������Ϊ0���ڵ�һ�У�����Ϊ1���ǵڶ���*/

    value_daughter_constell = constell_names[value_birth_month-1][value_birth_date/constell_dates[value_birth_month-1]];//Ů��������
    cout <<"Ů������Ϣ��"<<endl;
    cout <<"Ů����������"<<value_daughter_name<<endl;
    cout <<"���գ�1659-"<<value_birth_month<<"-"<<value_birth_date<<endl;
    cout <<"������"<<value_daughter_constell<<endl;

    if(value_daughter_constell == "������"){
        value_array_baseinfo[0] = 80; value_array_baseinfo[1] = 15; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 25; value_array_baseinfo[4] = 11;
    }else if(value_daughter_constell == "��ţ��"){
        value_array_baseinfo[0] = 46; value_array_baseinfo[1] = 30; value_array_baseinfo[2] = 28; value_array_baseinfo[3] = 35; value_array_baseinfo[4] = 20;
    }else if(value_daughter_constell == "˫����"){
        value_array_baseinfo[0] = 50; value_array_baseinfo[1] = 35; value_array_baseinfo[2] = 23; value_array_baseinfo[3] = 26; value_array_baseinfo[4] = 8;
    }else if(value_daughter_constell == "��з��"){
        value_array_baseinfo[0] = 40; value_array_baseinfo[1] = 31; value_array_baseinfo[2] = 33; value_array_baseinfo[3] = 23; value_array_baseinfo[4] = 17;
    }else if(value_daughter_constell == "ʨ����"){
        value_array_baseinfo[0] = 85; value_array_baseinfo[1] = 9;  value_array_baseinfo[2] = 11; value_array_baseinfo[3] = 28; value_array_baseinfo[4] = 20;
    }else if(value_daughter_constell == "��Ů��"){
        value_array_baseinfo[0] = 35; value_array_baseinfo[1] = 28; value_array_baseinfo[2] = 36; value_array_baseinfo[3] = 19; value_array_baseinfo[4] = 18;
    }else if(value_daughter_constell == "�����"){
        value_array_baseinfo[0] = 42; value_array_baseinfo[1] = 33; value_array_baseinfo[2] = 25; value_array_baseinfo[3] = 24; value_array_baseinfo[4] = 32;
    }else if(value_daughter_constell == "��Ы��"){
        value_array_baseinfo[0] = 50; value_array_baseinfo[1] = 25; value_array_baseinfo[2] = 40; value_array_baseinfo[3] = 20; value_array_baseinfo[4] = 18;
    }else if(value_daughter_constell == "������"){
        value_array_baseinfo[0] = 40; value_array_baseinfo[1] = 31; value_array_baseinfo[2] = 15; value_array_baseinfo[3] = 19; value_array_baseinfo[4] = 20;
    }else if(value_daughter_constell == "ɽ����"){
        value_array_baseinfo[0] = 56; value_array_baseinfo[1] = 21; value_array_baseinfo[2] = 16; value_array_baseinfo[3] = 22; value_array_baseinfo[4] = 25;
    }else if(value_daughter_constell == "ˮƿ��"){
        value_array_baseinfo[0] = 43; value_array_baseinfo[1] = 20; value_array_baseinfo[2] = 29; value_array_baseinfo[3] = 25; value_array_baseinfo[4] = 23;
    }else if(value_daughter_constell == "˫����"){
        value_array_baseinfo[0] = 41; value_array_baseinfo[1] = 20; value_array_baseinfo[2] = 29; value_array_baseinfo[3] = 25; value_array_baseinfo[4] = 23;
    }

    for(int i = 0;i < 5;i++)
    {
        cout << value_array_baseinfo[i] << '\t';
    }
    cout << endl;
    //��Ϸ����ѭ����ʼ
    for(int year = 1659;year < 1659+7;year++)
    {
        for(int month = (year == 1659)?6:1;month <= 12;month++){
            //�жϱ����Ƿ���Ů��������
            if(month == value_birth_month){
                cout << "������" << value_daughter_name << "���գ�Ҫ��Ҫ�����" << endl;
            }
        //��ʾ��Ϸ���˵�
        cout << "\n1.�鿴״̬\n2.�����г�\n3.����̸��\n4.�浵\n5.����" <<endl;
        cin >>chioce;
        switch(chioce){
        case 1://�鿴״̬
            cout <<"Ů������Ϣ��"<<endl;
            cout <<"Ů����������"<<value_daughter_name<<endl;
            cout <<"���գ�1659-"<<value_birth_month<<"-"<<value_birth_date<<endl;
            cout <<"������"<<value_daughter_constell<<endl;
            cout <<"���" <<value_daughter_gold<<endl;
            //��ӡ��������
            cout << left;//ȫ�������
            for(int i = 0;i < 5;i++){
                cout << value_array_baseinfo_names[i] << ":" << setw(2) << value_array_baseinfo[i];//setw(2)���ÿ��Ϊ2
                //����ʵ�ķ��������
                int SolidCount = value_array_baseinfo[i] / 10;//ȡ�̣�ʮλ�Ƕ��پ��ж��ٸ�ʵ�ķ���
            for(int j=0;j <= 10;j++){
                if(j < SolidCount){//��Ϊj��0��ʼ�����Դ�ʱҪj<SolidCount
                    cout << "��";
                }
                else{
                    cout << "��";
                }
              }
              cout <<endl;
            }
            break;
        case 2:{//case�����붨������Ļ�����{}
            string month_parths[] = {"��Ѯ","��Ѯ","��Ѯ"};
            for(int i = 0;i < 3;i++){
                cout << "-- " << month << "��--" << month_parths[i] << endl;
                cout <<"\n1.ѧϰ����\n2.��˽��\n3.ѧϰ��\n4.��������\n5.��׬Ǯ"<<endl;
                cout <<"��ѡ��";
                cin >> chioce;
                //������Ҫ�жϣ���ûǮ�������ǿ�ƴ�
                srand(time(NULL));//�����������������Ϊrand�����ṩ��ͬ������ֵ������������ͬ�����������
                if(chioce == 1){//��������������������Ǯ
                    value_array_baseinfo[0] += temp1 = rand() % 11;//Ϊ����ʾ��������ֵ���ֵ�Ƕ��٣�����������temp1������ʾ��
                    value_array_baseinfo[3] += temp2 = rand() % 11;
                    value_daughter_gold -= temp3 = rand() % 51;//��Ϊ������Ҫ��1��10�����Զ���11��51(��ʼ��ǮΪ500)ȡ�ࣻ
                    cout << "ѧϰ���޼ɺð���" <<endl;
                    cout << "����ֵ��" << temp1 << "��������" << temp2 << "��Ǯ����" << temp3 <<endl;
                }else if(chioce == 5){
                    value_daughter_gold += temp3 = rand() % 101;//ͬ����Ҫ�ý��׬��1��100�����Զ�101ȡ�ࡣ
                    cout << "ͨ����׬���ˣ�" << value_daughter_gold << endl;
                }
            }
        }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;

         }
        }
    }
       //��������ֵ�����ж���Ϸ���
        /*Ů�� ��������2000����
          ���� 1800~2000
          Ů���� 1600~1800
          �ʼ�ѧԺ�ܲ� 1200~1600 ������� ������>����
          ���� 1200~1600 ������� ��������������
          ������ʿ�ų� 1200~1600 ������� ���ʴ�������
          �߼���˾ 1200~1600 ������� ������>����
          �����ĳ��� 1200~1600 ������� ������>����
        */
        int sum;
        for(int i = 0;i < 5;i++){
            sum += value_array_baseinfo[0];
        }
        if(sum >= 2000){
            cout << "��Ϸ���Ž�����ǻ�ΪŮ������" << endl;
        }else if(sum >= 1800 && sum < 2000){
            cout << "��Ϊ����" <<endl;
        }else if(sum >= 1200 && sum <1600){//�߼���˾ 1200~1600 ������� ������>����
            int MaxValue = value_array_baseinfo[0];
            int MaxIndex = 0;
            for(int i =1;i < 5;i++){
                    if(MaxValue < value_array_baseinfo[i]){
                        MaxValue = value_array_baseinfo[i];
                        MaxIndex = i;
                    }

            }
            if("����" == value_array_baseinfo_names[MaxIndex] && value_array_baseinfo[2] > value_array_baseinfo[4]){
                cout <<value_daughter_name << "��Ϊ�߼���˾" << endl;
            }

        }

















    return 0;
}
