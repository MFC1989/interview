// TestDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#pragma comment(lib,"../debug/DLL.lib")
extern  "C" __declspec (dllimport) int add(int ,int);

#include <limits.h>

int _tmain(int argc, _TCHAR* argv[])
{
	 
	printf("%d",add(3,2));
	return 0;
}

