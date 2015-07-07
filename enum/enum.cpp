// enum.cpp : 定义控制台应用程序的入口点。
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

