#include <iostream>
using namespace std;


template <typename T>
class Complex;//���ǰ������

template <typename T>
Complex<T> MySub(Complex<T> &c1, Complex<T> &c2);

template <typename T>
class Complex
{
	friend Complex<T> MySub<T>(Complex<T> &c1, Complex<T> &c2);//������Ԫ����

	friend ostream& operator<< <T>(ostream& out, Complex& c3);//��Ϊ��Ԫ��������Ϊ��<<���������ʱ��Ҫ����Complex���˽�����ԣ�a,b
public:
	Complex(T a, T b);
	void printCom();
	Complex operator+(Complex &c2);
	Complex operator-(Complex &c2);
protected:
private:
	T a;
	T b;
};

//���캯��д��������ⲿ
template <typename T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

template <typename T>
void Complex<T>::printCom()
{
	cout << "a" << a << " b" << b << endl;
}

//������ ģ�������� �������ɵ� ��һ�����ɵ��Ǻ���ͷ �͵ڶ��������ĺ���ͷ��һ�� 
//��Ա���� ʵ��+���������
template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c2)//ע���ʱ�����ķ���ֵ��Ҫ<T>����Ϊ���ص���һ��Ԫ�أ������Ĳ���Ҳ��Ҫ<T>
{
	Complex tmp(a + c2.a, b + c2.b);//Complex<T> tmp(a + c2.a, b + c2.b);����Ĳ������б�<T>���Բ��ӣ���Ϊ�����Ѿ�����
	return tmp;
}

//��Ա���� ʵ��-���������
template <typename T>
Complex<T> Complex<T>::operator-(Complex<T> &c2)
{
	Complex tmp(a - c2.a, b - c2.b); //Complex tmp(this->a - c2.a, this->b - c2.b);
	return tmp;
}

/*
dm_08������_���к�����д������ⲿ(��һ��cpp��).obj : error LNK2019: �޷��������ⲿ����
"class std::basic_ostream<char,struct std::char_traits<char> > & __cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> > &,class Complex<int> &)" (??6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@AAV?$Complex@H@@@Z)
�÷����ں��� _main �б�����

��������������еĺ��������е����������<<�ұ߼��ϲ������б�<T>,����13������
*/
//��Ԫ���� ʵ��<<���������
template <typename T>
ostream& operator<<(ostream& out, Complex<T>& c3)
{
	out << c3.a << " + " << c3.b << "i" << endl;
	return out;
}

////////////////////////////////////////////////////////////////////
//������Ԫ���� �ᱨ��
//��������н�ͼ ����5��9���Լ�14�е�д�������ǲ�����������������Ԫ����������
template <typename T>
Complex<T> MySub(Complex<T> &c1, Complex<T> &c2)//������Ԫ����
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
//���ۣ���Ҫ������Ԫ����



//��������ص�����д��
//����<<��>>ֻ������Ԫ������������������أ���ҪдΪ��Ա����,��Ҫ������Ԫ����
/*
ostream& operator<<(ostream& out, Complex& c3)
{
out << "a: " << c3.a << " b:" << c3.b << endl;
return out;
}
*/
void main()
{
	//��Ҫ��ģ������廯�Ժ󣬲��ܶ������ c++��������Ҫ�����ڴ�
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;
	//Complex operator+(Complex &c2);��Ա����ʵ��+�����������

	cout << c3 << endl;
	//ostream& operator<<(ostream& out, Complex& c3);<<ֻ����ȫ�ֺ���ʵ�����أ����һ�Ҫ�趨Ϊ�����Ԫ����

	//������Ԫ����
	{
		Complex<int> c4 = MySub(c1, c2);
		cout << c4 << endl;
	}

	cout << "hello..." << endl;
	return;
}