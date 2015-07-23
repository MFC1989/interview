// stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
using namespace std;
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG


const int STACK_INIT_SIZE=3;
const int STACK_INCREMENT=2;


struct SequenceStack
{
	int  *base;
	int  * top;
	int Size;
};


bool InitStack(SequenceStack * s)
{
	s->base=(int* )malloc(STACK_INIT_SIZE*sizeof(int));
	s->top = s->base;
	s->Size = STACK_INIT_SIZE;

	if(!s->base)
	{
		return false;
	}
	return true;
}

bool DestoryStack(SequenceStack * s)
{
	free(s->base);
	s->base = NULL;
	s->top = NULL;
	s->Size = 0;
	return true;
}

void ClearStack(SequenceStack *s)				//把S置为空栈
{
	s->top = s->base;
}

bool StackIsEmpty(SequenceStack * s)
{
	if (s->base==s->top)
	{
		return true;
	}
	return false;
}

size_t StackLenth(SequenceStack *s)
{
	return s->top - s->base;
}

int StackGetTop(SequenceStack *s)
{
	if (s->base==s->top)
	{
		return 0;
	} 
	else
	{
		return *(s->top - 1);
	}
}

void push(SequenceStack * s, int t)
{
	if (s->top-s->base>=s->Size)
	{
		s->base = (int *)realloc(s->base, (s->Size + STACK_INCREMENT)*sizeof(SequenceStack));
	
		if (!s->base)
		{
			return;
		}

		/*
			关于realloc:
			先判断当前的指针是否有足够的连续空间，如果有，扩大mem_address指向的地址，并且将mem_address返回，如果空间不够，先按照newsize指定的大小分配空间，将原有数据从头到尾拷贝到新分配的内存区域，而后释放原来mem_address所指内存区域（注意：原来指针是自动释放，不需要使用free），同时返回新分配的内存区域的首地址。即重新分配存储器块的地址
		*/
		s->top = s->base + s->Size;			//为什么要对s.top重新赋值，因为relloc函数的特性导致的。--具体见上面的注释
		s->Size += STACK_INCREMENT;
	}
	
	*(s->top) = t;
	s->top++;
}

int pop(SequenceStack *s)
{
	 return  *(--s->top);
}


int main()
{
	SequenceStack s;
	InitStack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	cout << StackGetTop(&s) << endl;
	cout<<pop(&s) << endl;
	cout << StackGetTop(&s) << endl;

	
	DestoryStack(&s);

	_CrtDumpMemoryLeaks();
	return 0;
}

