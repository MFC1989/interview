// testMainFunction.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstring>
#include <cstdlib>
//argc����������ĸ���.�� plus.exe 1 3  
//plus��һ���ӷ����򣬴�ʱargcΪ3�������˳�����plus��
//��ʱargv[0]Ϊ�ַ���plus.exe��argv[1]Ϊ�ַ�1��argv[2]Ϊ�ַ�3 
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

