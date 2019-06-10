#include <iostream>
using namespace std;
#include "HvEncDec.h"

//加密
int HvEncDec::EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen)
{
	//具体加密代码，视频中已经写好类以及实现类的成员函数，直接导入。此处就不再多写。这个案例主要是学习体会面向对象以及抽象类的编程
	return 0;
}
//解密
int HvEncDec::DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen)
{
	return 0;
}