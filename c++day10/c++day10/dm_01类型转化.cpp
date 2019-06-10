#include <iostream>
using namespace std;
/*
	c++�ṩ������
	static_cast ��̬����ת��
	reinterpret_cast ���½�������
	dynamic_cast ��̬����ת�����縸�������֮��Ķ�̬ת��
	const_cast ������������ȥ��const����
*/
//���ۣ�����ԱҪ�����֪�� ������ת��֮ǰ��ʲô���ͣ�ת��֮����ʲô����
//һ���£��������������ת���������������ת��

void printBuf(const char *p)//const char *p��const���Σ���pָ����ڴ�ռ� ���ֻ������
{
	char *p1 = NULL;
	//����ԱҪ�����֪�� ������ת��֮ǰ��ʲô���ͣ�ת��֮����ʲô����
	//const char* ===> char* //��ֻ������ȥ��
	p1 = const_cast<char *>(p);

	p1[0] = 'Z';//ͨ��p1�� ȥ�޸����ڴ�ռ�
	cout << p << endl;
}

void main()
{
	char buf[] = "adsdssafdssd";
	//����Ա Ҫȷ��p��ָ����ڴ�ռ� ȷʵ���޸� ����������޸ģ�����������Ժ��
	printBuf(buf);//"adsdssafdssd"==>"Zdsdssafdssd"

	//�������־Ͳ����޸� ��Ϊ�����ַ�ָ������ ���ĵ�ַ�����ַ������޷���
	//char *myp = "aanhmklmj";
	//printBuf(myp);

}

class Tree {};

class Animal
{
public:
	virtual void cry() = 0;
protected:
private:
};

class Dog : public Animal
{
public:
	virtual void cry()
	{
		cout << "����" << endl;
	}
	void doHome()
	{
		cout << "����" << endl;
	}
};

class Cat : public Animal
{
public:
	virtual void cry()
	{
		cout << "����" << endl;
	}
	void doThings()
	{
		cout << "ץ����" << endl;
	}
};

void playobj(Animal* base)
{
	base->cry();//��̬3������ 1.�м̳� 2.���麯����д 3.����ָ��ָ���������===>��̬

	//��ʶ���������
	//dynamic_cast����ʱ����ʶ�� RIIT

	Dog *pDog = dynamic_cast<Dog *>(base);//�������������︸��ָ��Dog����ָ��playobj(&d1)����ʶ��ɹ��ˣ��Ͳ�ΪNULL
	if (pDog != NULL)//��ΪNULL��˵��ʶ��ɹ�
	{
		pDog->doHome();//�������Լ����еĹ���
	}

	Cat *pCat = dynamic_cast<Cat *>(base);//������� ===> ������� ����ת��
										  //������ת��С��
	if (pCat != NULL)
	{
		pCat->doThings();
	}
}

void main12()
{
	Dog d1;
	Cat c1;
	playobj(&d1);
	playobj(&c1);
	
	Animal *pBase = NULL;

	//pBase = &d1;
	pBase = static_cast<Animal*>(&d1);//static_cast�����ñ���������ʱ�������ͼ��,�˴��ɹ�

	//ǿ������ת��
	pBase = reinterpret_cast<Animal*>(&d1);
	{
		Tree t1;
		//pBase = static_cast<Animal*>(&t1);//��Treeת��Animal�� c++�����������ͼ�� ��Ч��
		pBase = reinterpret_cast<Animal*>(&t1);//reinterpret_cast ���½���...ǿ����ת����ζ��
	}

	
	
	return;
}


void main11()
{
	double dpi = 3.1415926;

	int num1 = (int)dpi;//c��������ת��
	int num2 = static_cast<int>(dpi);//c++���ľ�̬����ת��
	int num3 = dpi;//c������ ��ʽ����ת���ĵط� ����ʹ��static_cast<>()����ת��

	//char* ===> int *
	/*
	char *p1 = "hello";
	int *p2 = NULL;
	P2 = static_cast<int*>(p1);//ʹ��static_cast<>()������������ʱ���������ͼ�� ���д��� ����ʾ����
	*/
	
	char *p1 = "hello";
	int *p2 = NULL;
	p2 = reinterpret_cast<int*>(p1);//����ͬ����֮�� ����ǿ������ת�� ��reinterpret_cast<>()�������½���
	cout << "p1: " << p1 << endl;//%s "hello"
	cout << "p2: " << p2 << endl;//%d "hello"�ĵ�ַ

	//�ܽ᣺ͨ��static_cast<>()��reinterpret_cast<>()��c++���Ե�ǿ������ת��������

	cout << "hello..." << endl;
	return;
}