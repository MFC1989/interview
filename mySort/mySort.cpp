// mySort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
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

int _tmain(int argc, _TCHAR* argv[])
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

	int a[5];
	int sum=0;

	//ifstream MyIfstream;
	//MyIfstream.open(L"a.txt");
	//
	//for (int i=0;i<5;i++)
	//{
	//	MyIfstream>>a[i];
	//	sum+=a[i];
	//}
	//printf("%d",sum/5);

	
	int * q=testPoint();
	cout<<*q<<endl;
	free(q);

	system("pause");
	return 0;
}

