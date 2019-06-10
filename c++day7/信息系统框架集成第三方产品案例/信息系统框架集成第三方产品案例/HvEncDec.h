#include <iostream>
using namespace std;

#include"CEncDecProtocol.h"

class HvEncDec : public CEncDecProtocol
{
public:
	//º”√‹
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen);
	//Ω‚√‹
	virtual int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen);
};