#ifndef LANDOWNER_H
#define LANDOWNER_H
/*地主类*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class LandOwner
{
    private:
        string m_NikeName;
        string m_Sex;
        int m_Gold;
        long m_Exp;
        vector<int> currCards;//当前玩家的手牌数组
        vector<int> surplusCards;//摸排后，剩余的牌
        vector<int> packCards;//默认的一副牌，1~54
        bool isContains(int);//剩余牌集合中是否包含cardNum这个牌面
        void deleteCards(vector<int>&, int);//删除哪一个集合中的哪一张牌
        string getColour(int);//获得牌面花色
        string getValue(int);//获得牌面



    public:
        LandOwner();
        LandOwner(string);
        LandOwner(string,string,int,long);
        ~LandOwner();

        string GetNikeName() { return m_NikeName; }
        void SetNikeName(string val) { m_NikeName = val; }
        string GetSex() { return m_Sex; }
        void SetSex(string val) { m_Sex = val; }
        int GetGold() { return m_Gold; }
        void SetGold(int val) { m_Gold = val; }
        long GetExp() { return m_Exp; }
        void SetExp(long val) { m_Exp = val; }

        void ShowInfo();
        void TouchCard(int);//摸牌
        void InitCards();//初始化currrCards,surplusCrads,packCards
        void ShowCards(const vector<int>&);//显示集合中的牌面

    protected:


};

#endif // LANDOWNER_H
