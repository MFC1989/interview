// AdvanceDebugInVS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
using namespace std;

void testBreakPoint()
{
	for (int i = 0; i < 10;i++)
	{
		printf("%d", i);
	}
}

int main()
{
	testBreakPoint();
	return 0;
}

