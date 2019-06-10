#include "LandOwnerV2.h"

LandOwnerV2::LandOwnerV2()
{
    //ctor
}
//实现摸牌方法
void LandOwnerV2::TouchCard(int cardcount)//::名称是作用域解析运算符
{
    cout << name << "摸了" << cardcount << "张牌" <<endl;
}
void LandOwnerV2::ShowScore()
{
    cout << name << "的" << "积分是" << score <<endl;
}

LandOwnerV2::~LandOwnerV2()
{
    //dtor
}
