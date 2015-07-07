// DynamicProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
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
	return 0;
}

