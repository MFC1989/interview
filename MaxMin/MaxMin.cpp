// MaxMin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

static int cmpTimes = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	int array[6] = { 6, 5, 8, 3, 9, 7 };
	int Max;
	int Min;
	{
		if (array[0] > array[1])
		{
			Max = array[0];
			Min = array[1];
		}
		else
		{
			Max = array[0];
			Min = array[1];
		}
		cmpTimes++;
	}
	
	for (int index = 2; index < 6;index+=2)
	{
		int tmpMax, tmpMin;
		if (array[index]>array[index+1])
		{
			tmpMax = array[index];
			tmpMin = array[index+1];
		} 
		else
		{
			tmpMax = array[index+1];
			tmpMin = array[index];
		}

		cmpTimes++;

		if (tmpMax>Max)
		{
			Max = tmpMax;
			cmpTimes++;

		}
		if (tmpMin < Min)
		{
			Min = tmpMin;
			cmpTimes++;

		}
	}
	cout << Max << "  " << Min << endl;
	return 0;
}

