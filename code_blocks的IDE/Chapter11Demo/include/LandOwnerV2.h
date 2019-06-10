#ifndef LANDOWNERV2_Hlom
#define LANDOWNERV2_H
#include <iostream>

using namespace std;

class LandOwnerV2
{

    long score;  //地主的积分。解决积分被错误赋值为负数的方法:将成员score进行隐藏并封装
    public:
            string name; //地主的名称

            int card[20];//地主的手牌数组
    public:
        LandOwnerV2();//构造函数的声明
        ~LandOwnerV2();//析构函数的声明

        void TouchCard(int);//声明摸牌的方法
        void ShowScore();//声明的显示积分的方法

        //使用方法or函数实现对成员变量的封装Get/Set方法
        void SetScore(long lscore){
                if(lscore < 0)
                {
                    //如果传入的积分是非法积分，那么积分默认为0
                    score = 0;
                }else
                {
                    //积分为正数时，才进行赋值操作-这里就通过条件判断，封装了score的赋值过程
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
