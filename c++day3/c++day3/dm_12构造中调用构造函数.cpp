#include <iostream>
using namespace std;

//�ڹ��캯���е��ù��캯������һ��Σ�յ���Ϊ
class MyTest
{
public:
	MyTest(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	MyTest(int a, int b)
	{
		this->a = a;
		this->b = b;

		MyTest(a, b, 100);//��������һ�����������������ھ�����һ�䣬֮�������������������������c���ղ���100���Ǹ�����
	}
	~MyTest()
	{
		printf("~MyTest:%d, %d,%d\n", a, b, c);
	}
protected:
private:
	int a, b, c;
public:
	int getC() const { return c; }
	void setC(int val) { c = val; }
};

int main()
{
	MyTest t1(1, 2);

	cout <<"c:%d"<< t1.getC() << endl;//c�Ƕ��٣�����������
	return 0;
}