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

//物品数据结构
typedef struct commodity
{
	int value;  //价值
	int weight; //重量
}commodity;

const int N = 3;  //物品个数
const int W = 5; //背包的容量

//初始物品信息
commodity goods[N + 1] = { { 0, 0 }, { 6, 1 }, { 10, 2 }, { 300, 5 } };
int select[N + 1][W + 1];

int max_value()
{
	//初始没有物品时候，背包的价值为0
	for (int w = 1; w <= W; ++w)
	{
		select[0][w] = 0;
	}
	for (int i = 1; i <= N; ++i)
	{
		select[i][0] = 0;  //背包容量为0时，最大价值为0
		for (int w = 1; w <= W; ++w)
		{
			if (goods[i].weight <= w)  //当前物品i的重量小于等于w，进行选择
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
				//当前物品i的重量大于w，不选择
				select[i][w] = select[i - 1][w];
			}
		}
	}
	return select[N][W];  //最终求得最大值
}

//导弹拦截
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

//数组最大差值
int maxArrayDiff(int array[],int n)
{
	vector<int>diff(n, 0);
	vector<int>max(n, 0);
	int tmpDiff = 0;					//全局变量保存上次的差值
	int tmpMax = array[0];		//保存左边最大的值
	int maxDiff = 0;				//最后要返回的值
	for (int i = 0; i < n-1; i++)
	{
		if (tmpMax<array[i])
		{
			tmpMax = array[i];
		}

		diff[i] = array[i] - array[i+1];		//本次差值

		if (diff[i]<tmpDiff)
		{
			diff[i] = tmpDiff;					//将本次差值与上次差值比较,若上次差值大于本次，则取上次
		}

		tmpDiff = tmpMax - array[i+1];			//将本次的差值保存下来，作为下次的计算差值的”上次“。

		if (maxDiff<diff[i])
		{
			maxDiff = diff[i];
		}
	}

	return maxDiff;
}


 
#define MAXN 4
#define  CURN 4 
int  inPutBox()		//装箱问题
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


//切割钢条
int cutSteel()
{
	const int LEN = 5;
	int value[LEN] = { 0,2,1, 1, 2 };		//分别为长度是1,2,3,4时
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




//最长公共子序列的长度
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

//获取最长子序列
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


//最大乘积
/*
给一个浮点数序列，取最大乘积连续子串的值，例如 -2.5，4，0，3，0.5，8，-1，则取出
的最大乘积连续子串为3， 0.5， 8。 也就是说， 上述数组中， 3 0.5 8这3 个数的乘积3*0.5*8=12
是最大的，而且是连续的
*/

//还有一个插入乘号的变种 如123 插入一个乘号  最大乘积为12*3=36.   !!!

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

		if (tmp*a[i]>a[i])		//关键点！	 如r[i-1]=3, a[i]=0.5. 只要3*0.5>0.5 则可让r[i]=3*0.5。 
		{								//因为1.5乘以8总比0.5乘以3大！
			r[i] = tmp*a[i];		//状态转移方程为 r[i]=max(a[i],r[i-1]*a[i]);
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
	//输出所选择的物品列表：
	for (int i = N; i >= 1; i--)
	{
		if (remainspace >= goods[i].weight)
		{
			if ((select[i][remainspace] - select[i - 1][remainspace - goods[i].weight] == goods[i].value))
			{
				cout << "item " << i << " is selected!" << endl;
				remainspace = remainspace - goods[i].weight;//如果第i个物品被选择，那么背包剩余容量将减去第i个物品的重量 ;
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





