// LinkList.cpp : �������̨Ӧ�ó������ڵ㡣
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

//ͷ�巨��������
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

//β�巨��������
void CreateListTail(Node * mList)
{
	Node* s; Node* r;
	//��listָ��r���
	r = mList;
	for (int i = 1; i < 5; i++)
	{
		s = new Node(i);
		//r���ָ����һ�����
		//��iΪ1ʱ����ʱͷ���ָ��s��㡣�˺�sһֱ���󣬵�ͷ����λ�ò���
		r->Next = s;
		r = s;

	}
	r->Next = NULL;

}

//��������
bool Search(Node * mList, int Elem)
{
	Node * NodeTmp = mList->Next;
	while (NodeTmp)
	{
		if (Elem == NodeTmp->data)
		{
			printf("�ҵ��� %d\n", Elem);
			return true;
		}
		NodeTmp = NodeTmp->Next;
	}

	printf("δ�ҵ� %d\n", Elem);
	return false;
}

//��ӡ(����)����
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
//��ȡ����
int GetLength(Node *mList)
{
	int len = 0;
	Node * NodeTmp = mList->Next;
	while (NodeTmp)
	{
		len++;
		NodeTmp = NodeTmp->Next;
	}
	printf("������Ϊ %d \n", len);
	return len;
}

//��������ɾ��Ԫ��
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

//��β�����Ԫ��
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

//ɾ�������һ��Ԫ��
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

//�����ÿ�
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
	//�½�һ��ͷ���
	Node * head = new Node;

	Node * oldNode = mList->Next;			//ԭ����ĵ�һ���ڵ�
	while (oldNode)
	{
		Node * tmpNode = new Node;			//����һ����ʱ�ڵ�
		tmpNode->data = oldNode->data;		//��ԭ�����еĽڵ㸴�Ƶ���ʱ�ڵ㣬�����뵽������(ͷ�巨)
		tmpNode->Next = head->Next;
		head->Next = tmpNode;

		Node * nodeForDel = oldNode;		//����ԭ�������Ѳ��뵽�������еĽڵ�	
		oldNode = oldNode->Next;			//����ԭ�������һ���ڵ�
		delete(nodeForDel);					//ɾ��ԭ������ֵ�Ѳ嵽�������еĽڵ�	
	}
	delete(mList);
	return head;

}

Node* ReverseList2(Node* head)
{
	if (NULL == head || NULL == head->Next) return head;    //���������ڵ�û�з�ת�ı�Ҫ��
	Node* p;
	Node* q;
	Node* r;
	p = head;
	q = head->Next;
	head->Next = NULL; //�ɵ�ͷָ�����µ�βָ�룬next��Ҫָ��NULL
	while (q){
		r = q->Next; //�ȱ�����һ��stepҪ�����ָ��
		q->Next = p; //Ȼ��p q���湤�����з���
		p = q;
		q = r;
	}
	head = p; // ���q��Ȼָ��NULL�����Է�����p��Ϊ�µ�ͷָ��
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
	//ѡ������
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

Node * Insert(Node * mList,int num)			//insert������ǰ������������ ���Ժ���ִ��ǰҪ������
{

	//Sort(mList);
	mNode p = mList->Next;
	mNode q = new Node();
	while (p)
	{
		//����ǲ���β��
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

//ɾ����������ֵ����mink��С��maxk��Ԫ��
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

//��һ��list������һ��list�ĺ���
void splice(mNode mList1, mNode mList2)
{
	//���ҵ�list1�����һ��
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

//�󽻼�
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

//�ҳ������м��Ԫ��
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
//	printf("�����м��Ԫ��Ϊ%d\n", p->data);
//	
//}


//������K��Ԫ��

/*
 *	��1�����������������ڵ�֮����K��Ȼ��ڵ�1��β��ʱ���ڵ�2�պ��ǵ�K��
	��2������һ�ְ취���ȱ���һ�������õ�����ĳ��ȣ��Ӷ��õ�������K���ڵ�
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

	printf("������%d��Ԫ��Ϊ%d", index,p2->data);
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

	printf("������%d��Ԫ��Ϊ%d", k, p->data);

}


int main()
{
	//��ʼ������
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


