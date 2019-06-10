#include <iostream>
using namespace std;
#include "CSckFactoryImp.h"


//�ͻ��˳�ʼ�� ��ȡhandle����
int CSckFactoryImp::cltSocketInit(/*out*/)
{
	p = NULL;
	len = 0;
	return 0;
}

//�ͻ��˷�����
int CSckFactoryImp::cltSocketSend(unsigned char *buf/*in*/, int buflen/*in out*/)
{
	p =(unsigned char *)malloc(sizeof(unsigned char) * buflen); //����int *p = (int *)malloc(4)
	if (p == NULL)
	{
		return -1;
	}
	memcpy(p, buf, buflen);
	len = buflen;
	return 0;
}

//�ͻ����ձ���
int CSckFactoryImp::cltSocketRev(unsigned char *buf/*in*/, int *buflen/*in out*/)
{
	if (buf == NULL || buflen == NULL)
	{
		return -1;
	}

	*buflen = this->len;
	memcpy(buf, this->p, this->len);
	return 0;
}

//�ͻ����ͷ���Դ
int CSckFactoryImp::cltSocketDestory()
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
		len = 0;
	}
	return 0;
}