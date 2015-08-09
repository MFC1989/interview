// mySort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <functional>
#include <limits>
#include <cstdint>
#include <cmath>
using namespace std;

void showArray(int array[])
{
	for (int i=0;i<10;i++)
	{
		 cout<<array[i]<<" ";
	}
	cout<<endl;
}

void sortArray(int array[])
{
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10-i-1;j++)
		{
			if (array[j]>array[j+1])
			{
				swap(array[j],array[j+1]);
			}
		}
	}
}


void sortArray2(int array[])
{
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10-i-1;j++)
		{
			if (array[j]<array[j+1])
			{
				swap(array[j],array[j+1]);
			}
		}
	}

}

int * testPoint( )
{
	int * p=(int *)malloc(sizeof(int));
	*p=100;
	return p;
}

void printBigger1st(int standard, int n)
{
	if (n>standard)
	{
		printf("%d ", n);
	} 
}

void printBigger2nd(int n,int standard)
{
	if (n > standard)
	{
		printf("%d ", n);
	}
}


bool quickSortWithDupDetect(int* nums, int startP, int endP);

bool containsDuplicate(int* nums, int numsSize) {
	return quickSortWithDupDetect(nums, 0, numsSize - 1);
}

bool quickSortWithDupDetect(int* nums, int startP, int endP)
{
	if (startP >= endP)
		return false;
	int i = startP;
	int j = endP;
	//int currP = startP;
	int key = nums[startP];
	while (i != j){
		while (i < j && key < nums[j])
			--j;
		if (i == j)
			break;
		if (key == nums[j])
			return true;
		nums[i] = nums[j];
		while (i < j && key > nums[i])
			++i;
		if (i == j)
			break;
		if (key == nums[i])
			return true;
		nums[j] = nums[i];
	}
	nums[i] = key;
	return quickSortWithDupDetect(nums, startP, i - 1) || quickSortWithDupDetect(nums, i + 1, endP);

}


template <class T>
void PrintfBinary(T a)
{
	int i;
	for (i = sizeof(a) * 8 - 1; i >= 0; --i)
	{
		if ((a >> i) & 1)
			putchar('1');
		else
			putchar('0');
		if (i % 8 == 0)
			putchar(' ');
	}
	putchar('\n');
}

int gCount = 0;
int getHigh(int n)
{
	int count = 0;
	while (n>0)
	{
		n >>= 1;
		count++;
	}
	gCount = count;
	return count;
}

int getLow(int n)
{
	int count = 0;
	while (n>0)
	{
		if ((n&1)==0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

int f()
{
	int m ;
	int n ;

	cin >> m >> n;
	
	if (m==n) 
	{
		return m;
	}

	int high = getHigh(n);
	if (getHigh(m) != getHigh(n))
	{
		return 0;
	}
	else
	{
		int x = pow(2, high - 1) + pow(2, high - 2);
		if (m<x)
		{
			return pow(2, high - 1);
		}
		else
		{
			return x;
		}
	}
}


int main()
{
	//int myArray[10]={0x00};
	//for (int i=0;i<10;i++)
	//{
	//	myArray[i]=rand()%100;
	//}
	//showArray(myArray);
	//
	//sortArray2(myArray);

	//showArray(myArray);
	
	//char * p=(char *)malloc(3*sizeof(char));
	//p[0]='a';
	//p[1]='a';
	//p[2]='b';

	//for (int i=0;i<3;i++)
	//{
	//	printf("%p\n",p);
	//	p++;
	//}

	/*int a[5];
	int sum=0;*/

	//ifstream MyIfstream;
	//MyIfstream.open(L"a.txt");
	//
	//for (int i=0;i<5;i++)
	//{
	//	MyIfstream>>a[i];
	//	sum+=a[i];
	//}
	//printf("%d",sum/5);

	
	//int * q=testPoint();
	//cout<<*q<<endl;
	//free(q);

	//system("pause");


	//vector<int> vec{ 1, 2, 3, 4 };
	//
	//for_each(vec.begin(), vec.end(), bind1st((printBigger1st), 2));
	//for_each(vec.begin(), vec.end(), bind2nd(ptr_fun(printBigger2nd), 2));

	
	cout << f() << endl;

	return 0;
}

