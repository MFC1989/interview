// AdvanceDebugInVS.cpp : �������̨Ӧ�ó������ڵ㡣
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

