// recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;
const int ARRAYLEN = 9;

//题目地址： http://www.bowdoin.edu/~ltoma/teaching/cs107/spring05/recursion.html

//递归求整数的各位之和
int getSum(int n)
{
	if (n < 10)
	{
		return n;
	}
	else
	{
		int k = n % 10;
		n /= 10;
		return k + getSum(n);
	}

}

//通过递归找到数组中最小的数
int findmin(int a[], int n)
{
	int x = a[n];
	int y;
	if (n > 1)
	{
		y = findmin(a, n - 1);
	}
	else
	{
		y = a[0];
	}

	return min(x, y);
}

int findsum(int a[], int n)
{
	if (n == 0)
	{
		return a[n];
	}
	else
	{
		int k = a[n];
		return k + findsum(a, n - 1);
	}

}

bool ispalindrome(char a[], int n)
{

	//使用迭代法

	//int len = n;
	//for (int i = 0; i <= len / 2;i++)
	//{
	//	if (a[i]!=a[n])
	//	{
	//		return false;
	//	}
	//	n--;
	//}
	//return true;

	//使用递归
	if (n>=0)
	{
		char * p = a + n;
		if (*a!=*p)
		{
			return false;
		}
		else
		{
			a++;
			n -= 2;
			return ispalindrome(a, n);
		}
	}
	
}

//迭代法
bool binSearch(int * a,int n,int num)
{
	int begin = 0;
	int end = n-1;
	while (begin<=end)
	{
		int middle = (begin + end) / 2;

		if (a[middle] == num)
		{
			return true;
		}
		else if (a[middle]<num)
		{
			begin = middle + 1;
		}
		else if (a[middle]>num)
		{
			end = middle - 1;
		}
	}
	return false;
}

bool binSearchRecursion(int * a, int lIndex ,int rIndex, int find)
{
	int mid = (lIndex + rIndex) / 2;
	if (lIndex <= rIndex)
	{
		if (a[mid]==find)
		{
			return true;
		}
		else if (a[mid]<find)
		{
			return binSearchRecursion(a, mid + 1, rIndex, find);
		}else if (a[mid]>find)
		{
			return binSearchRecursion(a, lIndex, mid-1, find);
		}
	}
	return false;
}

int testStaticVar(int x)
{
	//int res;
	//if (x>1)
	//{
	//	res= x + testStaticVar(x - 1);
	//	return res;
	//}
	//else
	//{
	//	return 1;
	//}

	static int res;
	if (x==1)
	{
		return 1;
	}
	
	res =x+ testStaticVar(x - 1);
	return res;
	
}


void reverseShowNum(int n)
{
	printf("%d", n % 10);     

	if ((n / 10) != 0)
	{
		reverseShowNum(n / 10);
	}
}

#include <set>

char findchar(const string & str)
{
	int len = str.size();
	for (int i = len - 1; i >= 0;i--)
    {
		if (std::count(str.begin(),str.end(),str[i])==1)
		{
			return str[i];
		}
    }

	cout << "can't find!" << endl;
	return ' ';
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	int res = getSum(1200);
	int array[ARRAYLEN];
	srand(time(NULL));
	for each (int & var in array)
	{
		var = rand();
	}
	int minimum = findmin(array, ARRAYLEN - 1);

	int tmp = 0;
	for (int i = 0; i < ARRAYLEN; i++)
	{
		array[i] = i;
		tmp += array[i];
	}
	int sum = findsum(array, ARRAYLEN - 1);

	char * str = "abcba";
	bool bRes = ispalindrome(str, strlen(str) - 1);
	int a[3] = { 1, 2, 3 };
	bool bfind = binSearch(a, 3, 3);
	bool bRFind = binSearchRecursion(a, 0, (sizeof(a)/sizeof(int))-1,-1);

	int f=testStaticVar(3);



	return 0;
}

