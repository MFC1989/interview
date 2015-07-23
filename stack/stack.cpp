// stack.cpp : �������̨Ӧ�ó������ڵ㡣
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

void ClearStack(SequenceStack *s)				//��S��Ϊ��ջ
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
			����realloc:
			���жϵ�ǰ��ָ���Ƿ����㹻�������ռ䣬����У�����mem_addressָ��ĵ�ַ�����ҽ�mem_address���أ�����ռ䲻�����Ȱ���newsizeָ���Ĵ�С����ռ䣬��ԭ�����ݴ�ͷ��β�������·�����ڴ����򣬶����ͷ�ԭ��mem_address��ָ�ڴ�����ע�⣺ԭ��ָ�����Զ��ͷţ�����Ҫʹ��free����ͬʱ�����·�����ڴ�������׵�ַ�������·���洢����ĵ�ַ
		*/
		s->top = s->base + s->Size;			//ΪʲôҪ��s.top���¸�ֵ����Ϊrelloc���������Ե��µġ�--����������ע��
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

