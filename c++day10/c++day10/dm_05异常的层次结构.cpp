#include <iostream>
using namespace std;

class MyArray
{
public:
	MyArray(int len);
	int &operator[](int index);
	int getlen();
	~MyArray();

	//д���ڲ������ʽ
	class eSize
	{
	public:
		eSize(int size)
		{
			m_size = size;
		}
		virtual void printErr()
		{
			cout << "size:" << m_size << endl;
		}
	protected:
		int m_size;
	};
	class eNegative : public eSize
	{
	public:
		eNegative(int size) :eSize(size)
		{
			;
		}
		virtual void printErr()
		{
			cout << "eNegative:size:" << m_size << endl;
		}
	};
	class eZero : public eSize
	{
	public:
		eZero(int size) :eSize(size)
		{
			;
		}
		virtual void printErr()
		{
			cout << "eZero:size:" << m_size << endl;
		}
	};
	class eTooBig : public eSize
	{
	public:
		eTooBig(int size) :eSize(size)
		{
			;
		}
		virtual void printErr()
		{
			cout << "eTooBig:size:" << m_size << endl;
		}
	};
	class eTooSmall : public eSize
	{
	public:
		eTooSmall(int size) :eSize(size)
		{
			;
		}
		virtual void printErr()
		{
			cout << "eTooSmall:size:" << m_size << endl;
		}
	};
	

protected:
private:
	int m_len;
	int *m_space;
};



MyArray::MyArray(int len)
{
	if (len < 0)
	{
		throw eNegative(len);
	}
	else if (len == 0)
	{
		throw eZero(len);
	}
	else if (len > 0)
	{
		throw eTooBig(len);
	}
	else if (len < 3)
	{
		throw eTooSmall(len);
	}
	m_len = len;
	m_space = new int[len];
}
MyArray::~MyArray()
{
	if (m_space != NULL)
	{
		delete[] m_space;
		m_space = NULL;
		m_len = 0;
	}
}

int &MyArray::operator[](int index)
{
	return m_space[index];
}

int MyArray::getlen()
{
	return m_len;
}

void main()
{
	try
	{
		MyArray a(-5);
		for (int i = 0; i < a.getlen(); i++)
		{
			a[i] = i + 1;
			printf("%d", a[i]);

		}
	}
	catch (MyArray::eSize &e)
	{
		e.printErr();
	}
	catch (...)
	{

	}

	cout << "hello..." << endl;
	return;
}

//���Ƽ��ı�����
void main51()
{
	try
	{
		MyArray a(-5);
		for (int i = 0; i < a.getlen(); i++)
		{
			a[i] = i + 1;
			printf("%d", a[i]);

		}
	}
	catch (MyArray::eNegative &e)
	{
		cout << "eNegative�����쳣" << endl;
	}
	catch (MyArray::eZero &e)
	{
		cout << "eZero�����쳣" << endl;
	}
	catch (MyArray::eTooBig &e)
	{
		cout << "eTooBig�����쳣" << endl;
	}
	catch (MyArray::eTooSmall &e)
	{
		cout << "eTooSmall�����쳣" << endl;
	}
	catch (...)
	{

	}

	cout << "hello..." << endl;
	return;
}