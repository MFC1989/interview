// weiyunsuan.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
//λͼ�㷨
//#include "stdafx.h"
//#include <iostream>
//using namespace std;
//
//char *g_bitmap = NULL;  
//int g_size = 0;  
//int g_base = 0; 
//
////���ܣ���ʼ��bitmap 
////������ size��bitmap�Ĵ�С����bitλ�ĸ��� 
////      start����ʼֵ 
////����ֵ��0��ʾʧ�ܣ�1��ʾ�ɹ� 
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
////���ܣ���ֵindex�Ķ�Ӧλ��Ϊ1 
////index:Ҫ���ֵ 
////����ֵ��0��ʾʧ�ܣ�1��ʾ�ɹ� 
//int bitmap_set(int index)  
//{  
//	    int quo = (index-g_base)/8 ;  //ȷ�����ڵ��ֽ�
//	    int remainder = (index-g_base)%8;  //�ֽ��ڵ�ƫ��  
//	    unsigned char x = (0x1<<remainder);    
//		
//		char buffBinStr[260] = { 0x00 };
//		itoa(x, buffBinStr, 2);
//		//int tmp = atoi(buffBinStr);
//	    if( quo > g_size)  
//		        return 0;
//	    g_bitmap[quo] |= x;   //�����ֽ��ڵ��ض�λ��Ϊ1  
//	    return 1;   
//}  
// 
////���ܣ�ȡbitmap��iλ��ֵ 
////i����ȡλ 
////����ֵ��-1��ʾʧ�ܣ����򷵻ض�Ӧλ��ֵ 
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
// //���ܣ�����indexλ��Ӧ��ֵ   
//int bitmap_data(int index)  
//{  
//	return (index + g_base);  
//}  
//
////�ͷ��ڴ� 
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


//ɸѡ��������
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

//ʹ��bitmap��ɸѡ��������--��ʡ�ռ�
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

//��ת�ֽ�
 unsigned char reverse_bits( unsigned char value)
{
	 unsigned char rslt = (value & 0);
	 // ��־��λ�Ĵ���  
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


//�������������1�ĸ���---�޷�������	
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

//�������������1�ĸ���---���Դ�����
/*
�����Ŀհ�λ��1���
��8λ�ĸ��������λ������λ����1,��ֻ��������Ч����λ��������������λΪ111��������Ķ����Ʊ�ʾΪ11110111.
--��0Ϊ�ָ�λ,���λΪ1���м䲿����0���
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

//�������������1�ĸ���
/*
ֻΪ1��λ���м��㣬���ټ�����������Ը�����Ч������Ϊ�����Ŀհ�λ����1����䣩	
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
	printf("ȱʧ������Ϊ:  %d\n", lostNum);

	return 0;
}