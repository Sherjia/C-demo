#include <iostream>
using namespace std;

//�����﷨
//�����쳣֮���ǿ纯����
//��׽���쳣�Ժ�������봦�����Լ���������
//catch�쳣ʱ���������ͽ���catch
//�쳣���ϸ���������ƥ��

void main()
{
	try
	{
		throw 'z';
	}
	catch (int e)
	{
		cout << "����int�����쳣" << endl;
	}
	catch (...)
	{
		cout << "δ֪�����쳣" << endl;
	}
}

void divide(int x, int y)
{
	if (y == 0)
	{
		throw x;//�׳�int�����쳣
	}

	cout << "divide�����" << x / y << endl;
}

void myDivide(int x, int y)
{
	try
	{
		divide(x, y);
	}
	catch (...)//��׽���쳣�Ժ�������봦�����Լ���������
	{
		cout << "�ҽӵ���divide���쳣����û������������" << endl;
		throw;
	}
}

void main21()
{
	try
	{
		//divide(10,2);
		//divide(100, 0);

		myDivide(100, 0);
	}
	catch (int e)
	{
		cout << e << "�����" << endl;
	}
	catch (...)
	{
		cout << "����δ֪�����쳣" << endl;
	}

	cout << "hello..." << endl;
	return;
}