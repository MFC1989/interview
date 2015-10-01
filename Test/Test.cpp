//// Test.cpp : Defines the entry point for the console application.
////
//
//
#include "stdafx.h"
//
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//
//#ifdef _DEBUG
//#ifndef DBG_NEW
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#define new DBG_NEW
//#endif
//#endif  // _DEBUG
//
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <fstream>
#include <memory>
#include <set>
#include <algorithm>
#include <map>
#include <hash_set>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <stack>
#include <queue>
using namespace std;

struct st_t
{
	int status;
	short *pdata;
	char errstr[32];
};

st_t st[16];
char *p = (char *)(st[2].errstr + 32);


class B
{
	double a;
	short b;
	int c;
	char d;
};

//统计文章中每个单词出现的次数
void countWord()
{
	typedef unordered_map<string, int> hashMap;

	hashMap wordCols;
	ifstream readFile;
	readFile.open("ReadMe.txt");
	string tmp;
	while (readFile >> tmp)
	{
		wordCols[tmp]++;
	}
}


//假定输入的字符串中只包含字母和* 号。编写函数fun，功能是，除了中间和尾部的*号外，

//将字符串中其他* 号全部删除。编写时，不用c的其他函数。

void fun(char *a)
{

	int j = 0;

	char *p = a;

	while (*p == '*')p++;

		while (*p){

			a[j++] = *p;

			p++;

		}

	a[j] = 0;

}


class mClass 
{
public:
	mClass()
	{
		cout << "default constructor!" << endl;
	}
	mClass  (const mClass & tmp)
	{
		cout << "copy constructor!" << endl;

	}
	
	mClass & operator = (const mClass & tmp)
	{
		cout << "assign operator!" << endl;
		return *this;
	}

};

void testMem()
{
	vector<shared_ptr<int>> vec;
	vec.push_back(shared_ptr<int>(new int(5)));
}


vector<int> productExceptSelf(vector<int>& nums) {

	bool isExistSingleZero = false;
	
	int zeroNum = count(nums.begin(), nums.end(), 0);
	
	if (zeroNum==nums.size())
	{
		return nums;
	}

	if (zeroNum>1)
	{
		fill(nums.begin(),nums.end(),0);
		return nums;
	}

	if (zeroNum==1)
	{
		isExistSingleZero = true;
	}
	 
	int products = 1;
	for (int i : nums)
	{
		if (i != 0)
		{
			products *= i;
		}

	}

	for (int & i : nums)
	{
		if (i == 0)
		{
			i = products;
		}
		else
		{
			if (isExistSingleZero)
			{
				i = 0;
			}
			else
			{
				i = products / i;
			}
		}

	}

	return nums;
}

#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>
#include <memory>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <functional>
using namespace std;

int missingNumber(vector<int>& nums) {
	
	sort(nums.begin(), nums.end());
	
		if (nums[0] != 0)
		{
			return 0;
		}
		


	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] + 1 != nums[i + 1])
		{
			return nums[i] + 1;
		}
	}

	return nums[nums.size()-1] + 1;
}

int findPeakElement(vector<int>& nums) {
	auto len = nums.size();
	if (len==1)
	{
		return 0;
	}
	if (len==2)
	{
		auto max=max_element(nums.begin(), nums.end());
		return distance(nums.begin(), max);
	}
	for (auto i = 1; i < len;i++)
	{
		if (nums[i]>nums[i-1]&&nums[i]>nums[i+1])
		{
			return i;
		}
	}

}

bool check(const vector<int> &vec,int k)
{
	for (int i : vec)
	{
		for (int j: vec )
		{
			if (i!=j&&abs(i-j)<=k)
			{
				return true;
			}
		}
	}
	return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_map<int,vector<int>>cols;   //此处使用哈希表速度较快
	int index = 0;
	for (auto i : nums)
	{
		cols[i].push_back(index++);
	}

	vector<int> VaildIndexCols;
	for (auto i : cols)
	{
		if (i.second.size()>1)
		{
			VaildIndexCols = i.second;
			if (check(VaildIndexCols,k))
			{
				return true;
			}
		}
	}

	return false;

}

int foo(int n)
{
	if (n < 2)return n;
	return foo(n - 1) + foo(n - 2);
}


unordered_set<int> getIntersection(vector<int>left,vector<int>right)
{
	unordered_set<int> res;
	unordered_set<int> cols{ left.begin(), left.end() };
	for (auto i : right)
	{
		if (cols.find(i)!=cols.end())
		{
			res.insert(i);
		}
	}

	return res;
}

bool cmp(string left, string right)
{
	return left[0] > right[0];
}

string largestNumber(vector<int>& nums) {
	
	vector<string> vecStr;
	string str;
	
	char buff[32] = { 0x00 };
	
	for (auto i : nums)
	{
		sprintf(buff, "%d", i);
		vecStr.push_back(buff);
	}

	std::sort(vecStr.begin(), vecStr.end(),cmp);
	for (auto i :vecStr)
	{
		str.append(i);
	}
	return str;
}


//二分查找 递归
bool binSearch(int * array, int begin, int end, int key)
{
	int left = begin;
	int right = end;

	if (left <= right)
	{
		int mid = (left + right) / 2;
		if (array[mid] == key)
		{
			return true;
		}
		else
		{
			return binSearch(array, left, mid - 1, key) || binSearch(array, mid + 1, right, key);
		}
	}
	else
	{
		return false;
	}
}

//（1）扫描数组，找到数组中的最大数max，最小数min
//（2）将[min, max]区间平均分为n-1个区间段（每个区间段对应一个桶），每个桶用一对有序实数对[a,b] 来表示桶内的数。
//（3）再次从头到尾扫描数组，将每个元素添加到相应的桶bucket里面。 注意：有的桶为空（不含任何数据）
//（4）然后按顺序访问每个（非空）的相邻的桶进行比较。
//若两个非空的相邻的桶分别为(a,b) , (c,d)，那么这两个非空相邻的桶的距离为 c-b。
//（5）最后选择最大的非空相邻同的距离返回即可。

#include <iostream>
#include <vector>
#include <utility>
using namespace std;


double maxDiff(double a[], int n){
	double max = a[0];
	double min = a[0];
	for (int i = 1; i < n; i++){
		if (max < a[i]){
			max = a[i];
		}
		if (min > a[i]){
			min = a[i];
		}
	}
	double bar = (max - min) / (n - 1);
	int pos;
	//pair<first,second> : first表示桶的左边界index，second表示桶的右边界index
	vector< pair<int, int> > buckets(n, make_pair(-1, -1));
	//这里桶内存相应数据的下标，而不是相应的数据，方便后面的数据计算，以免有精度损失。
	for (int i = 0; i < n; i++){
		pos = (int)((a[i] - min) / bar);
		if ((buckets[pos].first == -1) && (buckets[pos].second == -1)){ //下标比较，若为double型比较注意精度问题
			buckets[pos].first = buckets[pos].second = i;
		}
		else{
			if (a[buckets[pos].first] > a[i])
				buckets[pos].first = i;
			if (a[buckets[pos].second] < a[i])
				buckets[pos].second = i;
		}
	}
	int lastIx = 0;
	double max_diff = 0;
	double tmp_diff = 0;
	for (int i = 1; i < n; i++){ //计算桶之间的距离
		if ((buckets[i].first == -1) && (buckets[i].second == -1)){
			//桶为空的标志,不处理
		}
		else{
			tmp_diff = a[buckets[i].first] - a[buckets[lastIx].second];
			if (tmp_diff > max_diff){
				max_diff = tmp_diff;
			}
			lastIx = i;//lastIx指上一个非空桶的index，且第一个桶和最后一个桶肯定非空。
		}
	}
	return max_diff;
}


int getJumpDis(int n)
{
	int res=n;
	if (n==1)
	{
		return res;
	}
	else if (n>1)
	{
		while (n > 1)
		{
			n /= 2;
			res += 2*n ;

		}
		return res;
	}
	
	return 0;
}

int getJumpDisSum(int a,int b,int c,int d )
{
	int res = getJumpDis(a) + getJumpDis(b) + getJumpDis(c) + getJumpDis(d);
	
	return res;
}


//猴子分桃

 int getTotalApples(int bearsNum)
 {
	
	 int index;
	 vector<int> buff;
	 buff.resize(bearsNum);

	 buff[0] = 1;

	 while (true)
	 {
		 for (index = 1; index < buff.size(); index++)
		 {
			 if ((buff[index - 1] * bearsNum + 1) % (bearsNum-1) != 0)
				 break;
			 buff[index] = (buff[index - 1] * bearsNum + 1) / (bearsNum - 1);
		 }

		 if (index >= bearsNum)
		 {
			 break;
		 }
		 buff[0]++;
	 }

	 return bearsNum * buff[bearsNum - 1] + 1;
	}


 int f(int p,int n)
 {
	 set<int > cols;
	 
	 for (int i = 0; i < n;i++)
	 {
		 int tmp;
		 cin >> tmp;

		 if (cols.find(tmp)==cols.end())
		 {
			 cols.insert(tmp);
		 }
		 else
		 {
			 return i;
			 break;
		 }
			  
	 }


	 if (cols.size()==n)
	 {
		 return -1;
	 }
	 else
	 {
		 return cols.size();
	 }
 }




 struct ver 
 {
	 int major;
	 int minor;
	 int modifyTimes;

 public: 
 ver()
 {
	 major = 0;
	 minor = 0;
	 modifyTimes = 0;
 }


 };
 typedef ver VER;

 
 bool cmpf(const VER &a, const VER &b)
 {
	 return a.major > b.major;
 }

 void checkStr(string & s)
 {
	 for (int i = 0; i < s.size();i++)
	 {
		 if (s[i]=='.')
		 {
			 s[i] = ' ';
		 }
	 }
 }



 double findKernal()
 {
	 vector <VER> cols;

	 int n;
	 cin >> n;
	 
	 while (n--)
	 {
		 string str;
		 cin >> str;
		
		 checkStr(str);
		 if (count(str.begin(), str.end(), ' ') == 1)
		 {
			 stringstream ss(str);
			 VER tmp;
			 ss >> tmp.major >> tmp.minor;
			 cols.push_back(tmp);
		 }

		 if (count(str.begin(), str.end(), ' ') == 2)
		 {
			 stringstream ss(str);
			 VER tmp;
			 ss >> tmp.major >> tmp.minor >> tmp.modifyTimes;
			 cols.push_back(tmp);
		 }
	 }
	
	 
	 sort(cols.begin(), cols.end(), cmpf);
	 for (int m = 0; m < cols.size();m++)
	 {
		 auto i = cols[m];
		 if (i.minor%2==0)
		 {
			 if (i.modifyTimes!=0)
			 {
				 cout << i.major << "." << i.minor <<"."<< i.modifyTimes;
			 }
			 else
			 {
				 cout << i.major << "." << i.minor;
			 }
			 return 0;
		 }
	 }
	 cout << "no stable available" << endl;
	 return 0;
 }

 void initVec(vector<int> & v)
 {
	 
	 int len;
	 cin >> len;
	for (int i = 0; i < len; i++)
	 {
		 int tmp;
		 cin >> tmp;
		 v.push_back(tmp);
	 }
 }

 void checkStr2(string & s)
 {
	 for (int i = 0; i < s.size(); i++)
	 {
		 if (s[i] == '\t')
		 {
			 s[i] = ' ';
		 }
	 }
 }

 void checkStr3(string & s)
 {
	 for (int i = 0; i < s.size(); i++)
	 {
		 if (s[i] == ',')
		 {
			 s[i] = ' ';
		 }
	 }
 }

 void f()
 {
	 vector<int> vec1, vec2, vec3;
	 initVec(vec1);
	 initVec(vec2);
	 initVec(vec3);
	 sort(vec1.begin(), vec1.end());
	 sort(vec2.begin(), vec2.end());
	 sort(vec3.begin(), vec3.end());
	 
	 int len = vec1.size()+vec2.size()+vec3.size();

	 vector<int>buff1,buff2,res;
	 buff1.resize(len);
	 buff2.resize(len);
	 res.resize(len);
	 auto it=set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buff1.begin());
	 buff1.resize(it - buff1.begin());

	 it=set_intersection(vec3.begin(), vec3.end(), vec2.begin(), vec2.end(), buff2.begin());
	 buff2.resize(it - buff2.begin());

	 sort(buff1.begin(), buff1.end());
	 sort(buff2.begin(), buff2.end());
	 it=set_intersection(buff1.begin(), buff1.end(), buff2.begin(), buff2.end(), res.begin());
	 res.resize(it - res.begin());

	 if (!res.empty())
	 {
		 for (int i = 0; i < res.size();i++)
		 {
			 cout << res[i] << " ";
		 }
	 }
 }


 struct St 
 {
 typedef vector<int>::iterator mit;
	 int a;
	 int b;
	 int c;
 };

 void f2()
 {
	 int n;
	 vector<St> vec;
	 cin >> n;
	 while (n--)
	 {
		 string str;
		 cin.sync();
		 getline(cin, str);
		 stringstream ss(str);
		 int flag = count(str.begin(), str.end(), ',');
		 if (flag==0)
		 {
			 St tmp;
			 ss >> tmp.a >> tmp.b >> tmp.c;
		 }
		 else
		 {
			 int len = flag + 1;
			 vector<int>buff;
			 buff.resize(len);
			 int a;
			 string s;
			 s.resize(str.size());
			 int c;
			 int pos1 = str.find_first_of('\t');
			 int pos2 = str.find_last_of('\t');
			 
			 std::copy(str.begin() + pos1 + 1, str.begin() + pos2, s.begin());
			 
			 checkStr3(s);
			 for (int i = 0; i < len;i++)
			 {
				 stringstream ss2(s);
				 ss2 >> buff[i];
			 }

			 
		 }
	 }
 }



 //int MaxSum(int c, int *a)
 //{
	// int sum = 0, b = 0;
	// for (int i = 1; i <= c; i++)
	// {
	//	 if (b > 0)
	//	 {
	//		 b += a[i];
	//	 }
	//	 else
	//	 {
	//		 b = a[i];
	//	 }
	//	 if (b > sum)
	//	 {
	//		 sum = b;
	//	 }
	// }
	// return sum;
 //}

 //int MaxSum2(int r, int c, int **a)
 //{
	// int sum = 0;
	// int *b = new int[c + 1];
	// for (int i = 0; i < r; i++)//枚举行  
	// {
	//	 for (int k = 0; k < c; k++)
	//	 {
	//		 b[k] = 0;
	//	 }

	//	 for (int j = i; j < r; j++)//枚举初始行i,结束行j  
	//	 {
	//		 for (int k = 0; k < c; k++)
	//		 {
	//			 b[k] += a[j][k];//b[k]为纵向列之和  
	//			 int max = MaxSum(c, b);
	//			 if (max > sum)
	//			 {
	//				 sum = max;
	//			 }
	//		 }
	//	 }
	// }
	// return sum;
 //}
 

 void show()
 {
	 cout << "show" << endl;
 }

 void moveZeroes(vector<int>& nums) 
 {
	 for (auto & i :nums )
	 {
		 if (i==0)
		 {
			 i = INT_MAX;
		 }
	 }
 }



int main()
{
	
	
	vector<int>vecInt{ 2, 0, 5, 6, 4 };
	moveZeroes(vecInt);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	void(*pShow) ();
	pShow = &show;
	pShow();
	
	
	
	
	
	string strIn;
	getline(cin,strIn);
	int row = count(strIn.begin(), strIn.end(), ';') + 1;
	
	size_t pos = strIn.find_first_of(';');
	string tmpStr = strIn.substr(0, pos);
	int col = count(tmpStr.begin(), tmpStr.end(), ' ');


	int ** p=new int *[row];
	for (int i = 0; i < row;i++)
	{
		p[i] = new int[col];
	}

	strIn.erase(remove(strIn.begin(), strIn.end(), ';'), strIn.end());

	stringstream ss(strIn);

	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < col;j++)
		{
			ss >> p[i][j];
		}
	}
	
	



	mClass m1;
	mClass m2 = m1;
	mClass m3;
	m3 = m1;
	f2();
	f();
	findKernal();
	//P1是指针数组(存储指针的数组),他存有十个int * 指针
	int * p1[10];
	int (*p2)[10];
	cout << "指针数组P1的长度为"<<sizeof(p1) << endl;
	cout << "数组指针p2的长度为"<<sizeof(p2) << endl;


	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&a + 1);               //+1等于+5
	printf("%d,%d\n", *(a + 1), *(ptr - 1));  //-1等于-4 
	
	int apple = getTotalApples(5);
	//int res = getJumpDisSum(4, 90, 80, 70);
	int array[5] = { 1, 2, 3, 4, 5 };
	bool r = binSearch(array, 0, 5, 5);

	vector<int> vec{ 10, 2 };
	string str = largestNumber(vec);
	return 0;
}


//使用C++11标准库提供的容器unordered_set（基于哈希表，查询时间复杂度约为O(1)）
//此代码在C++11环境(如GCC4.8，VS2013等)下能运行，
//在C++98下要将unordered_set改成set容器，set使用红黑树，查询速度慢于哈希表。

#include<iostream>
#include<vector>
#include<unordered_set>
#include <limits.h>

using namespace std;





int  MaxSumSubArray(int Array[], int Len)
{
	if (Array == NULL || Len <= 0)
	{
		printf("input error");
	}

	int res = INT_MIN;   // 初始sum为最小32位有符号数
	int curSum = 0;
	for (int i = 0; i < Len; ++i)
	{
		if (curSum <= 0)
			curSum = Array[i];
		else
			curSum += Array[i];

		if (curSum > res)
			res = curSum;
	}
	return res;
}

//#include<stdio.h>
//
//int div(int a,int b, int &rem)
//{
//	int n = 0;
//	int nPos = -1;
//	unsigned long long diva = b;
//	unsigned long long divb = a;
//
//	while (diva < divb)
//	{
//		diva <<= 1;
//		nPos++;
//	}
//
//	diva >>= 1;
//
//	while (nPos > -1)
//	{
//		if (divb >= diva)
//		{
//			n += (1 << nPos);
//			divb -= diva;
//		}
//
//		diva >>= 1;
//		nPos -= 1;
//	}
//
//	rem = (int)divb;
//	return n;
//}
//
//int divide(int a, int b, int & quo, int &rem)
//{
//	quo=div(a, b, rem);
//	return quo;
//}
//
//int main()
//{
//	int a=4;
//	int b=1;
//	int rem;
//	int quo;
//	int res = div(b, a,  rem);
//	return 0;
//}