#include <iostream>
using namespace std;

//��д ���� �ض���
//��д������2����֮��
//���ر�����һ����֮��

//��д��Ϊ2��
//1.�麯����д ��Ҫ������̬
//2.���麯����д���ض��壩

class Parent
{
	//�����������������ع�ϵ
public:
	void abc()//û��virtual�ؼ��֣�������д�еĺ����ض���
	{
		printf("abc");
	}
	virtual void func()
	{
		cout << "func() do..." << endl;
	}
	virtual void func(int i)
	{
		cout << "func() do..." <<i<< endl;
	}
	virtual void func(int i, int j)
	{
		cout << "func() do..." << i <<" "<<j<< endl;
	}
	virtual void func(int i, int j, int k, int n)
	{
		cout << "func() do..." << i << " " << j << endl;
	}
protected:
private:
};

class Child : public Parent
{
public:
	void abc()//û��virtual�ؼ��֣�������д�еĺ����ض���
	{
		printf("child abc");
	}
	void abc(int l, int m, int n)
	{
		printf("child lmn");
	}
	virtual void func(int i, int j)
	{
		cout << "func(int i, int j) do..." << i << " " << j << endl;
	}
	virtual void func(int i, int j, int k)
	{
		cout << "func(int i, int j, int k) do..." << endl;
	}
protected:
private:
};


void main()
{
	// error C2661: ��Child::func��: û�����غ������� 0 ������
	Child c1;
	//c1.func()  //����
	c1.Parent::func();//��ȷ����ʽ�ص���һ��
	//func���������֣��������з��������Ƶĸ��ǣ����ຯ�������֣�ռ���˸��ຯ�������ֵ�λ��
	//��Ϊ�������Ѿ�����func���ֵ�������ʽ
	//��������ʼ����������func����...����û��0��������func����

	
	//1.c++����������func���ƣ����������Ѿ����ڣ����Ƹ��ǣ������Ա���������ȥ�Ҹ����4��������func����
	//2.c++������ֻ���������в���func�������ҵ�����func��һ����2�������ģ�һ����3��������
	//3.c++��������ʼ����error C2661: ��Child::func��: û�����غ������� 4 ������
	//������ø����func������ֻ����ʽ�ص��ã�c1.Parent::func(1, 2, 3,4);
	//c1.func(1, 2, 3,4);  //����

	
	
	//�����޷����ظ���ĺ���������ͬ��������������
	//����Ҫ��ͬһ��֮��
	//c1.abc(1, 2, 3);  //����
	

	cout << "hello..." << endl;
	return;
}