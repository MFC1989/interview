// effectiveSTL19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <set>
#include <vector>
#include <iostream>
using namespace std;

class mPoint
{
public:
	int x;
	int y;

	mPoint();

	mPoint(int tx, int ty)
	{
		x = tx;
		y = ty;
	}

	bool operator ==( const mPoint& rhs) const
	{
		return this->x == rhs.x && this->y==rhs.y;			//相等性 a.x==b.x && a.y==b.y才认为相等
	}
	
};

class setCmp 
{
public:
	bool operator() (const mPoint& lhs, const mPoint& rhs) const
	{
		return lhs.x < rhs.x;
	}
};

void fillSet(set<mPoint,setCmp> & paraSet)
{
	paraSet.insert(mPoint(1, 2));			//insert函数使用等价性来插入，在本例中如果a.x>b.x==false && a.x<b.x==false 则认为a和b等价	
	paraSet.insert(mPoint(1, 3));			//此时临时对象mPoint(1,3)不会被插入
	paraSet.insert(mPoint(1, 4));			//临时对象mPoint(1,4)也不会插入	
}


int main( )
{
	set<mPoint,setCmp> mSet;
	fillSet(mSet);

	set<mPoint,setCmp>::iterator its=find( mSet.begin(),mSet.end(),mPoint(1,3));
	if (its!=mSet.end())
	{
		cout << "全局算法find使用使用相等性查找出的值为" << "mPoint.x=" << (*its).x << "   " << "mPoint.y=" << (*its).y << endl;
	}
	else
	{
		cout << "全局算法使用相等性查找未查找到想要的值" <<endl;
	}

	its = mSet.find(mPoint(1, 3));
	if (its != mSet.end())
	{
		cout << "关联性容器自带算法find使用使用等价性查找出的值为" << "mPoint.x=" << (*its).x << "   " << "mPoint.y=" << (*its).y << endl;
	}
	else
	{
		cout << "关联性容器算法使用等价性查找未查找到想要的值" << endl;
	}

	return 0;
}

