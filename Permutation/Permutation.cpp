// Permutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
using namespace std;
//#include <cstring>

//#include<iostream>  
//using namespace std;
//#include<assert.h>  
//
//void Permutation(char* pStr, char* pBegin)
//{
//	assert(pStr && pBegin);
//
//	if (*pBegin == '\0')
//		printf("%s\n", pStr);
//	else
//	{
//		for (char* pCh = pBegin; *pCh != '\0'; pCh++)
//		{
//			swap(*pBegin, *pCh);
//			Permutation(pStr, pBegin + 1);
//			swap(*pBegin, *pCh);
//		}
//	}
//}
//
//int main(void)
//{
//	char str[] = "ab";
//	Permutation(str, str);
//	return 0;
//}
//


////k表示当前选取到第几个数，m表示共有多少个数  
//void Permutation(char* pStr, int k, int m)
//{
//	assert(pStr);
//
//	if (k == m)
//	{
//		static int num = 1;  //局部静态变量，用来统计全排列的个数  
//		printf("第%d个排列\t%s\n", num++, pStr);
//	}
//	else
//	{
//		for (int i = k; i <= m; i++)
//		{
//			swap(*(pStr + k), *(pStr + i));
//			Permutation(pStr, k + 1, m);
//			swap(*(pStr + k), *(pStr + i));
//		}
//	}
//}
//
//int main(void)
//{
//	char str[] = "abc";
//	Permutation(str, 0, strlen(str) - 1);
//	return 0;
//}


bool isDup(char * pStr,int left,int right)
{
	for (int i = left; i < right;i++)
	{
		char a = pStr[i];
		char b = pStr[right];
		if (a==b)
		{
			return false;
		}
	}
	return true;
}

void perm(char list[], int k, int m)
{
	
	if (k==m)
	{
		puts(list);
	}
	else
	{
		for (int i = k; i <= m;i++)
		{
			if (isDup(list,k,i))
			{
				swap(list[k], list[i]);
				perm(list, k + 1, m);
				swap(list[k], list[i]);			//为了不改变原数组	,将之前的改动换回来
			}
		}

	}
}

int main()
{
	char s[] = "abc";
	perm(s, 0, strlen(s) - 1);

	return 0;
}