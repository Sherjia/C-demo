#include "LandOwner.h"

LandOwner::LandOwner()
{
    SetNikeName("�����");
    SetSex("����");
    SetGold(1000);
    SetExp(0);
    cout << "LandOwner()" << endl;
    InitCards();
}
LandOwner::LandOwner(string NikeName):m_NikeName(NikeName)//��ʼ�������б��д�����ȼ���m_NikeName = NikeName
{
    SetSex("����");
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
    cout << "���ƣ�" << GetNikeName() <<endl;
    cout << "�Ա�:" << GetSex() <<endl;
    cout << "���:" << GetGold() <<endl;
    cout << "����ֵ��" << GetExp() <<endl;
}
void LandOwner::InitCards()//��ʼ��currrCards,surplusCrads,packCards
{
    for(int i = 0;i < 54;i++)
    {
        //����Ĭ�ϵ�һ����
        packCards.push_back(i+1);//packCards[i] = i+1
        surplusCards.push_back(packCards.at(i));//surplusCards.push_back(i+1)
    }
    currCards.clear();

    ShowCards(packCards);
    //ShowCards(surplusCards);
}
void LandOwner::ShowCards(const vector<int>& cards)
{
    /*C���Ե�ϰ��
    for(int i = 0;i < cards.size();i++)
    {
        cout <<  cards[i] << ",";
    }
    cout << endl;*/

    //ʹ�õ�����д
    /*
    for(vector<int>::const_iterator iter = cards.begin();iter != cards.end(); iter++)//const_iterator�����޷��޸����ݵĵ�������iter�ǵ�����������
    {
        cout << *iter << ", ";
    }
    cout << endl;*/

    /*ʹ��C++11�����ƶ�
    for(auto iter = cards.begin();iter != cards.end(); iter++)//const_iterator�����޷��޸����ݵĵ�������iter�ǵ�����������
    {
        cout << *iter << ", ";
    }
    cout << endl;*/

    //for�������
    for(auto card:cards)
    {
       cout << card << ":" << getColour(card) << "-" << getValue(card) << ", ";
    }
     cout << endl;


     //ʹ���㷨�ķ�ʽ�������������ݸ��Ƶ�cout�󶨵ĵ�������
     //ʹ�����ַ�ʽ��Ҫ������ͷ�ļ� #include <iterator>   #include <algorithem>
     /*
     copy(cards.cbegin(),cards.cend(),ostream_iterator<int>(cout,", "));
     cout << endl;*/
}
void LandOwner::TouchCard(int cardCount)
{
    srand(time(NULL));//ʱ������
    //�������һ��ʣ���Ƽ������е��ƣ���ӵ�currCards�����У���surplusCards��ɾ��������
    for(int i = 0;i < cardCount;i++)
    {
        int randIndex = rand() % 54;     //0~53֮����������
        //�жϣ�������ɵ��������Ƿ��ڼ�����
        if(isContains(packCards[randIndex]))
        {
            currCards.push_back(packCards[randIndex]);//�������Ʒ��뵱ǰ��������
            //��ʣ���Ƽ�����ɾ��������
            deleteCards(surplusCards,packCards[randIndex]);
        }else
        {
            i--;//�������ƣ��൱����һ��ʲô��û��
        }
    }
    cout << m_NikeName << "<��������>-��ǰ�������£�" << endl;
    ShowCards(currCards);
    cout << "<�������ź�>-ʣ���������£�" << endl;
    ShowCards(surplusCards);
}
bool LandOwner::isContains(int cardNum)
{
    //ʹ���㷨����
    vector<int>::iterator iter = find(surplusCards.begin(),surplusCards.end(),cardNum);
    if(iter != surplusCards.end())
    {
        return true;
    }
        return false;
}
void LandOwner::deleteCards(vector<int>& cardVec, int card)
{
    /*����д��
    for(auto iter = cardVec.begin(); iter != cardVec.end();)
    {
        if(*iter == card)//����ҵ�����ɾ��Ԫ��
        {
            *iter = cardVec.erase(iter);//���ﷵ��ֵָ����ɾ��Ԫ�ص���һԪ��
        }else{
            ++iter;//�����ж���һԪ���Ƿ���ͬ
        }
    }*/
    //ʹ���㷨
    auto iter = find(cardVec.begin(),cardVec.end(),card);
        if(iter != cardVec.end())//�ҵ���Ҫɾ����Ԫ��
        {
            cardVec.erase(iter);//ɾ��һ��λ�õ����ݣ�������iter
        }

}
string LandOwner::getColour(int card)//ע��˴�card�����±�
{
    if(card == 53) return "С��";
    if(card == 54) return "����";
    string colours[] = {
        "����","����","��Ƭ","÷��"
    };
    return colours[(card - 1) / 13];//card�����±꣬����Ҫ��һ�����廨ɫ�㷨�н�ͼ

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
    cout << m_NikeName << "���ͷ�" << endl;//dtor
}
