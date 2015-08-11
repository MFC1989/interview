// LinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG


void mSwap(int & lhs,int &rhs)
{
	int tmp;
	tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

struct Node
{
	int data;
	Node * Next;
	Node(int tData)
	{
		data = tData;
		Next = NULL;
	}
	Node()
	{
		data = 0;
		Next = NULL;
	}
};

typedef   Node* mNode;

//头插法建立链表
void CreateListFront(Node * mList)
{
	Node * pTmp;
	for (int i = 1; i < 20000; i++)
	{
		pTmp = new Node(i);
		pTmp->Next = mList->Next;
		mList->Next = pTmp;
	}
}

//尾插法建立链表
void CreateListTail(Node * mList)
{
	Node* s; Node* r;
	//让list指向r结点
	r = mList;
	for (int i = 1; i < 5; i++)
	{
		s = new Node(i);
		//r结点指向下一个结点
		//当i为1时，此时头结点指向s结点。此后s一直往后，但头结点的位置不变
		r->Next = s;
		r = s;

	}
	r->Next = NULL;

}

//搜索链表
bool Search(Node * mList, int Elem)
{
	Node * NodeTmp = mList->Next;
	while (NodeTmp)
	{
		if (Elem == NodeTmp->data)
		{
			printf("找到了 %d\n", Elem);
			return true;
		}
		NodeTmp = NodeTmp->Next;
	}

	printf("未找到 %d\n", Elem);
	return false;
}

//打印(遍历)链表
void printList(Node *mList)
{
	Node * NodeTmp;
	if (mList->Next)
	{
		NodeTmp = mList->Next;
	}
	else
	{
		puts("link list is empty");
		return;
	}
	while (NodeTmp->Next)
	{
		printf("%d ", NodeTmp->data);

		NodeTmp = NodeTmp->Next;
	}
	printf("%d ", NodeTmp->data);
	printf("\n");
}
//获取长度
int GetLength(Node *mList)
{
	int len = 0;
	Node * NodeTmp = mList->Next;
	while (NodeTmp)
	{
		len++;
		NodeTmp = NodeTmp->Next;
	}
	printf("链表长度为 %d \n", len);
	return len;
}

//从链表中删除元素
bool Delete(Node * mList, int Elem)
{
	Node * NodeTmp = mList;
	while (NodeTmp)
	{
		if (Elem == NodeTmp->Next->data)
		{
			Node * freeNode = NodeTmp->Next;
			NodeTmp->Next = NodeTmp->Next->Next;
			free(freeNode);
			return true;
		}
		NodeTmp->Next = NodeTmp;
	}
	return false;
}

//在尾部添加元素
void push_back(Node * mList, int Elem)
{
	Node * NodeTmp = mList;
	Node * AddNode = new Node(Elem);
	while (NodeTmp->Next)
	{
		NodeTmp = NodeTmp->Next;
	}
	NodeTmp->Next = AddNode;
}

//删除掉最后一个元素
void pop_back(Node * mList)
{
	Node * NodeTmp = mList->Next;
	while (NodeTmp->Next->Next)
	{
		NodeTmp = NodeTmp->Next;
	}
	free(NodeTmp->Next);
	NodeTmp->Next = NULL;
}

//链表置空
void clear(Node * mList)
{
	Node * NodeTmp = mList->Next;
	while (NodeTmp->Next->Next)
	{
		Node *NodeCon = NodeTmp->Next->Next;
		Node *NodeDel = NodeTmp->Next;
		NodeTmp->Next = NodeCon;
		delete(NodeDel);
	}
	delete(NodeTmp->Next);
	delete(NodeTmp);
	mList->Next = NULL;
}

Node* reverseList(Node * mList)
{
	//新建一个头结点
	Node * head = new Node;

	Node * oldNode = mList->Next;			//原链表的第一个节点
	while (oldNode)
	{
		Node * tmpNode = new Node;			//创建一个临时节点
		tmpNode->data = oldNode->data;		//将原链表中的节点复制到临时节点，并插入到新链表(头插法)
		tmpNode->Next = head->Next;
		head->Next = tmpNode;

		Node * nodeForDel = oldNode;		//保存原链表中已插入到新链表中的节点	
		oldNode = oldNode->Next;			//遍历原链表的下一个节点
		delete(nodeForDel);					//删除原链表中值已插到新链表中的节点	
	}
	delete(mList);
	return head;

}

Node* ReverseList2(Node* head)
{
	if (NULL == head || NULL == head->Next) return head;    //少于两个节点没有反转的必要。
	Node* p;
	Node* q;
	Node* r;
	p = head;
	q = head->Next;
	head->Next = NULL; //旧的头指针是新的尾指针，next需要指向NULL
	while (q){
		r = q->Next; //先保留下一个step要处理的指针
		q->Next = p; //然后p q交替工作进行反向
		p = q;
		q = r;
	}
	head = p; // 最后q必然指向NULL，所以返回了p作为新的头指针
	return head;
}

Node * uniqueList(Node * mList)
{
	mNode p, q, r;
	p = mList->Next;
	while (p)
	{
		q = p;
		while (q->Next)
		{
			if (q->Next->data==p->data)
			{
				r = q->Next;
				q->Next = r->Next;
				delete(r);
			}
			else
			{
				q = q->Next;
			}

		}
		p = p->Next;
	}
	return NULL;
}

Node * Sort(Node * mList)
{
	//选择排序
	mNode p, q, small;
	int tmp;

	for (p = mList->Next; p->Next != NULL;p=p->Next)
	{
		small = p;
		for (q = p->Next; q;q=q->Next)
		{
			if (q->data<small->data)
			{
				small = q;
			}
		}
		if (small!=p)
		{
			mSwap(small->data,p->data);
		}
	}
	return mList;
}

Node * Insert(Node * mList,int num)			//insert操作的前提是链表有序 所以函数执行前要先排序
{

	//Sort(mList);
	mNode p = mList->Next;
	mNode q = new Node();
	while (p)
	{
		//如果是插入尾部
		if (!p->Next)
		{
			q->data = num;
			q->Next = NULL;
			p->Next = q;
			break;
		}else if (p->data<=num&&p->Next->data>num)
		{
			q->data = num;
			q->Next = p->Next;
			p->Next = q;
			break;
		}
		p = p->Next;
	}

	return mList;
}

//删除表中所有值大于mink且小于maxk的元素
void deleteRange(mNode mList,int mink,int maxk)
{
	mNode nodeTmp= mList;
	bool jump = true;
	while (nodeTmp)
	{
		if (nodeTmp->Next)
		{
			while (nodeTmp->Next->data>mink&&nodeTmp->Next->data<maxk)
			{
				mNode freeNode = nodeTmp->Next;
				nodeTmp->Next = nodeTmp->Next->Next;
				free(freeNode);
				if (!nodeTmp->Next)
				{
					break;
				}
			}
		}
		nodeTmp = nodeTmp->Next;
	}

}

//将一个list连在另一个list的后面
void splice(mNode mList1, mNode mList2)
{
	//先找到list1的最后一个
	mNode list1=mList1;
	while (list1->Next)
	{
		list1 = list1->Next;
	}

	mNode list2Head = mList2->Next;
	while (list2Head->Next)
	{
		list1->Next = list2Head;
		list1 = list1->Next;
		list2Head = list2Head->Next;
	}

}

//求交集
mNode ListUnion(mNode mlist1,mNode mlist2)
{
	
	bool isUnion = false;
	mNode res=new Node();
	mNode pres = res;
	mNode list1 = mlist1;
	mNode list2 = mlist2;
	while (list1->Next&&list2->Next)
	{
		mNode tmp1 = list1->Next;
		mNode tmp2 = list2->Next;
		while (tmp1)
		{
			if (tmp2->data!=tmp1->data)
			{
				if (tmp2->Next)
				{
					tmp2 = tmp2->Next;
				}
				else
				{
					break;
				}
			}
			else
			{
				printf("%d ",tmp1->data);
				mNode nodeUnion = new Node();
				nodeUnion->data = tmp1->data;
				pres->Next = nodeUnion;
				pres = pres->Next;
				isUnion = true;
				break;
			}
			
		}
		list1 = list1->Next;
			
	}

	if (isUnion)
	{
		return res;
	}
	else
	{
		free(res);
		return NULL;
	}

}

//找出链表中间的元素
//void findMidElement(mNode mlist1)
//{
//	Node * p = mlist1;
//	Node * q = p->Next;
//	while (q)
//	{
//		p = p->Next;
//		if (q)
//		{
//			q = q->Next;
//		}
//		if (q)
//		{
//			q = q->Next;
//		}
//	}
//	printf("链表中间的元素为%d\n", p->data);
//	
//}


//倒数第K个元素

/*
 *	（1）本方法利用了两节点之间间隔K，然后节点1到尾部时，节点2刚好是第K个
	（2）还有一种办法，先遍历一次链表，得到链表的长度，从而得到倒数第K个节点
 */
void findBackwardKElement(mNode mList,int k)  
{
	int index = k;
	mNode p1 = mList->Next;
	mNode p2 = mList->Next;

	if (k<0||k>GetLength(mList))
	{
		return;
	}

	while (k>1)
	{
		k--;
		p1 = p1->Next;
	}
	
	while (p1->Next)
	{
		p1 = p1->Next;
		p2 = p2->Next;
	}

	printf("倒数第%d个元素为%d", index,p2->data);
}


void findBackwardKElement1(mNode mList, int k)
{
	int len = GetLength(mList);
	int index = len - k;
	if (index<0)
	{
		return;
	}

	mNode p = mList->Next;
	int tmpIndex = 0;
	while (tmpIndex<index)
	{
		if (p->Next)
		{
			p = p->Next;
			tmpIndex++;
		}
		else
		{
			break;
		}
	}

	printf("倒数第%d个元素为%d", k, p->data);

}


int main()
{
	//初始化链表
	Node * list1=new Node();
	Node * list2 = new Node();
	/*CreateListTail(list2);
	CreateListTail(list1);
	printList(list1);
	printList(list2);
	splice(list1, list2);
	printList(list1);
	printList(list2);*/

	push_back(list1, 1);
	push_back(list1, 2);
	push_back(list1, 3);
	push_back(list1, 4);
	push_back(list1, 5);

 
	/*push_back(list1, 2);
	push_back(list1, 2);*/
	findBackwardKElement(list1, 20);
	findBackwardKElement1(list1, 20);
	_CrtDumpMemoryLeaks();

	return 0;
}


