#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class Test
{
public:
	Test()//���캯��  ��������ɶ����Եĳ�ʼ������
	{
		a = 10;
		p = (char*)malloc(100);
		strcpy(p, "aaaaaf");
		cout << "���ǹ��캯��" << endl;
	}
	void printP()
	{
		cout << a << endl;
		cout << p << endl;
	}
	~Test()
	{
		if (p != NULL)
		{
			free(p);
		}
		cout << "������������" << endl;
	}
private:
	int a;
	char *p;
protected:
};

//������һ����̨���о��������Ϊ
void objplay()
{
	//�ȴ����Ķ�����ͷš��ȵ���t1�Ĺ��캯�����ڵ���t2�Ĺ��캯�����ͷ�ʱ��������t2,��t1
	Test t1;//���ù��캯��
	t1.printP();

	cout << "�ָ���1" << endl;

	Test t2;
	t2.printP();

	cout << "�ָ���2" << endl;
}

void main()
{
	objplay();

	cout << "hello..." << endl;
	return;
}