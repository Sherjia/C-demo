#include "Student.h"

Student::Student()
{
    cout << "Ĭ�Ϲ���" << endl;//ctor
    InitScores();
}
Student::Student(int age)
{
    Setage(age);
    cout << "���ι���:int age" << endl;
    InitScores();
}
Student::Student(string name,string desc):m_Name(name),m_desc(desc)//��ʼ�������б��д������m_Name = name;m_desc = desc;һ�����ܡ�
{
    //m_Name = name;//�ȼ��� SetName(name)
    //m_desc = desc;
    cout << "���ι���:string name,string desc" << endl;
    InitScores();
}
void Student::Showinfo()
{
    cout << m_desc << m_Name << endl;
    for(int i = 0;i < scoresCount;i++)
    {
        cout << this->scores[i] << "\t";
    }
    cout << endl;
}
void Student::InitScores()
{
    this->scores = new float[1];
    this->scoresCount = 1;

}
void Student::AddScores(float score)
{
    this->scores[this->scoreCount - 1] = score;
    //1.����һ�������飬����scoreCount + 1�ռ�
    //2.����ԭ�����е����ݷŵ���������
    //3.scoreCount++
    //4.scoresָ��������
    float* newScores = new float[scoreCount + 1];
    memcpy(newScores,score,sizeof(float) * scoresCount);
    scoresCount++;
    scores = newScores;
    delete oldscores;
}
Student::~Student()//ͨ���������������ջ�ռ�������Ϻ󣬻��Զ��ͷ�ջ�ڴ�
{
    cout << m_Name << "���ͷ�" << endl;
    delete this->scores;
}
