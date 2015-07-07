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

 

//分配内存(无法分配内存，因为参数默认是按value传递，生成了pStr的副本)
void getMem(char * pStr)
{
	pStr = (char *)malloc(100 * (sizeof(char)));
}

//正确的分配内存方法(传递指针的引用，即指针的指针)
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

