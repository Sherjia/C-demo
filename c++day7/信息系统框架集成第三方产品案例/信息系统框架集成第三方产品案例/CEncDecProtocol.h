#pragma once //��ֻ����һ��

#include <iostream>
using namespace std;

class CEncDecProtocol
{
public:
	CEncDecProtocol()
	{
		;
	}
	virtual ~CEncDecProtocol()
	{
		;
	}
	//����
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen) = 0;
	//����
	virtual int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen) = 0;

};