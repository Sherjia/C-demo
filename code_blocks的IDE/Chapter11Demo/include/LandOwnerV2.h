#ifndef LANDOWNERV2_Hlom
#define LANDOWNERV2_H
#include <iostream>

using namespace std;

class LandOwnerV2
{

    long score;  //�����Ļ��֡�������ֱ�����ֵΪ�����ķ���:����Աscore�������ز���װ
    public:
            string name; //����������

            int card[20];//��������������
    public:
        LandOwnerV2();//���캯��������
        ~LandOwnerV2();//��������������

        void TouchCard(int);//�������Ƶķ���
        void ShowScore();//��������ʾ���ֵķ���

        //ʹ�÷���or����ʵ�ֶԳ�Ա�����ķ�װGet/Set����
        void SetScore(long lscore){
                if(lscore < 0)
                {
                    //�������Ļ����ǷǷ����֣���ô����Ĭ��Ϊ0
                    score = 0;
                }else
                {
                    //����Ϊ����ʱ���Ž��и�ֵ����-�����ͨ�������жϣ���װ��score�ĸ�ֵ����
                    score = lscore;
                }
        }
        void Setname(string lname)
        {
            name = lname;
        }
        string Getname()
        {
            return name;
        }


    protected:

};

#endif // LANDOWNERV2_H
