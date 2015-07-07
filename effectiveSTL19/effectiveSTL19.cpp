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
		return this->x == rhs.x && this->y==rhs.y;			//����� a.x==b.x && a.y==b.y����Ϊ���
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
	paraSet.insert(mPoint(1, 2));			//insert����ʹ�õȼ��������룬�ڱ��������a.x>b.x==false && a.x<b.x==false ����Ϊa��b�ȼ�	
	paraSet.insert(mPoint(1, 3));			//��ʱ��ʱ����mPoint(1,3)���ᱻ����
	paraSet.insert(mPoint(1, 4));			//��ʱ����mPoint(1,4)Ҳ�������	
}


int main( )
{
	set<mPoint,setCmp> mSet;
	fillSet(mSet);

	set<mPoint,setCmp>::iterator its=find( mSet.begin(),mSet.end(),mPoint(1,3));
	if (its!=mSet.end())
	{
		cout << "ȫ���㷨findʹ��ʹ������Բ��ҳ���ֵΪ" << "mPoint.x=" << (*its).x << "   " << "mPoint.y=" << (*its).y << endl;
	}
	else
	{
		cout << "ȫ���㷨ʹ������Բ���δ���ҵ���Ҫ��ֵ" <<endl;
	}

	its = mSet.find(mPoint(1, 3));
	if (its != mSet.end())
	{
		cout << "�����������Դ��㷨findʹ��ʹ�õȼ��Բ��ҳ���ֵΪ" << "mPoint.x=" << (*its).x << "   " << "mPoint.y=" << (*its).y << endl;
	}
	else
	{
		cout << "�����������㷨ʹ�õȼ��Բ���δ���ҵ���Ҫ��ֵ" << endl;
	}

	return 0;
}

