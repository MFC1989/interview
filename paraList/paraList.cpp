// paraList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<string>paraList;
	paraList.push_back("/c");
	paraList.push_back("fill");
	paraList.push_back("t");
	paraList.push_back("/part");
	//paraList.push_back("/system");
	//paraList.push_back("s");
	//paraList.push_back("s");

	list<string> mList;
	mList.resize(paraList.size());
	copy(paraList.begin(), paraList.end(), mList.begin());

	size_t originalSize = mList.size();
	string prevPara;
	while (mList.size()>0)
	{
		if (mList.size() == 1)
		{
			//两种情况
			//(1)找到"/" ：因为他后面没跟参数 所以认为他自己是错误的
			//(2)找不到"/": 因为他不是参数，所以认为上一个参数跟了两个值
			string str = mList.front();
			if (str.find("/",0)!=string::npos)
			{
				cout << "the usage of \"" << mList.front() << "\" was error!" << endl;
			} 
			else
			{
				if (prevPara!="")
				{
					//如果没有上一个参数  意味着他自己就是原始链表中唯一的一个。直接报它出错即可.
					cout << "the usage of \"" << prevPara << "\" was error!" << endl;
				}
				else
				{
					//认为上一个参数跟了两个值
					cout << "the usage of \"" << mList.front() << "\" was error!" << endl;
				}
			}
			break;
		}

		string strPara, strValue;
		strPara = mList.front();
		mList.pop_front();	
		strValue = mList.front();
		mList.pop_front();
	
		if (strPara.find("/", 0) == string::npos)
		{
			//分为两种
			//(1)它是原始链表的第一个（原始链表长度大于1）说明他自己用法错误
			//(2)不是第一个 说明上次的参数用法错误

			if (prevPara=="")
			{
				cout << strPara << endl;
			}
			else
			{
				cout << prevPara << endl;
			}

			break;
			
		}
		if (strValue.find("/", 0) != string::npos)
		{
			//在value中发现"/"只能说明前一个para没有跟上合适的值
			cout << strPara << endl;
			break;
		}
	 
	 
		prevPara = strPara;
		 
	}

	return 0;
}

