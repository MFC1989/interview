#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#include <iostream>
using namespace std;



struct LinkStack
{
	int data;
	LinkStack * next;
};


//初始化
LinkStack * InitStack()
{
	LinkStack * s = (LinkStack *)malloc(sizeof(LinkStack));
	s->data = 0;
	s->next = NULL;
	return s;
}

//插入元素--入栈
void push(LinkStack * s, int t)
{
	LinkStack * node = (LinkStack *)malloc(sizeof(LinkStack));
	node->data = t;
	node->next = s->next;	//典型的链表头插法
	s->next = node;
}

//出栈
void pop(LinkStack * s)
{
	LinkStack * node = s->next;
	if (!node)
	{
		return;
	}
	s->next = node->next;
	free(node);
}

//销毁栈
void DestoryLinkStack(LinkStack * s)
{
	while (s->next!=NULL)
	{
		LinkStack * node;
		if (s->next)
		{
			node = s->next;
			s->next = node->next;
			free(node);
		}
	}
	free(s);
}

//求长度
int getLen(LinkStack * s)
{
	int len = 0;
	LinkStack *  tmp = s;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}

	return len;
}

//是否为空
bool isEmpty(LinkStack * s)
{
	if (s->next==NULL)
	{
		return true;
	}
	return true;
}


int main()
{
	LinkStack * s = InitStack();
	push(s, 1);
	push(s, 2);
	cout << getLen(s) << endl;;
	DestoryLinkStack(s);
	_CrtDumpMemoryLeaks();

	return 0;
}
