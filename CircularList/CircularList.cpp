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
//	//��listָ��r���
//	r = mList;
//	for (int i = 1; i < 30; i++)
//	{
//		s = new node(i);
//		//r���ָ����һ�����
//		//��iΪ1ʱ����ʱͷ���ָ��s��㡣�˺�sһֱ���󣬵�ͷ����λ�ò���
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
////��15�����ų�һȦ����������1��15�ı�š����ڴ�1�ſ�ʼ������������4�����˳�
////���У����µ��˴��˳�����һ��λ�ÿ�ʼ�����ղŵı�����ֱ����������ֻʣ��һ����Ϊֹ������������Ǽ�
////��?
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
//Լɪ��
void printfList(LinkList head)
{

	LinkList p = head;
	if (head != NULL)
	{

		do
		{
			cout << p->data << " ";
			p = p->next;
		} while (p != head);  //������ֹ����⣬��do-while
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
	}//�ҵ�k����ʼ

	while (n--) //Ҫȫ�����
	{
		int mm = 1;
		pre = mend;//ÿ�ζ�Ҫ��pre���¸�ֵ����������
		while (mm != m) //����Ҫ�������ָ��ÿ����ǰ��һ����mendָ�������ˣ�preָ��ǰһ��
		{
			pre = mend;
			mend = mend->next;
			mm++;
		}
		pre->next = mend->next;//ǰһ��������һ��׼��������
		cout << mend->data << endl;
		LinkList deletem = mend;
		mend = pre->next;//mendָ�������ˣ�
		free(deletem); //���ɾ��
	}
}
int main()
{
	Josephus(5, 1, 2);
	return 0;
}