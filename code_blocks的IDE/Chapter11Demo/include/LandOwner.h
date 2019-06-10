#ifndef LANDOWNER_H
#define LANDOWNER_H
/*������*/
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
        vector<int> currCards;//��ǰ��ҵ���������
        vector<int> surplusCards;//���ź�ʣ�����
        vector<int> packCards;//Ĭ�ϵ�һ���ƣ�1~54
        bool isContains(int);//ʣ���Ƽ������Ƿ����cardNum�������
        void deleteCards(vector<int>&, int);//ɾ����һ�������е���һ����
        string getColour(int);//������滨ɫ
        string getValue(int);//�������



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
        void TouchCard(int);//����
        void InitCards();//��ʼ��currrCards,surplusCrads,packCards
        void ShowCards(const vector<int>&);//��ʾ�����е�����

    protected:


};

#endif // LANDOWNER_H
