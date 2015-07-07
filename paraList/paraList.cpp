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
			//�������
			//(1)�ҵ�"/" ����Ϊ������û������ ������Ϊ���Լ��Ǵ����
			//(2)�Ҳ���"/": ��Ϊ�����ǲ�����������Ϊ��һ��������������ֵ
			string str = mList.front();
			if (str.find("/",0)!=string::npos)
			{
				cout << "the usage of \"" << mList.front() << "\" was error!" << endl;
			} 
			else
			{
				if (prevPara!="")
				{
					//���û����һ������  ��ζ�����Լ�����ԭʼ������Ψһ��һ����ֱ�ӱ���������.
					cout << "the usage of \"" << prevPara << "\" was error!" << endl;
				}
				else
				{
					//��Ϊ��һ��������������ֵ
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
			//��Ϊ����
			//(1)����ԭʼ����ĵ�һ����ԭʼ�����ȴ���1��˵�����Լ��÷�����
			//(2)���ǵ�һ�� ˵���ϴεĲ����÷�����

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
			//��value�з���"/"ֻ��˵��ǰһ��paraû�и��Ϻ��ʵ�ֵ
			cout << strPara << endl;
			break;
		}
	 
	 
		prevPara = strPara;
		 
	}

	return 0;
}

