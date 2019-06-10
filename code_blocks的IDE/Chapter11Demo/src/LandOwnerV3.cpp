#include "LandOwnerV3.h"

LandOwnerV3::LandOwnerV3()
{
    //一般使用构造函数进行成员变量的初始化
    //_name = "默认地主"
    _score = 100;
    //将用户的手牌数组初始化为0
    //memset(cards,0,sizeof(cards));//数组名，要初始化的值，数组的大小
    //cout << "LandOwnerV3的无参构造被调用！" << endl;
    //cout <<"初始化的结果如下： " << endl;
    //cout << "名称：" << _name << endl;
    //cout << "积分：" << _score << endl;
    //cout << "手牌数组：";
    //for(int i = 0;i < sizeof(cards)/sizeof(card[0]); i++)
    //{
     //   cout << cards[i] << endl;
    //}
    //cout << endl;

}

LandOwnerV3::~LandOwnerV3()
{
    //dtor
}
