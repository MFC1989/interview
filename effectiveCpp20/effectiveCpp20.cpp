// effectiveCpp20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class MemberVar1
{
public:
	MemberVar1(){ cout << "member var 1 construct!" << endl; }
	MemberVar1(const MemberVar1 &rh)
	{
		*this=(MemberVar1)rh;
		cout << "member var 1 copy construct!" << endl;
	}

	~MemberVar1(){ cout << "member var 1 destruct!" << endl; }
};


class mClass
{
public:
	MemberVar1 m_memVar1;

	mClass()
	{
		cout << "class construct!" << endl; 
	};
		mClass(const mClass & rh)
		{
			this->m_memVar1 = rh.m_memVar1;
			cout << "class copy construct" << endl;
		}
		~mClass(){ cout << "class destruct!" << endl; }
};


void testConstRef(const mClass &tmp)
{

}

void testValue(mClass tmp)
{

}

void test()
{
	{
		cout << "传递const引用时的构造与析构过程：" << endl;
		mClass c1;
		testConstRef(c1);
	}

	{
		cout << "传递value时的构造与析构过程：" << endl;
		mClass c2;
		testValue(c2);
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	test();
	return 0;
}

