// DynamicProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>

//#define MAXWEIGHT 100
//
//int n = 3; /* The number of objects */
//int c[10] = { 8, 6, 4 }; /* c[i] is the *COST* of the ith object; i.e. what
//						 YOU PAY to take the object */
//int v[10] = { 16, 11, 7 }; /* v[i] is the *VALUE* of the ith object; i.e.
//						   what YOU GET for taking the object */
//int W = 10; /* The maximum weight you can take */
//
//void fill_sack() {
//	int a[MAXWEIGHT]; /* a[i] holds the maximum value that can be obtained
//					  using at most i weight */
//	int last_added[MAXWEIGHT]; /* I use this to calculate which object were
//							   added */
//	int i, j;
//	int aux;
//
//	for (i = 0; i <= W; ++i) 
//	{
//		a[i] = 0;
//		last_added[i] = -1;
//	}
//
//	a[0] = 0;
//	for (i = 1; i <= W; ++i)
//	{
//		for (j = 0; j < n; ++j)
//		{
//			if ((c[j] <= i) && ( a[i] < a[  i - c[j]  ] + v[j] ))
//			{
//				a[i] = a[ i - c[j] ] + v[j];
//				printf("%d\n", a[i]) ;
//				last_added[i] = j;
//			}
//		}
//			
//	}
//		
//	for (i = 0; i <= W; ++i)
//		if (last_added[i] != -1)
//			printf("Weight %d; Benefit: %d; To reach this weight I added object %d (%d$ %dKg) to weight %d.\n", i, a[i], last_added[i] + 1, v[last_added[i]], c[last_added[i]], i - c[last_added[i]]);
//		else
//			printf("Weight %d; Benefit: 0; Can't reach this exact weight.\n", i);
//
//	printf("---\n");
//
//	aux = W;
//	while ((aux > 0) && (last_added[aux] != -1)) 
//	{
//		printf("Added object %d (%d$ %dKg). Space left: %d\n", last_added[aux] + 1, v[last_added[aux]], c[last_added[aux]], aux - c[last_added[aux]]);
//		aux -= c[last_added[aux]];
//	}
//
//	printf("Total value added: %d$\n", a[W]);
//}
//
//int main(int argc, char *argv[]) {
//	fill_sack();
//
//	return 0;
//}


#include <iostream>
using namespace std;

//��Ʒ���ݽṹ
typedef struct commodity
{
	int value;  //��ֵ
	int weight; //����
}commodity;

const int N = 3;  //��Ʒ����
const int W = 5; //����������

//��ʼ��Ʒ��Ϣ
commodity goods[N + 1] = { { 0, 0 }, { 6, 1 }, { 10, 2 }, { 300, 5 } };
int select[N + 1][W + 1];

int max_value();

int main()
{
	int maxvalue = max_value();
	cout << "The max value is: ";
	cout << maxvalue << endl;
	int remainspace = W;
	//�����ѡ�����Ʒ�б�
	for (int i = N; i >= 1; i--)
	{
		if (remainspace >= goods[i].weight)
		{
			if ((select[i][remainspace] - select[i - 1][remainspace - goods[i].weight] == goods[i].value))
			{
				cout << "item " << i << " is selected!" << endl;
				remainspace = remainspace - goods[i].weight;//�����i����Ʒ��ѡ����ô����ʣ����������ȥ��i����Ʒ������ ;
			}
		}
	}
	return 0;
}
int max_value()
{
	//��ʼû����Ʒʱ�򣬱����ļ�ֵΪ0
	for (int w = 1; w <= W; ++w)
	{
		select[0][w] = 0;
	}
	for (int i = 1; i <= N; ++i)
	{
		select[i][0] = 0;  //��������Ϊ0ʱ������ֵΪ0
		for (int w = 1; w <= W; ++w)
		{
			if (goods[i].weight <= w)  //��ǰ��Ʒi������С�ڵ���w������ѡ��
			{
				if ((goods[i].value + select[i - 1][w - goods[i].weight]) > select[i - 1][w])
				{
					select[i][w] = goods[i].value + select[i - 1][w - goods[i].weight];
				}
				else
				{
					select[i][w] = select[i - 1][w];
				}
			}
			else
			{
				//��ǰ��Ʒi����������w����ѡ��
				select[i][w] = select[i - 1][w];
			}
		}
	}
	return select[N][W];  //����������ֵ
}

