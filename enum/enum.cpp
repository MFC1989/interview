// enum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>

int main()
{
	enum color{red,blue,green};
	
	  color myColorRed=color::red;
	  color myColorBlue=color::blue;
	  color myColorGreen=color::green;

	printf("%d\n%d\n%d\n",myColorRed,myColorBlue,myColorGreen);
  
	system("pause");
	return 0;
}

