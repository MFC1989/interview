// DynamicProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
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
	return 0;
}

