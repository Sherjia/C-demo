#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
    public:
        //构造函数的重载规则和普通函数的重载规则相同
        Student();
        Student(int);//如果构造函数中，只有一个是带唯一的参数，那就可以这样调用：Student stu4 = 50;
        Student(string ,string );//带参构造

        virtual ~Student();
        void Showinfo();

        string GetName() { return m_Name; }
        void SetName(string val) { m_Name = val; }
        string Getdesc() { return m_desc; }
        void Setdesc(string val) { m_desc = val; }
        int Getage() { return m_age; }
        void Setage(int val)//封装年龄
        {
            if(val < 0)
            {
                m_age = 18;
            }
            else
                m_age = val;
        }
        void InitScores(); //初始化学生成绩数组，默认分配一个元素空间
        void AddScores();//向scores数组中添加一个分数

    protected:

    private:
        string m_Name;//这种m_Name就是标准写法
        string m_desc;
        int m_age;
        float* scores;//学生的分数数组
        int scoresCount;//学生成绩个数

};

#endif // STUDENT_H
