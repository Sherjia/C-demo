#include <iostream>
using namespace std;
#include "CSckFactoryImp.h"


//客户端初始化 获取handle上下
int CSckFactoryImp::cltSocketInit(/*out*/)
{
	p = NULL;
	len = 0;
	return 0;
}

//客户端发报文
int CSckFactoryImp::cltSocketSend(unsigned char *buf/*in*/, int buflen/*in out*/)
{
	p =(unsigned char *)malloc(sizeof(unsigned char) * buflen); //类似int *p = (int *)malloc(4)
	if (p == NULL)
	{
		return -1;
	}
	memcpy(p, buf, buflen);
	len = buflen;
	return 0;
}

//客户端收报文
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

//客户端释放资源
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