#include <iostream>
using namespace std;

// malloc �� free ��c�ĺ���
// new �� delete ��c++�Ĳ�����
// new �������ͱ���  ����������� ���������
void main1()
{
	//
	int *p = (int *)malloc(sizeof(int));
	*p = 10;
	free(p);

	int *p2 = new int;
	*p2 = 20;//�����������
	free(p2);

	//
	int *p3 = new int(30);
	printf("*p3:%d \n", *p3);
	delete p3;

	cout << "hello..." << endl;
	return;
}

//�����������
void main2()
{
	int *p = (int *)malloc(sizeof(int)* 10);
	p[0] = 1;
	free(p);

	//c++��������
	int *pArray = new int[10];
	pArray[1] = 2;
	delete[] pArray;//���鲻Ҫ����������

	cout << "hello..." << endl;
	return;
}

class Test
{
public:
	Test(int _a)
	{
		a = _a;
		cout << "���캯��" << endl;
	}
	~Test()
	{
		cout << "��������" << endl;
	}
protected:
private:
	int a;
};

//�������
void main()
{
	Test *pT1 = (Test *)malloc(sizeof(Test));//c
	free(pT1);

	//c++
	Test *pT2 = new Test(10);//new�����Զ�ִ����Ĺ��캯����delete�����Զ�ִ���������������malloc��free����
	delete pT2;

	return;

}