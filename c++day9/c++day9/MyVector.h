#include <iostream>
using namespace std;

template <typename T>
class MyVetcor
{
	friend ostream& operator<< <T>(ostream& out, const MyVetcor<T> &obj);//������ʱ��operator<<�����<T>������
public:
	MyVetcor(int size = 0);//���캯��
	MyVetcor(const MyVetcor &obj);//�������캯��
	~MyVetcor();//��������

	T& operator[](int index);//a1.operator[i]��������ֵ����ֵ����Ҫ����һ������(Ԫ�ر���������һ��ֵ)������Ҫ֧����ʽ���
	//a3 = a2 = a1;
	MyVector& operator=(const MyVetcor &obj);//��������ֵ����ֵ����Ҫ����һ������(Ԫ�ر���������һ��ֵ)������Ҫ֧����ʽ���

	int getLen()
	{
		return size;
	}
protected:
	T *m_space;
	T m_len;
	int size;
private:
};