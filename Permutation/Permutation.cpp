// Permutation.cpp : �������̨Ӧ�ó������ڵ㡣
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


////k��ʾ��ǰѡȡ���ڼ�������m��ʾ���ж��ٸ���  
//void Permutation(char* pStr, int k, int m)
//{
//	assert(pStr);
//
//	if (k == m)
//	{
//		static int num = 1;  //�ֲ���̬����������ͳ��ȫ���еĸ���  
//		printf("��%d������\t%s\n", num++, pStr);
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
				swap(list[k], list[i]);			//Ϊ�˲��ı�ԭ����	,��֮ǰ�ĸĶ�������
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