#include <iostream>
using namespace std;

//�����õ�֪ʶ�ܹ� 
void main301()
{
	//��ͨ����

	int a = 10;
	int &b = a;
	printf("b:%d \n", b);

	//������
	int x = 20;
	const int &y = x; //������ �� �ñ��� ����ֻ������ ����ͨ��yȥ�޸�x��

	//������ ��ʼ�� ��Ϊ2�����
	//1.�ñ��� ��ʼ�� ������
	{
		int x1 = 20;
		const int &y = x1;
	}
	//2. ������ ��ʼ�� ��������
	{
		const int a = 40; //c++��������a���ڷ��ű���
		//int &m = 41; //��仰��ͨ��,��Ϊ�����������������ڴ�
		const int &m = 41;//������ڴ档��Ϊ���õı��ʾ��Ǹ��ڴ�ȡ������
	}

	cout << "hello..." << endl;
	return;
}
struct Teacher
{
	char name[64];
	int age;
};


void printTeacher(const Teacher &myt)
{
	//������ �� ʵ�α��� ӵ��ֻ������
	printf("myt.age:%d \n", myt.age);
}

void main()
{
	Teacher t1;
	t1.age = 36;

	printTeacher(t1);


	cout << "hello..." << endl;
	return;
}