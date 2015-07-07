// string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdio>
#include <cstring>
#define MAXLEN 1024


//删除字符串中的a 并复制字符串中的b
char * DelCh1_DupCh2_Str(char * str,int ArraySize,char chDel,char chDup)
{
	char * strBuff = new char[ArraySize];
	strcpy(strBuff, str);

	int n = 0, numb = 0;
	for (int i = 0; str[i];i++)
	{
		if (str[i]!=chDel)
		{
			str[n++] = str[i];
		}
		if (str[i]==chDup)
		{
			++numb;
		}
		
	}

	if (numb*2>ArraySize)
	{
		memset(str, 0, ArraySize);
		strcpy(str, strBuff);
		delete(strBuff);
		printf("error!\n");
		return str;
	}
	
	str[n] = '\0';
	int newLen = n + numb;
	str[newLen] = '\0';

	for ( int j=newLen -1,k=n-1; k >= 0; --k) 
	{
		str[j--] = str[k];
		if (str[k] == chDup)
		{
			str[j--] = chDup;
		}
	}
	
	delete(strBuff);
	return str;
}



/*********************
@date 4.22
@description
给定两个串a和b，问b是否是a的子串的变位词。（假设只含有全英的小写字母a~z）
例如输入a = hello, b = lel, lle, ello都是true,但是b = elo是false。
@tags: string, hash table, two pointers

********************/

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	bool subStringAnagram(string a, string b){
		int nonZero = 0;
		int num[26] = { 0 };
		int lena = a.size();
		int lenb = b.size();

		if (lena < lenb)
			return false;

		for (int i = 0; i < lenb; i++)
		{
			char ch = b[i];
			int index = ch - 'a';
			if (num[index]==0)
			{
				++nonZero;
			}
			num[index]++;
		}


		for (int i = 0; i < lenb; ++i)
		{   // 第一个窗口单独开，因为第一个窗口的第一个元素不能丢
			int index = a[i] - 'a';
			--num[index];                       // 此时的num[]变成了a,b对应元素出现的次数的差值
			if (num[index] == 0)
			{
				--nonZero;
			}
			else if (num[index] == 1)
			{
				++nonZero;
			}
			if (nonZero == 0)
			{
				return true;
			}
		}


		for (int i = lenb; i < lena; ++i){
			int c = a[i - lenb] - 'a';
			++num[c]; // 扔掉a[i-lenb];   // 新窗口是a[i-lenb+1]...a[i]
			if (num[c] == 1) ++nonZero;
			else if (num[c] == 0) --nonZero;
			c = a[i] - 'a';               // 旧窗口是a[i-lenb]....a[i-1]
			--num[c]; // 加入a[i]
			if (num[c] == 0) --nonZero;
			else if (num[c] == -1) ++nonZero;
			if (nonZero == 0) return true;
		}
	}
};



int main()
{
	char * mStr = new char[MAXLEN];
	strcpy(mStr, "bbba");
	DelCh1_DupCh2_Str(mStr, MAXLEN,'a','b');
	delete(mStr);
	mStr = NULL;
	Solution a;
	cout << a.subStringAnagram("hello", "ell");


	char * str1 = new char[10];
	strcpy(str1, "aaa");
	str1[0] = 0;
	char * strr2 = str1 + 1;
	return 0;
}

