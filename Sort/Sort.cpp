// Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <stdlib.h>
#include <utility>
#include <iostream>
using namespace std;

void mSwap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void mSwapByRef(int &a,int &b)
{
	//int tmp=a;
	//a=b;
	//b=tmp;
	a=a^b;
	b=a^b;
	a=a^b;
}

void bubbleSort(int tArray[],int len)
{
	int i,j;
	for ( i=0;i<len;i++)
	{
		for (j=1;j<len-i;j++)
		{
			if (tArray[j]<tArray[j-1])
			{
				int tmp=tArray[j];
				tArray[j]=tArray[j-1];
				tArray[j-1]=tmp;
			}
		}
	}
}


void InsertSort(int tArray[],int len)
{
	int i,j,tmp;
	for ( i=1;i<len;i++)
	{
		tmp=tArray[i];
		for (j=i-1;j>=0&&tArray[j]>tmp;--j )
		{
			tArray[j+1]=tArray[j];
		}
		tArray[j+1]=tmp;
	}
}


void ShellSort(int tArray[],int len)
{
	int i,j,flag,tmp;
	flag=len/2;
	while (flag>=1)
	{
		for (i=flag;i<len;i++)
		{
			tmp=tArray[i];
			j=i-flag;
			while (j>=0&&tArray[j]>tmp)
			{
				tArray[j+flag]=tArray[j];
				j=j-flag;
			}
			tArray[j+flag]=tmp;
		
		}
		flag/=2;
	}

}

void SelectSort(int tArray[],int len)
{
	int i,j,flag;
	for ( i=0;i<len-1;i++)
	{
		flag=i;
		for ( j=i+1;j<len;j++)
		{
			if (tArray[flag]>tArray[j])
			{
				flag=j;
			}
		}

			//tmp=tArray[i];
			//tArray[i]=tArray[flag];
			//tArray[flag]=tmp;
			mSwapByRef((tArray[i]),(tArray[flag]));
	}


}

void QuickSort(int a[], int first,int last)
{

	/*if (left<right)
	{
		int i = left;
		int j = right;
		int x = tArray[left];
		while (i<j)
		{
			while (i<j&&tArray[j]>=x)
			{
				j--;
			}

			if (i<j)
			{
				tArray[i] = tArray[j];
				i++;
			}

			while (i<j&&tArray[i]<x)
			{
				i++;
			}
			if (i<j)
			{
				tArray[j] = tArray[i];
				j--;
			}

			tArray[i] = x;
			QuickSort(tArray, left,i - 1);
			QuickSort(tArray, i + 1, right);
		}
	}*/
	
	if (last <= first)
	{
		return;
	}
	int pivot = a[first];
	int index = last;

	for (int i = last; i >= first + 1; i--)
	{
		if (a[i] >= pivot)
		{
			mSwap(&(a[i]), &(a[index]));
			index--;
		}
	}

	a[first] = a[index];
	a[index] = pivot;

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	QuickSort(a, first, index - 1);
	QuickSort(a, first, index + 1);

}

void mergeArray(int array1[],int first,int mid,int last,int res[])
{
	int i = first;
	int j = mid+1;
	int m = mid;
	int n = last;
	int k = 0;
	while (i<=m&&j<=n)
	{
		if (array1[i]<array1[j])
		{
			res[k] = array1[i];
			k++;
			i++;
		} 
		else
		{
			res[k] = array1[j];
			k++;
			j++;
		}
	}

	while (i<=m)
	{
		res[k] = array1[i];
		k++;
		i++;
	}

	while (j<=n)
	{
		res[k] = array1[j];
		k++;
		j++;
	}

	
	for (int i = 0; i < k;i++)
	{
		array1[first + i] = res[i];
		cout << res[i] <<" ";
	}
	cout << endl;
}

void mergeSort(int array[],int first,int last,int buffer[])
{
	if (first<last)
	{
		int mid = (first + last) / 2;
		mergeSort(array, first, mid, buffer);
		mergeSort(array, mid+1, last, buffer);
		mergeArray(array, first, mid, last, buffer);
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	int mArray[10]={72,6,57,88,60,42,83,73,48,85};
	int mArrayLen=sizeof(mArray)/sizeof(int);
	//bubbleSort(mArray,mArrayLen);
	//ShellSort(mArray,mArrayLen);
	 //SelectSort(mArray,mArrayLen);
	//QuickSort(mArray, 0, mArrayLen-1 );
	// int a=2,b=3;
	// mSwapByRef(a,b);


	 int array2[6] = { 1,89,12,903, 4, 5 };
	 int  arrRes[6] = {0x00};
	 mergeSort(array2, 0, 5, arrRes);
	 return 0;
}

