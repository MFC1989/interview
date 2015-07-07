// reverseOutputInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

void printLastNum(int paraX)
{
	if (paraX>10)
	{
		cout << paraX % 10;
		paraX = paraX / 10;
		printLastNum(paraX);
	}
	else if (paraX>0)
	{
		cout << paraX << endl;
	}
}


char* strrev5(/*const */char* str, int len)
{
	if (len <= 1)
		return str;

	char t = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = t;

	return (strrev5(str + 1, len - 2) - 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	char str[6] = "abcde";
	strrev5(str,strlen(str));
	int x = 123000;
	printLastNum(x);
	return 0;
}

