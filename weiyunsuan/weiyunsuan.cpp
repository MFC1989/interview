// weiyunsuan.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>

#define MYMIN(x,y)((x)<(y)?(x):(y))

//�ж�һ�������Ƿ���2��������
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

//  �ж�һ�����Ƿ���2�������ݣ�ʹ��λ���㣩
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
			 printf("%d��2��������\n",i);
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
	// (*p)Ϊconst����p����const������ͨ���ı�p��ָ������ӵĸı�*p��ֵ��
	const int * p = &a;
	//p=&b;
	
	//�˴�q������p������һ����������Ϊconst��int��ǰ����ߺ����������
	int const *q=&b;
	
	//��ʱָ��mΪconst�����ɸı�����ָ�򡣵����Ըı���ָ��ĵ�ַ�б����ֵ��
	int * const m=&d;
	*m=11;
	 
 
	//printf("%d\n",*p);

	system("pause");
	return 0;
}

