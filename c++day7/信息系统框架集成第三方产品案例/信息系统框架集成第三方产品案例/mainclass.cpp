#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "CSocketProtocol.h"
#include "CSckFactoryImp.h"
#include "CSckFactoryImp2.h"

//����������̿��ʵ�����
int SckSendAndRec(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketSend(in, inlen);
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketRev(out, (int *)outlen);
	if (ret != 0)
	{
		goto End;
	}
End:
	ret = sp->cltSocketDestory();

	return 0;
}

//дһ�����
int main()
{
	int ret = 0;
	unsigned char in[4096]; 
	int inlen;
	unsigned char out[4096]; 
	int outlen = 0;

	strcpy((char *)in, "aaddddddddaaaaa");
	inlen = 9;
	
	
	CSocketProtocol *sp = NULL;
	//sp = new CSckFactoryImp;
	sp = new CSckFactoryImp2;

	ret = SckSendAndRec(sp, in, inlen, out, &outlen);
	if (ret != 0)
	{
		printf("func SckSendAndRec() err:%d \n", ret);
	}
	delete sp;//��ͨ������ָ���ͷ���������������Դ

	cout << "hello..." << endl;
	return 0;
}