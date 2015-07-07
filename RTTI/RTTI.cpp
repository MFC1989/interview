// RTTI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class base
{
public:
	int x;
	base()
	{
		x = 100;
	};
	virtual void f();
	
};


void base::f()
{

}

class child : public base
{
public:
	child(){};

};


int _tmain(int argc, _TCHAR* argv[])
{

	child *mChild= new child();
	base * mBase = dynamic_cast<child *>(mChild);

	return 0;
}

