// memManage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

 

//�����ڴ�(�޷������ڴ棬��Ϊ����Ĭ���ǰ�value���ݣ�������pStr�ĸ���)
void getMem(char * pStr)
{
	pStr = (char *)malloc(100 * (sizeof(char)));
}

//��ȷ�ķ����ڴ淽��(����ָ������ã���ָ���ָ��)
void getMem1(char ** pStr)
{
	*pStr = (char *)malloc(100 * (sizeof(char)));
}


struct MyStruct
{
	int a;
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	//char * p = NULL;
	//int *pi;
	////printf("%d",sizeof(pi));
	//getMem1(&p);
 

	return 0;
}

