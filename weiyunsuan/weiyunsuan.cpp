// weiyunsuan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
//位图算法
//#include "stdafx.h"
//#include <iostream>
//using namespace std;
//
//char *g_bitmap = NULL;  
//int g_size = 0;  
//int g_base = 0; 
//
////功能：初始化bitmap 
////参数： size：bitmap的大小，即bit位的个数 
////      start：起始值 
////返回值：0表示失败，1表示成功 
//int bitmap_init(int size, int start)  
//{  
//	g_size = size/8+1;
//	g_base = start;
//	g_bitmap = new char[g_size];  
//	if(g_bitmap == NULL)
//	{
//		return 0;  
//	}
//	memset(g_bitmap, 0x0, g_size);  
//	return 1;  
//}  
//
////功能：将值index的对应位设为1 
////index:要设的值 
////返回值：0表示失败，1表示成功 
//int bitmap_set(int index)  
//{  
//	    int quo = (index-g_base)/8 ;  //确定所在的字节
//	    int remainder = (index-g_base)%8;  //字节内的偏移  
//	    unsigned char x = (0x1<<remainder);    
//		
//		char buffBinStr[260] = { 0x00 };
//		itoa(x, buffBinStr, 2);
//		//int tmp = atoi(buffBinStr);
//	    if( quo > g_size)  
//		        return 0;
//	    g_bitmap[quo] |= x;   //所在字节内的特定位置为1  
//	    return 1;   
//}  
// 
////功能：取bitmap第i位的值 
////i：待取位 
////返回值：-1表示失败，否则返回对应位的值 
//int bitmap_get(int i)  
//{  
//	int quo = (i)/8 ;  
//	int remainder = (i)%8;  
//	unsigned char x = (0x1<<remainder);  
//	unsigned char res;  
//	if( quo > g_size)  
//		return -1;  
//	res = g_bitmap[quo] & x;  
//	return res > 0 ? 1 : 0;   
//}  
//
// 
// //功能：返回index位对应的值   
//int bitmap_data(int index)  
//{  
//	return (index + g_base);  
//}  
//
////释放内存 
//int bitmap_free()  
//{  
//	delete [] g_bitmap;
//	return 0;
//}    
// 
//int _tmain(int argc, _TCHAR* argv[]) 
//{  
//	int a[] = {5,8,7,6,3,1,10,78,56,34,23,12,43,54,65,76,87,98,89,100};  
//    int i;  
//	bitmap_init(100, 0);  
//	for(i=0; i<20; i++)
//	{
//		bitmap_set(a[i]);  
//	}
//	for(i=0; i<=100; i++)  
//	{  
//		if(bitmap_get(i) > 0 )  
//			cout << bitmap_data(i)<< " ";
//	}  
//	cout << endl;  
//	bitmap_free(); 
//	char * p = "abc";
//	char q = p[0];
//    return 0;  
//}  


//筛选法求素数
void selectPrim()
{
	int array[100] = { 0x00 };
	for (int i = 2; i < 100;i++)
	{
		if (!array[i])
		{
			for (int j = 2*i; j < 100;j+=i)
			{
				array[j] = 1;
			}
		}
	
	}

	for (int i = 2; i < 100;i++)
	{
		if (!array[i])
		{
			cout << i << " " ;
		}
	}
	cout << endl;
}

//使用bitmap和筛选法找素数--节省空间
void selectPrimBitmap()
{
	#define space 100/8+1
	int array[space] = { 0x00 };
	for (int i = 2; i < 100;i++)
	{
		if (!(array[i/32]>>(i%32)&1))
		{
			for (int j = 2 * i; j < 100; j += i)
			{
				array[j / 32] |= (1 << (j % 32));
			}
		}
		
	}

	for (int i = 2; i < 100;i++)
	{
		if (!(array[i / 32] >> (i % 32) & 1))
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

//反转字节
 unsigned char reverse_bits( unsigned char value)
{
	 unsigned char rslt = (value & 0);
	 // 标志移位的次数  
	 unsigned char flag = 1;
	 while (flag != 0)
	 {
		 if ((value & 1) == 1)
		 {
			 rslt = (rslt << 1) + 1;
		 }
		 else
		 {
			 rslt <<= 1;
		 }
		 value >>= 1;
		 flag <<= 1;
	 }
	 return rslt;
}


int Add(int a, int b)
{
	int jw = a&b;
	int jg = a^b;
	while (jw)
	{
		int t_a = jg;
		int t_b = jw << 1;
		jw = t_a&t_b;
		jg = t_a^t_b;
	}
	return jg;
}

template <class T>
void PrintfBinary(T a)
{
	int i;
	for (i = sizeof(a)* 8 - 1; i >= 0; --i)
	{
		if ((a >> i) & 1)
			putchar('1');
		else
			putchar('0');
		if (i == 8)
			putchar(' ');
	}
	putchar('\n');
}


//求二进制数字中1的个数---无法处理负数	
int getNumOfOneOnBinV1(int paraN)
{
	int nCount = 0;
	int calcTimes = 0;

	while (paraN!=0)
	{
		if ((paraN&1)==1)
		{
			nCount++;
		}
		paraN >>= 1;
		calcTimes++;
	}
	cout << calcTimes << "  " << nCount << endl;
	return nCount;
}

//求二进制数字中1的个数---可以处理负数
/*
负数的空白位用1填充
如8位的负数，最高位（符号位）是1,但只有三个有效数据位，且这三个数据位为111，则该数的二进制表示为11110111.
--以0为分割位,最高位为1，中间部分用0填充
*/

int getNumOfOneOnBinV2(int paraN)
{
	int nCount = 0;
	int calcTimes = 0;
	while (paraN)
	{
		if (paraN & 1 == 1)
		{
			nCount++;
		}
		paraN >>= 1;
		calcTimes++;
	}
	cout << calcTimes<<"  "<<nCount << endl;
	return nCount;
}

//求二进制数字中1的个数
/*
只为1的位进行计算，减少计算次数，但对负数无效果（因为负数的空白位是用1来填充）	
*/
int getNumOfOneOnBinV3(int paraN)
{
	int nCount = 0;
	int calcTimes = 0;
	while (paraN)
	{
		paraN = paraN & (paraN - 1);
		nCount++;
		calcTimes++;
	}
	cout << calcTimes << "  " << nCount << endl;
	return nCount;
}


int main()
{
	//selectPrim();
	//selectPrimBitmap();
	//char buff[260] = { 0x00 };
	//
	// unsigned char t = 1;
	//PrintfBinary(t);
	//t = reverse_bits(t);

	//PrintfBinary(t);
	//int res=	getNumOfOneOnBinV2(-3);
	getNumOfOneOnBinV1(129);
	getNumOfOneOnBinV2(129);
	getNumOfOneOnBinV3(129);

	const int MAXN = 5;
	int a[MAXN] = { 2,3,3,2,1 };
	int lostNum = 0;
	for (int i = 0; i < MAXN; i++)
	{
		lostNum ^= a[i];
	}
	printf("缺失的数字为:  %d\n", lostNum);

	return 0;
}