// CircularList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node
//{
//	node * next;
//	int data;
//	node()
//	{
//		next = NULL;
//		data = 0;
//	}
//	node(int tx)
//	{
//		next = NULL;
//		data = tx;
//	}
//};
//
//typedef node * mlist;
//
//void CreateListTail(mlist mList )
//{
//	node* s; node* r;
//	//让list指向r结点
//	r = mList;
//	for (int i = 1; i < 30; i++)
//	{
//		s = new node(i);
//		//r结点指向下一个结点
//		//当i为1时，此时头结点指向s结点。此后s一直往后，但头结点的位置不变
//		r->next = s;
//		r = s;
//
//	}
//	r->next = mList;
//
//}
//
//size_t lenth(mlist list1)
//{
//	mlist tmp = list1;
//	int len = 0;
//	if (!tmp->next)
//	{
//		return 0;
//	}
//	while (tmp->next!=list1)
//	{
//		tmp = tmp->next;
//		len++;
//	}
//	return len;
//}
//
////有15个人排成一圈，并给他们1～15的编号。现在从1号开始报数，报数字4的人退出
////队列，余下的人从退出者下一个位置开始继续刚才的报数，直到整个队列只剩下一个人为止。请问这个人是几
////号?
//void Josephus(mlist list1,int i)
//{
//	mlist tmp = list1;
//	int j = 1;
//	int len = lenth(list1);
//	while (len>=1)
//	{
//		if (len== 1 && tmp->next->data != 0)
//		{
//			printf("%d ", tmp->next->data);
//			break;
//		}
//		
//		if (tmp->next->data!=0)
//		{
//			j++;
//			tmp = tmp->next;
//		}
//		else
//		{
//			tmp = tmp->next;
//			continue;
//		}
//
//	
//		if (j==i&&tmp->next->data!=0)
//		{
//			 
//			printf("%d ", tmp->next->data);
//			node * r = tmp->next;
//			tmp->next = r->next;
//			delete(r);
//			j = 1;
//			len--;
//		}
//	 
//	}
//
//}
//int main()
//{
//	mlist list1=new node();
//	CreateListTail(list1);
//	int len = lenth(list1);
//	Josephus(list1,11);
//
//	return 0;
//}
//


#include <iostream>
using namespace std;

typedef struct student
{
	int data;
	struct student *next;
} node, *LinkList;
//约瑟夫环
void printfList(LinkList head)
{

	LinkList p = head;
	if (head != NULL)
	{

		do
		{
			cout << p->data << " ";
			p = p->next;
		} while (p != head);  //这里出现过问题，用do-while
		cout << endl;
	}
}
void Josephus(int n, int k, int m)
{
	int i = 2;
	LinkList head = (LinkList)malloc(sizeof(node));
	head->next = head;
	head->data = 1;
	LinkList pre = head;
	while (i <= n)
	{
		LinkList p = (LinkList)malloc(sizeof(node));
		p->data = i;
		p->next = pre->next;
		pre->next = p;
		pre = p;
		i++;
	}
	//printfList(head);

	LinkList mend = pre;
	int kk = 0;
	while (kk != k)
	{
		mend = mend->next;
		++kk;
	}//找到k个开始

	while (n--) //要全部输出
	{
		int mm = 1;
		pre = mend;//每次都要给pre从新复值否则程序错误
		while (mm != m) //不是要求的数，指针每次往前推一步，mend指向报数的人，pre指向前一个
		{
			pre = mend;
			mend = mend->next;
			mm++;
		}
		pre->next = mend->next;//前一个链到下一个准备报数的
		cout << mend->data << endl;
		LinkList deletem = mend;
		mend = pre->next;//mend指向报数的人；
		free(deletem); //最后删除
	}
}
int main()
{
	Josephus(5, 1, 2);
	return 0;
}