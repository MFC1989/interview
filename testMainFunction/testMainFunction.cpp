// testMainFunction.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstring>
#include <cstdlib>
//argc代表传入参数的个数.如 plus.exe 1 3  
//plus是一个加法程序，此时argc为3（包括了程序名plus）
//此时argv[0]为字符串plus.exe，argv[1]为字符1，argv[2]为字符3 
int main(int argc, char* argv[])
{
	int a,b;
	//sscanf_s(argv[1],"%d",&a);
	sscanf_s(argv[2],"%d",&b);
	//printf_s("%d",a*b);
	puts(argv[0]);
	
	system("pause");
	return 0;
}

