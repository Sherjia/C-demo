#include "Student.h"

Student::Student()
{
    cout << "默认构造" << endl;//ctor
    InitScores();
}
Student::Student(int age)
{
    Setage(age);
    cout << "带参构造:int age" << endl;
    InitScores();
}
Student::Student(string name,string desc):m_Name(name),m_desc(desc)//初始化参数列表的写法，与m_Name = name;m_desc = desc;一个功能。
{
    //m_Name = name;//等价于 SetName(name)
    //m_desc = desc;
    cout << "带参构造:string name,string desc" << endl;
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
    //1.创建一个新数组，分配scoreCount + 1空间
    //2.复制原数组中的内容放到新数组中
    //3.scoreCount++
    //4.scores指向新数组
    float* newScores = new float[scoreCount + 1];
    memcpy(newScores,score,sizeof(float) * scoresCount);
    scoresCount++;
    scores = newScores;
    delete oldscores;
}
Student::~Student()//通过这个析构函数，栈空间运行完毕后，会自动释放栈内存
{
    cout << m_Name << "被释放" << endl;
    delete this->scores;
}
