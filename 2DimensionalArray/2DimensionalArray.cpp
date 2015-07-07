// 2DimensionalArray.cpp : 定义控制台应用程序的入口点。
//




#include "stdafx.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//#include <string.h>
//#include <iostream>
//#define  NDEBUG
//
//#include <cassert>
//using namespace std;
//
//
//char * testAlloc()
//{
//	char * p=(char *)alloca(sizeof(char)*3);
//	strcpy(p,"ab");
//	char * q=p;
//	 
//	return q;
//	
//}
//
//int main()
//{
//	//rain 具有五个元素，并且每个元素都是包含有12个float数值的数组
//	float rain[5][12];
//	for (int i=0;i<5;i++)
//	{
//		for (int j=0;j<12;j++)
//		{
//			rain[i][j]=rand()%100;
//		}
//	}
// 
//	int x=3;
//	assert(x>100);
//
//	char str[3]="ab";
//	str[0]=0;
//	puts(str);
//
//	return 0;
//}
//
#include <iostream>
#include <fstream> // file I/O support
#include <cstdlib> // support for exit()
const int SIZE = 60;
int main()
{
	using namespace std;
	char filename[SIZE];
	ifstream inFile; // object for handling file input


	cout << "Enter name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename); // associate inFile with a file
	if (!inFile.is_open()) // failed to open file
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		// cin.get(); // keep window open
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0; // number of items read
	inFile >> value;// get first value
	while (inFile.good()) // while input good and not at EOF
	{
		++count; // one more item read
		sum += value; // calculate running total
		inFile >> value; // get next value
	}
 
	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";
	if (count == 0)
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}
	inFile.close(); // finished with the file
	// cin.get();
	system("pause");
	return 0;
}