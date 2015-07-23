// DynamicProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
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

//��������
int missleIntercept(const vector <int> & missle)
{
	vector<int> dp(missle.size(),0);
	for (int i = missle.size()-1; i >=0; i--)
	{
		for (int j = i ; j < missle.size(); j++)
		{
			if (missle[i]>=missle[j] && dp[i] < dp[j]+1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}
	int res = *max_element(dp.begin(), dp.end());
	return res;
}

//��������ֵ
int maxArrayDiff(int array[],int n)
{
	vector<int>diff(n, 0);
	vector<int>max(n, 0);
	int tmpDiff = 0;					//ȫ�ֱ��������ϴεĲ�ֵ
	int tmpMax = array[0];		//�����������ֵ
	int maxDiff = 0;				//���Ҫ���ص�ֵ
	for (int i = 0; i < n-1; i++)
	{
		if (tmpMax<array[i])
		{
			tmpMax = array[i];
		}

		diff[i] = array[i] - array[i+1];		//���β�ֵ

		if (diff[i]<tmpDiff)
		{
			diff[i] = tmpDiff;					//�����β�ֵ���ϴβ�ֵ�Ƚ�,���ϴβ�ֵ���ڱ��Σ���ȡ�ϴ�
		}

		tmpDiff = tmpMax - array[i+1];			//�����εĲ�ֵ������������Ϊ�´εļ����ֵ�ġ��ϴΡ���

		if (maxDiff<diff[i])
		{
			maxDiff = diff[i];
		}
	}

	return maxDiff;
}


 
#define MAXN 4
#define  CURN 4 
int  inPutBox()		//װ������
{
	int items[5] = { 0,3,2,1 };
	int r[MAXN+1][MAXN+1] = { 0 };

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= MAXN; j++)
		{
			if (j < items[i])
			{
				r[i][j] = r[i - 1][j];
			}
			else
			{
				r[i][j] = max(r[i - 1][j], r[i - 1][j - items[i]] + items[i]);
			}

		}
	}


	return 1;
}


//�и����
int cutSteel()
{
	const int LEN = 5;
	int value[LEN] = { 0,2,1, 1, 2 };		//�ֱ�Ϊ������1,2,3,4ʱ
	int r[10] = { 0x00 };
	
	for (int i = 1; i < 5;i++)
	{
		int tmp = -1;
		for (int j = 1; j <= i;j++)
		{
			if (tmp<r[i-j]+value[j])
			{
				tmp = r[i - j] + value[j];
			}
		}
		r[i]=tmp;
	}
	return 0;
}




//����������еĳ���
int getCommenLen(int n, int r[4][4], char *str1, char * str2, int  b[4][4])
{
	int i, j;
	for ( i = 1; i < n; i++)
	{
		for ( j = 1; j <n;j++)
		{
			if (str1[i]==str2[j])
			{
				r[i][j] = r[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else
			{
				if (r[i-1][j ]>r[i ][j-1])
				{
					b[i][j] = 2;
					r[i][j] = r[i-1][j ];
				} 
				else
				{
					b[i][j] = 3;
					r[i][j] = r[j][i-1];
				}
			}
		}
	}

	return r[n-1][n-1];
}

//��ȡ�������
void LCS(int i, int j, char * x, int pos[4][4])
{
	if (i==0||j==0)
	{
		return;
	}

	cout << "i= " << i << "j= " << j << endl;
	if (pos[i][j] == 1)
	{
		cout << x[i]<< endl;
		LCS(i - 1, j - 1, x, pos);
	}
	else if (pos[i][j] == 2)
	{
		LCS(i - 1, j, x, pos);
	}
	else
	{
		LCS(i, j - 1, x, pos);
	}
}


//���˻�
/*
��һ�����������У�ȡ���˻������Ӵ���ֵ������ -2.5��4��0��3��0.5��8��-1����ȡ��
�����˻������Ӵ�Ϊ3�� 0.5�� 8�� Ҳ����˵�� ���������У� 3 0.5 8��3 �����ĳ˻�3*0.5*8=12
�����ģ�������������
*/

//����һ������˺ŵı��� ��123 ����һ���˺�  ���˻�Ϊ12*3=36.   !!!

float maxMultiplySequence()
{
	const int LEN = 10;
	float a[LEN] = { 88, 4 ,0, 3, 0.5 ,8 ,0,12,3,0 };
	float r[LEN] = { 0x00 };

	r[0] = a[0];
	float curMax = r[0];
	for (int i = 1; i < LEN ; i++)
	{
		float tmp = r[i-1];

		if (tmp*a[i]>a[i])		//�ؼ��㣡	 ��r[i-1]=3, a[i]=0.5. ֻҪ3*0.5>0.5 �����r[i]=3*0.5�� 
		{								//��Ϊ1.5����8�ܱ�0.5����3��
			r[i] = tmp*a[i];		//״̬ת�Ʒ���Ϊ r[i]=max(a[i],r[i-1]*a[i]);
		}
		else
		{
			r[i] = a[i];
		}
		
		curMax = std::max(r[i],curMax);
	}
	cout << curMax << endl;
	return curMax;
}
	




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

	vector<int>missles{ 2,1,1,1,1,1,9,8,7,6,5,4,3,2,1};
	int res=missleIntercept(missles);

	int array[12] = { 208,117,109,238,144,248,138,39,106,9,159,18 };
	int maxDiff=maxArrayDiff(array, 12);
	inPutBox();
	cutSteel();

	char * str1 = "#abc";
	char * str2 = "#bcd";
	int n = strlen(str1);
	int r[4][4] = { 0x00 };
	int b[4][4] = { 0x00 };

	int len=getCommenLen(n, r, str1, str2, b);
	LCS(3, 3, str1, b);
	maxMultiplySequence();
	cout << LLONG_MAX << endl;

	return 0;
}





