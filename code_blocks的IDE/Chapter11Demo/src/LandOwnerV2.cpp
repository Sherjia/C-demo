#include "LandOwnerV2.h"

LandOwnerV2::LandOwnerV2()
{
    //ctor
}
//ʵ�����Ʒ���
void LandOwnerV2::TouchCard(int cardcount)//::��������������������
{
    cout << name << "����" << cardcount << "����" <<endl;
}
void LandOwnerV2::ShowScore()
{
    cout << name << "��" << "������" << score <<endl;
}

LandOwnerV2::~LandOwnerV2()
{
    //dtor
}
