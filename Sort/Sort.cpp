// Sort.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <ratio>
#include <chrono>

#include <iostream>
#include <ctime>
#include <iomanip>

#include <future>
#include <thread>
using namespace std;

inline void swap(int & a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void PRINT(int * mArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << mArray[i] << " ";
	}
	cout << endl;
}

void initArray(int * mArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		mArray[i] = rand();
	}
}
//依次把最大的放后面
int  bubbleSort(int * array, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 1; j < len - j; ++j)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
			}
		}
	}

	return 0;
}


//插入排序
void insertSort(int * array, int len)
{
	int i, j, tmp;
	for (i = 1; i < len; ++i)
	{
		int tmp = array[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j]>tmp)
			{
				array[j + 1] = array[j];
			}
			else
			{
				break;
			}
		}
		array[j + 1] = tmp;

	}


}

//选择排序
int selectSort(int array[], int len)
{
	int minIndex;
	for (int i = 0; i < len; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (array[minIndex]>array[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(array[i], array[minIndex]);
		}
	}
	return 0;
}


void QuickSort(int * array, int left, int right)
{
	int i = left;
	int j = right;
	int x = array[i];

	if (i < j)
	{
		while (i < j&&x <= array[j]) {
			j--;
		}
		if (i < j)
		{
			array[i] = array[j];
			i++;
		}

		while (i < j&&array[i] < x) {
			i++;
		}
		if (i < j)
		{
			array[j] = array[i];
			j--;
		}
		array[i] = x;
		QuickSort(array, left, i - 1);
		QuickSort(array, i + 1, right);
	}


}


//二分查找 递归
bool binSearch(int * array, int begin, int end, int key)
{
	int left = begin;
	int right = end;

	if (left <= right)
	{
		int mid = (left + right) / 2;
		if (array[mid] == key)
		{
			return true;
		}
		else
		{
			return binSearch(array, left, mid - 1, key) || binSearch(array, mid + 1, right, key);
		}
	}
	else
	{
		return false;
	}
}


//合并两个有序数组
void merge(int * array, int first, int mid, int last, int * tmp)
{
	int i = first;
	int j = mid + 1;
	int m = mid;
	int n = last;
	int k = 0;

	while (i <= m&&j <= n)
	{
		if (array[i] > array[j])
		{
			tmp[k++] = array[j++];
		}
		else
		{
			tmp[k++] = array[i++];
		}

	}

	while (i <= m)
	{
		tmp[k++] = array[i++];
	}

	while (j <= n)
	{
		tmp[k++] = array[j++];
	}



}

//递归拆分合并
void recursionMerge(int * array, int first, int last, int * tmp)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		recursionMerge(array, first, mid, tmp);
		recursionMerge(array, mid + 1, last, tmp);
		merge(array, first, mid, last, tmp);
	}
}

void mergeSort(int * array, int len)
{
	int * ptmp = new int[len];
	recursionMerge(array, 0, len - 1, ptmp);
	delete[] ptmp;
}

void showTime()
{
	using std::chrono::system_clock;
	auto end = std::chrono::system_clock::now();

	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	cout << std::ctime(&end_time) << endl;
}

#define ARRAY_LEN 50000
int main(int argc, char**a)
{



	showTime();
	int mArray[ARRAY_LEN];
	int mArray2[ARRAY_LEN];
	int mArray3[ARRAY_LEN];

	cout << sizeof(mArray)*(sizeof(int)) / 1024 << endl;

	//initArray(mArray, ARRAY_LEN);
	//PRINT(mArray,ARRAY_LEN);
	//QuickSort(mArray, 0, ARRAY_LEN - 1);


	initArray(mArray, ARRAY_LEN);
	initArray(mArray2, ARRAY_LEN);
	initArray(mArray3, ARRAY_LEN);


	mergeSort(mArray, ARRAY_LEN);



	initArray(mArray, ARRAY_LEN);
	//std::thread t1(selectSort, mArray3, ARRAY_LEN); // Acceptable.
	//t1.join();
	selectSort(mArray3,ARRAY_LEN);

	initArray(mArray, ARRAY_LEN);
	//std::thread t2(bubbleSort, mArray2, ARRAY_LEN); // Acceptable.
	//t2.join();
	bubbleSort(mArray2, ARRAY_LEN);
	initArray(mArray, ARRAY_LEN);

	insertSort(mArray, ARRAY_LEN);

	//PRINT(mArray,ARRAY_LEN);

	showTime();


	//PRINT(mArray,ARRAY_LEN);
	getch();
	return 0;
}




//#define ABS(n) (n>0?n:-n)
//
//char *itoa(int  i)
//{
//	char * Str = (char *)malloc(sizeof(char) * 32);
//	
//	char buff[32] = { '\0' };
//	int tmp = ABS(i);
//	int m, n;
//	for (m = 0; m < 32; m++)
//	{
//		buff[m] = (tmp%10) + '0';
//		tmp = tmp / 10;
//		if (tmp == 0)
//		{
//			break;
//		}
//	}
//	if (i < 0)
//	{
//		buff[++m] = '-';
//	}
//	for (n = 0; m >= 0; m--)
//	{
//		Str[n++] = buff[m];
//	}
//	Str[n] = '\0';
//	return Str;
//}




