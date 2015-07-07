// 素数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


bool isPrime(int tmpNum)
{
	if (tmpNum==1)
	{
		return true;
	}
	
	for (int i=2;i<tmpNum;i++)
	{
		if (tmpNum%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()

{
	int target=100;
	while (target)
	{
		
		if (isPrime(target))
		{
			printf("%d ",target);
		}
		target--;
	}
	return 0;
}

