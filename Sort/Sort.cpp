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

void mSwapByBitOp(int &a,int &b)
{
	if (a!=b)
	{
		a = a^b;
		b = a^b;
		a = a^b;
	}
	
}

void bubbleSort(int tArray[],int len)
{
	for (int i = 0; i < len;i++)
	{
		for (int j = 1; j < len - i;j++)
		{
			if (tArray[j]<tArray[j-1])
			{
				mSwapByBitOp(tArray[j], tArray[j - 1]);
			}
		}
	}
}


void InsertSort(int tArray[],int len)
{

	int i, j, tmp;
	for ( i = 1; i < len;i++)
	{
		tmp = tArray[i];
		for ( j = i - 1; j >= 0;j--)
		{
			if (tArray[j]>tmp)					//如果前面有数大于它，则把前面的数往后挪动
			{
				tArray[j + 1] = tArray[j];		
			}
		}
		
		tArray[j + 1] = tmp;		//把它插入到正确的位置
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

//void SelectSort(int tArray[],int len)
//{
//	int i,j,flag;
//	for ( i=0;i<len-1;i++)
//	{
//		flag=i;
//		for ( j=i+1;j<len;j++)
//		{
//			if (tArray[flag]>tArray[j])
//			{
//				flag=j;
//			}
//		}
//
//			//tmp=tArray[i];
//			//tArray[i]=tArray[flag];
//			//tArray[flag]=tmp;
//			mSwapByBitOp((tArray[i]),(tArray[flag]));
//	}
//
//
//}


//找到后面最小的那个数的下标，然后与之交换。
void selectSortV2()
{
	int a[5] = { 2, 4, 3, 1, 9 };
	for (int i = 0; i < 5;i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < 5;j++)
		{
			if (a[minIndex]>a[j])
			{
				minIndex = j;
			}
		}

		if (minIndex!=i)
		{
			mSwapByBitOp(a[i], a[minIndex]);
		}
	}

}




void QuickSort(int tArray[], int left,int right)
{
	if (left < right)
	{
		int i = left;
		int j = right;
		int x = tArray[left];
		while (i < j)
		{
			while (i < j&&tArray[j] >= x)
			{
				j--;
			}

			if (i < j)
			{
				tArray[i] = tArray[j];
				i++;
			}

			while (i < j&&tArray[i] < x)
			{
				i++;
			}
			if (i < j)
			{
				tArray[j] = tArray[i];
				j--;
			}

			tArray[i] = x;
			QuickSort(tArray, left, i - 1);
			QuickSort(tArray, i + 1, right);
		}
	}
	
	//if (last <= first)
	//{
	//	return;
	//}
	//int pivot = a[first];
	//int index = last;

	//for (int i = last; i >= first + 1; i--)
	//{
	//	if (a[i] >= pivot)
	//	{
	//		mSwapByBitOp(a[i], a[index]);
	//		index--;
	//	}
	//}

	//a[first] = a[index];
	//a[index] = pivot;

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << a[i] << " ";
	//}
	//QuickSort(a, first, index - 1);
	//QuickSort(a, first, index + 1);

}

void mergeArray(int array1[],int first,int mid,int last,int res[])
{
	int j = mid+1;
	int cur = 0;
	while (first<=mid&&j<=last)
	{
		if (array1[first]<array1[j])
		{
			res[cur] = array1[first];
			cur++;
			first++;
		} 
		else
		{
			res[cur] = array1[j];
			cur++;
			j++;
		}
	}

	while (first<=mid)						//若前半部分没有合并完
	{
		res[cur] = array1[first];
		cur++;
		first++;
	}

	while (j<=last)							//若后半部分没有合并完
	{
		res[cur] = array1[j];					//PS: 前半部分没有合并完和后半部分没有合并完这两种情况只会出现一种。
		cur++;
		j++;
	}

	
	//for (int i = 0; i < k;i++)
	//{
	//	array1[first + i] = res[i];
	//	cout << res[i] <<" ";
	//}
	//cout << endl;
}



//合并有序数组(array的前半部分和后半部分分别是有序的，现将其合并为整体有序)
void merge2SortedArray(int array[],int first,int mid,int last,int res[])
{
	int cur = 0;
	int j = mid + 1;
	while (first<=mid&&j<=last)
	{
		if (array[first]<array[j])
		{
			res[cur] = array[first];
			first++;
			cur++;
		}
		else
		{
			res[cur] = array[j];
			j++;
			cur++;
		}
	}

	while (first<=mid)
	{
		res[cur] = array[first];
		cur++;
		first++;
	}

	while (j <= last)
	{
		res[cur] = array[j];
		cur++;
		j++;
	}


}


void mergeSort(int array[], int first, int last, int buffer[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergeSort(array, first, mid, buffer);
		mergeSort(array, mid + 1, last, buffer);
		mergeArray(array, first, mid, last, buffer);
	}

}

//堆排序


#define  LEFT(x)  (x<<1)
#define  RIGHT(x) ((x<<1)+1)

//维护最大堆的性质
void maxHeapify(int array[], int len, int index)
{
	int l = LEFT(index);
	int r = RIGHT(index);

	int largest = 0;

	if (l <= len&&array[l] > array[index])
	{
		largest = l;
	}
	else
	{
		largest = index;
	}


	if (r <= len&&array[r] > array[largest])
	{
		largest = r;
	}

	if (!(largest&index))
	{
		mSwapByBitOp(array[index], array[largest]);
		maxHeapify(array, len, largest);
	}

}


//建堆
void buildMaxHeap(int array[],int len)
{
	for (int i = len / 2; i >= 1;i--)
	{
		maxHeapify(array, len, i);
	}
}


//堆排序
void heapSort(int array[], int len)
{
	buildMaxHeap(array, len);

	for (int i = len; i > 1; i--)
	{
		mSwapByBitOp(array[1], array[len]);
		maxHeapify(array, i, 1);
	}

}



int _tmain(int argc, _TCHAR* argv[])
{
	int mArray[6]={0,3,11,7,9,2};
	QuickSort(mArray, 0, 5);
	//int mArrayLen=sizeof(mArray)/sizeof(int);
	//int newArray[5] = { 0x00 };

	////mergeSort(mArray, 0, 3, newArray);

	 //merge2SortedArray(mArray, 0, 2, 4, newArray);
	// mMergeSort(mArray,0,4,newArray);
	//heapSort(mArray, 5);
	//selectSortV2();

	return 0;
}

