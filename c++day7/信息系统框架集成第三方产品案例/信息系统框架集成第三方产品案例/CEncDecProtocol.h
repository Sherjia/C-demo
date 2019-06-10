#pragma once //类只包含一次

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
	//加密
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen) = 0;
	//解密
	virtual int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen) = 0;

};