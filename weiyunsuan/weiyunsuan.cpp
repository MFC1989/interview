// weiyunsuan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

#define MYMIN(x,y)((x)<(y)?(x):(y))

//判断一个整数是否是2的整数幂
bool powerOf2(int num)
{
 for (int i=2;i<=65536;i*=2)
 {
	if (num==i)
	{
		return true;
	}

 }
 	return false;
}

//  判断一个数是否是2的整数幂（使用位运算）
bool powerOf2byBit(int num)
{
	if ((num&(num-1))==0)
	{
		return true;
	}
	return false;
}

//#include <Windows.h>
int _tmain(int argc, _TCHAR* argv[])
{
	 
	/* for (int i=4;i<=65536;i++ )
	 {
		 if (powerOf2(i))
		 {
			 printf("%d是2的整数幂\n",i);
		 } 
		 else
		 {
				
		 }
	 }
 
     int a =15;
	 int b =a^(3); 

	 int x=1,y=2;
	 int z=MYMIN(x,y);*/
	
	int a=15,b=10,c=11,d=12;
	// (*p)为const，但p不是const，可以通过改变p的指向，来间接的改变*p的值。
	const int * p = &a;
	//p=&b;
	
	//此处q和上面p的性质一样，并不因为const在int的前面或者后面而有区别。
	int const *q=&b;
	
	//此时指针m为const，不可改变它的指向。但可以改变它指向的地址中保存的值。
	int * const m=&d;
	*m=11;
	 
 
	//printf("%d\n",*p);

	system("pause");
	return 0;
}

