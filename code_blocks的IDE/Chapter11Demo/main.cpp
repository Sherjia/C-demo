#include <iostream>
#include "LandOwner.h"
#include "Student.h"

using namespace std;

int main()
{
    /*
    Student* ptrStu1 = new Student("һ������","������");

    ptrStu1->AddScores(78.9f);
    ptrStu1->Showinfo();*/



    LandOwner* ptr_LandOwner1 = new LandOwner();//ָ�뷽ʽ��ȫ���ڶ��ڴ���
    LandOwner* ptr_LandOwner2 = new LandOwner("רҵ������");//���������ʲô���Ͳ����ĺ��������������Զ�������Ӧ�ġ����൱�ں�������
    LandOwner* ptr_LandOwner3 = new LandOwner("��ħ������");

    ptr_LandOwner1->ShowInfo();
    ptr_LandOwner2->ShowInfo();
    ptr_LandOwner3->ShowInfo();

    ptr_LandOwner3->TouchCard(3);



    delete ptr_LandOwner1;//�ͷŶ��ڴ�
    delete ptr_LandOwner2;
    delete ptr_LandOwner3;

    /*������ջ�ڴ�ķ�ʽ������,Ч����������ͬ
        LandOwner landowner2;
        landowner2.SetNikeName("�ܰ�Ƥ");
        landowner2.TouchCard(3)
        //��������д
        LandOwner landowner3("�ܰ�Ƥ");
    */

    /*
     ��������
     LandOwner()
     �����ǣ�רҵ������LandOwner(string NikeName)
     �����ǣ���ħ������LandOwner(string NikeName)
     ���ƣ������
     �Ա�:����
     ���:1000
     ����ֵ��0
     ���ƣ�רҵ������
     �Ա�:����
     ���:1000
     ����ֵ��0
     ���ƣ���ħ������
     �Ա�:����
     ���:1000
     ����ֵ��0
     ��������ͷ�
     רҵ���������ͷ�
     ��ħ���������ͷ�

    */





    /*
    Student stu1;//��ջ�ڴ������ռ�
    Student stu2("����","��ͨ��ͥ");//���������ʲô���Ͳ����ĺ��������������Զ�������Ӧ�ġ����൱�ں�������
    Student stu3(45);
    Student stu4 = 50;
    stu2.Showinfo();

    Student* stu5 = new Student("�ܿ���","�ڴ�����");//����һ��ָ�������������new�ķ�ʽ��̬�����ڴ棬ͬʱ�������Ĺ��캯��
    stu5->Showinfo();//stu5��һ��ָ�룬���Է�������ʹ�����ַ�ʽ�������ڶ��ڴ��з���ռ�

    delete stu5;//������ʹ�����ʱ���ǵ�delete,�ͷ��ڴ棡
    */

    /*
    LandOwnerV2 LandOwner2;//����һ��LandOwnerV2���͵ı���-LandOwner2
    //LandOwner2.name = "��ǫ";//����LandOwner2�еı���������ֵ����Ϊname��public�еģ����Կ��Ե���
    LandOwner2.Setname("��ǫ");
    LandOwner2.TouchCard(5);//����LandOwner2�еĺ���
    //LandOwner2.score = -100;Ϊ�˲���ʾ�Ƿ����֣�Ҫ��ǰ��score���з�װ
    LandOwner2.SetScore(100);//ʹ�÷���(����)�ķ�ʽ�����˷�װ����ν��װ������ǰʹ�÷���������һ���ж�
    LandOwner2.ShowScore();
    cout << LandOwner2.Getname() << endl;
    LandOwnerV3 LandOwner3;
    */

    return 0;
}
