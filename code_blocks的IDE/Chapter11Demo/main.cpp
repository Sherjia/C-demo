#include <iostream>
#include "LandOwner.h"
#include "Student.h"

using namespace std;

int main()
{
    /*
    Student* ptrStu1 = new Student("一无所有","王健林");

    ptrStu1->AddScores(78.9f);
    ptrStu1->Showinfo();*/



    LandOwner* ptr_LandOwner1 = new LandOwner();//指针方式，全部在堆内存中
    LandOwner* ptr_LandOwner2 = new LandOwner("专业斗地主");//你输入的是什么类型参数的函数，编译器就自动调用相应的。这相当于函数重载
    LandOwner* ptr_LandOwner3 = new LandOwner("大魔王地主");

    ptr_LandOwner1->ShowInfo();
    ptr_LandOwner2->ShowInfo();
    ptr_LandOwner3->ShowInfo();

    ptr_LandOwner3->TouchCard(3);



    delete ptr_LandOwner1;//释放堆内存
    delete ptr_LandOwner2;
    delete ptr_LandOwner3;

    /*这是用栈内存的方式来调用,效果与以上相同
        LandOwner landowner2;
        landowner2.SetNikeName("周扒皮");
        landowner2.TouchCard(3)
        //或者这样写
        LandOwner landowner3("周扒皮");
    */

    /*
     输出结果：
     LandOwner()
     名称是：专业斗地主LandOwner(string NikeName)
     名称是：大魔王地主LandOwner(string NikeName)
     名称：大地主
     性别:保密
     金币:1000
     经验值：0
     名称：专业斗地主
     性别:保密
     金币:1000
     经验值：0
     名称：大魔王地主
     性别:保密
     金币:1000
     经验值：0
     大地主被释放
     专业斗地主被释放
     大魔王地主被释放

    */





    /*
    Student stu1;//在栈内存里分配空间
    Student stu2("马化腾","普通家庭");//你输入的是什么类型参数的函数，编译器就自动调用相应的。这相当于函数重载
    Student stu3(45);
    Student stu4 = 50;
    stu2.Showinfo();

    Student* stu5 = new Student("杰克马","悔创阿里");//这是一个指针变量，所以用new的方式动态分配内存，同时调用他的构造函数
    stu5->Showinfo();//stu5是一个指针，所以访问属性使用这种方式。这是在堆内存中分配空间

    delete stu5;//当对象使用完毕时，记得delete,释放内存！
    */

    /*
    LandOwnerV2 LandOwner2;//声明一个LandOwnerV2类型的变量-LandOwner2
    //LandOwner2.name = "于谦";//调用LandOwner2中的变量，并赋值；因为name是public中的，所以可以调用
    LandOwner2.Setname("于谦");
    LandOwner2.TouchCard(5);//调用LandOwner2中的函数
    //LandOwner2.score = -100;为了不显示非法积分，要提前对score进行封装
    LandOwner2.SetScore(100);//使用方法(函数)的方式进行了封装，所谓封装就是提前使用方法进行了一个判断
    LandOwner2.ShowScore();
    cout << LandOwner2.Getname() << endl;
    LandOwnerV3 LandOwner3;
    */

    return 0;
}
