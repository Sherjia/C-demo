#include "LandOwner.h"

LandOwner::LandOwner()
{
    SetNikeName("大地主");
    SetSex("保密");
    SetGold(1000);
    SetExp(0);
    cout << "LandOwner()" << endl;
    InitCards();
}
LandOwner::LandOwner(string NikeName):m_NikeName(NikeName)//初始化参数列表的写法，等价于m_NikeName = NikeName
{
    SetSex("保密");
    SetGold(1000);
    SetExp(0);
    cout  << "LandOwner(string NikeName)" << endl;
    InitCards();
}
LandOwner::LandOwner(string nikename,string sex,int gold,long exp):m_NikeName(nikename),m_Sex(sex),m_Gold(gold),m_Exp(exp)
{
    cout << "LandOwner(string nikename,string sex,int gold,long exp)" << endl;
    InitCards();
}
void LandOwner::ShowInfo()
{
    cout << "名称：" << GetNikeName() <<endl;
    cout << "性别:" << GetSex() <<endl;
    cout << "金币:" << GetGold() <<endl;
    cout << "经验值：" << GetExp() <<endl;
}
void LandOwner::InitCards()//初始化currrCards,surplusCrads,packCards
{
    for(int i = 0;i < 54;i++)
    {
        //生成默认的一副牌
        packCards.push_back(i+1);//packCards[i] = i+1
        surplusCards.push_back(packCards.at(i));//surplusCards.push_back(i+1)
    }
    currCards.clear();

    ShowCards(packCards);
    //ShowCards(surplusCards);
}
void LandOwner::ShowCards(const vector<int>& cards)
{
    /*C语言的习惯
    for(int i = 0;i < cards.size();i++)
    {
        cout <<  cards[i] << ",";
    }
    cout << endl;*/

    //使用迭代器写
    /*
    for(vector<int>::const_iterator iter = cards.begin();iter != cards.end(); iter++)//const_iterator就是无法修改内容的迭代器，iter是迭代器的名字
    {
        cout << *iter << ", ";
    }
    cout << endl;*/

    /*使用C++11类型推断
    for(auto iter = cards.begin();iter != cards.end(); iter++)//const_iterator就是无法修改内容的迭代器，iter是迭代器的名字
    {
        cout << *iter << ", ";
    }
    cout << endl;*/

    //for区间遍历
    for(auto card:cards)
    {
       cout << card << ":" << getColour(card) << "-" << getValue(card) << ", ";
    }
     cout << endl;


     //使用算法的方式，将容器的内容复制到cout绑定的迭代器中
     //使用这种方式需要加两个头文件 #include <iterator>   #include <algorithem>
     /*
     copy(cards.cbegin(),cards.cend(),ostream_iterator<int>(cout,", "));
     cout << endl;*/
}
void LandOwner::TouchCard(int cardCount)
{
    srand(time(NULL));//时间种子
    //随机生成一张剩余牌集合中有的牌，添加到currCards集合中，从surplusCards中删除这张牌
    for(int i = 0;i < cardCount;i++)
    {
        int randIndex = rand() % 54;     //0~53之间的随机数字
        //判断：随机生成的这张牌是否在集合中
        if(isContains(packCards[randIndex]))
        {
            currCards.push_back(packCards[randIndex]);//将摸的牌放入当前手牌数组
            //在剩余牌集合中删除这张牌
            deleteCards(surplusCards,packCards[randIndex]);
        }else
        {
            i--;//重新摸牌，相当于上一轮什么都没做
        }
    }
    cout << m_NikeName << "<地主摸牌>-当前手牌如下：" << endl;
    ShowCards(currCards);
    cout << "<地主摸排后>-剩余牌面如下：" << endl;
    ShowCards(surplusCards);
}
bool LandOwner::isContains(int cardNum)
{
    //使用算法查找
    vector<int>::iterator iter = find(surplusCards.begin(),surplusCards.end(),cardNum);
    if(iter != surplusCards.end())
    {
        return true;
    }
        return false;
}
void LandOwner::deleteCards(vector<int>& cardVec, int card)
{
    /*常用写法
    for(auto iter = cardVec.begin(); iter != cardVec.end();)
    {
        if(*iter == card)//如果找到，就删除元素
        {
            *iter = cardVec.erase(iter);//这里返回值指向已删除元素的下一元素
        }else{
            ++iter;//继续判断下一元素是否相同
        }
    }*/
    //使用算法
    auto iter = find(cardVec.begin(),cardVec.end(),card);
        if(iter != cardVec.end())//找到了要删除的元素
        {
            cardVec.erase(iter);//删除一个位置的数据，所以是iter
        }

}
string LandOwner::getColour(int card)//注意此处card不是下标
{
    if(card == 53) return "小王";
    if(card == 54) return "大王";
    string colours[] = {
        "黑桃","红心","方片","梅花"
    };
    return colours[(card - 1) / 13];//card不是下标，所以要减一。具体花色算法有截图

}
string LandOwner::getValue(int card)
{
    if(card == 53) return "Black Jocker";
    if(card == 54) return "Red Jocker";
    string values[] = {
    "A","2","3","4","5","6","7","8","9","10","J","Q","K"
    };
    return values[(card - 1) % 13];
}
LandOwner::~LandOwner()
{
    cout << m_NikeName << "被释放" << endl;//dtor
}
