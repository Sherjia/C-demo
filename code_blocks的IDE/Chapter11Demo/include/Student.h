#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
    public:
        //���캯�������ع������ͨ���������ع�����ͬ
        Student();
        Student(int);//������캯���У�ֻ��һ���Ǵ�Ψһ�Ĳ������ǾͿ����������ã�Student stu4 = 50;
        Student(string ,string );//���ι���

        virtual ~Student();
        void Showinfo();

        string GetName() { return m_Name; }
        void SetName(string val) { m_Name = val; }
        string Getdesc() { return m_desc; }
        void Setdesc(string val) { m_desc = val; }
        int Getage() { return m_age; }
        void Setage(int val)//��װ����
        {
            if(val < 0)
            {
                m_age = 18;
            }
            else
                m_age = val;
        }
        void InitScores(); //��ʼ��ѧ���ɼ����飬Ĭ�Ϸ���һ��Ԫ�ؿռ�
        void AddScores();//��scores���������һ������

    protected:

    private:
        string m_Name;//����m_Name���Ǳ�׼д��
        string m_desc;
        int m_age;
        float* scores;//ѧ���ķ�������
        int scoresCount;//ѧ���ɼ�����

};

#endif // STUDENT_H
