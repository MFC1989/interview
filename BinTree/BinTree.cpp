// BinTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <queue>
#include <stack>

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define QUEUE_MAXSIZE 50
typedef int DATA;

typedef struct ChainTree
{
	DATA data;
	struct ChainTree *left;
	struct ChainTree * right;
} ChainBinTree;

//��ʼ��������
ChainBinTree *BinTreeInit(ChainBinTree *node)
{
	if (node!=NULL)
	{
		return node;
	}
	else
	{
		return NULL;
	}
}


int BinTreeAddNode(ChainBinTree *bt,int n)
{
	ChainBinTree *p=bt;
	ChainBinTree * node=new ChainBinTree();
	node->left = NULL;
	node->right = NULL;
	scanf_s("%d", &(node->data));
	if (bt == NULL)
	{
		puts("root node was not exist");
		return 0;
	}
	switch (n)
	{
	case 1:
		while (p->left)
		{
			p = p->left;
		}
		p->left = node;
		break;
	case 2:
		while (p->right)
		{
			p = p->right;
		}
		p->right = node;
		break;

	
	default:
		puts("para error !");
		break;
	}
	return 1;

}


//void AddNode(ChainBinTree *node)
//{
//	ChainBinTree * node, *parent;
//	DATA data;
//	char select;s
//	if (node = (ChainBinTree *)malloc(sizeof(ChainBinTree))); 
//	{
//		puts("����ڵ�����");
//		scanf_s("%c", &node->data);
//		node->left = NULL;
//		node->right = NULL;
//	}
//
//
//
//}

//��ȡ��������
ChainBinTree * BinTreeLeft(ChainBinTree *bt)
{
	if (bt)
	{
		return bt->left;
	}
	else
	{
		return NULL;
	}
}

ChainBinTree * BinTreeRight(ChainBinTree *bt)
{
	if (bt)
	{
		return bt->right;
	} 
	else
	{
		return NULL;
	}
}

//��ȡ������״̬
bool BinTreeIsEmpty(ChainBinTree * bt)
{
	if (bt)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

int getDepth(ChainBinTree * bt)
{
	int dep1, dep2;
	if (bt==NULL)
	{
		return 0;
	}
	else
	{
		dep1 = getDepth(bt->left);
		dep2 = getDepth(bt->right);

		if (dep1>dep2)
		{
			return dep1 + 1;
		} 
		else
		{
			return dep2 + 1;
		}
	}


}

void BinTreeClear(ChainBinTree * bt)
{
	if (bt)
	{
		BinTreeClear(bt->left);
		BinTreeClear(bt->right);
		free(bt);
		bt = NULL;
	}
	
}

void PreTravel(const ChainBinTree *bt)
{

	if (bt)
	{
		printf("%d\n", bt->data);
		PreTravel(bt->left);
		PreTravel(bt->right);
	}

}

void leftTravel(const ChainBinTree *bt)
{
	if (bt)
	{
		PreTravel(bt->left);
		printf("%c\n", bt->data);
		PreTravel(bt->right);
	}
}

void rightTravel(const ChainBinTree *bt)
{
	if (bt)
	{
		PreTravel(bt->left);
		PreTravel(bt->right);
		printf("%c\n", bt->data);
	}
}

//��α���������
//�൱�ڹ������������ʹ�ö���ʵ�֡����г�ʼ���������ڵ�ѹ����С�
//�����в�Ϊ�գ��������²���������һ���ڵ㣬���ʣ������ӽڵ�����ӽڵ㲻Ϊ�գ�����ѹ����С�
void levelTravel(ChainBinTree *bt)
{
	std::queue < ChainBinTree *> mQueue;
	mQueue.push(bt);
	while (!mQueue.empty())
	{
		ChainBinTree * curNode = mQueue.front();
		printf("%d\n", curNode->data);
		mQueue.pop();
		if (curNode->left!=NULL)
		{
			mQueue.push(curNode->left);
		}

		if (curNode->right != NULL)
		{
			mQueue.push(curNode->right);
		}

	}

}



//��ӡ����ڵ�
int printSingleLevelNodes(ChainBinTree * bt,int level)
{
	if (!bt||level<0)
	{
		return 0;
	}

	if (level==0)
	{
		printf("%d\t", bt->data);
		return 1;
	}

	return printSingleLevelNodes(bt->left, level - 1) + printSingleLevelNodes(bt->right, level - 1);
	
}


//��α���
void printAllLevelNodes(ChainBinTree * bt)
{
	int depth = getDepth(bt);
	for (int i = 0; i < depth;i++)
	{
		printSingleLevelNodes(bt, i);
		printf("\n");
	}
}


ChainBinTree *InitRoot()
{
	ChainBinTree * node;
	if (node=(ChainBinTree *)malloc(sizeof(ChainBinTree)))
	{
		node->data = 100;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	else
	{
		return NULL;
	}
}

//�������Ľڵ����
int getNumberOfNode(ChainBinTree * mTree)
{
	if (mTree==NULL)
	{
		return 0;
	}
	else
	{
		return 1+getNumberOfNode(mTree->left)+getNumberOfNode(mTree->right);
	}

}


//������Ҷ�ӽڵ�ĸ���
int getLeaveNodesNums(ChainBinTree *bt)
{
	if (bt==NULL)
	{
		return 0;	
	}
	else 
	{
		if (bt->left == NULL&&bt->right == NULL)
		{
			return 1;
		}
		else
		{
			return getLeaveNodesNums(bt->left) + getLeaveNodesNums(bt->right);
		}
	}

}

//K��ڵ�ĸ���
int getKLevelNodeNums(ChainBinTree *bt,int k)
{
	
	if (k==0)
	{
		if (bt!=NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (k>0)
	{
		if (bt!=NULL)
		{
			return getKLevelNodeNums(bt->left, k - 1) + getKLevelNodeNums(bt->right, k - 1);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	
}

//�������ڵ�������� --�������������ڵ����󸸽ڵ�
int getBTreeMaxDistance(ChainBinTree * mTree)
{
	static int maxLen = 0;
	int tmp;
	if (mTree)
	{
		int leftDepth = getDepth(mTree->left);
		int rightDepth = getDepth(mTree->right);
		tmp = leftDepth + rightDepth;
		if (tmp>maxLen)
		{
			maxLen = tmp;
		}
	}
	
	if (mTree->left)
	{
		getBTreeMaxDistance(mTree->left);
	}

	if (mTree->right)
	{
		getBTreeMaxDistance(mTree->right);
	}

	return maxLen;
}

//�ж��Ƿ�Ϊ��ȫ������
bool isCompleteBTree(ChainBinTree * bt)
{
	std::queue<ChainBinTree *>mQueue;
	mQueue.push(bt);

	ChainBinTree * curNode = NULL;
	bool flag = false;
	while (!mQueue.empty())
	{
		curNode = mQueue.front();
		mQueue.pop();
		if (curNode)
		{
			if (flag)
			{
				return false;
			}
			mQueue.push(curNode->left);
			mQueue.push(curNode->right);
		}
		else
		{
			flag = true;
		}

		if (flag)
		{
			return false;
		}

	}



	return true;
}



/* �������(�ǵݹ�)
˼·������T->data�󣬽�T��ջ��������������
����������������ʱ��ջ��Ԫ��ӦΪT����ջ�����������T����������
*/

void PreOrder2(ChainBinTree* T){
	stack<ChainBinTree*> stack;
	//p�Ǳ���ָ��
	ChainBinTree *p = T;
	//ջ���ջ���p����ʱѭ��
	while (p || !stack.empty())
	{
		if (p != NULL)
		{
			//����ջ��
			stack.push(p);
			//���ʸ��ڵ�
			printf("%d ", p->data);
			//����������
			p = p->left;
		}
		else
		{
			//��ջ
			p = stack.top();
			stack.pop();
			//����������
			p = p->right;
		}
	}//while
}

//�ǵݹ�������
void postOrder3(ChainBinTree *root)    
{
	stack<ChainBinTree*> s;
	ChainBinTree *cur;							//��ǰ��� 
	ChainBinTree *pre = NULL;					//ǰһ�η��ʵĽ�� 
	s.push(root);
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->left == NULL&&cur->right == NULL) ||
			(pre != NULL && (pre == cur->left || pre == cur->right)))
		{
			cout << cur->data << " ";	//�����ǰ���û�к��ӽ��
										//���ߺ��ӽڵ㶼�ѱ����ʹ� 
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->right != NULL)
				s.push(cur->right);
			if (cur->left != NULL)
				s.push(cur->left);
		}
	}
}

//�������ڵ�
ChainBinTree * lCA(ChainBinTree *root,ChainBinTree * p,ChainBinTree * q)
{
	if (root==NULL)
	{
		printf("not found!");
	}
	if (root==p||root==q)
	{
		return root;
	}

	ChainBinTree * l = lCA(root->left, p, q);
	ChainBinTree * r = lCA(root->right, p, q);

	if (l!=NULL&&r!=NULL)
	{
		return root;
	}
	else
	{
		if (l!=NULL)
		{
			return l;
		}
		else
		{
			return r;
		}
	}
	 
}


int _tmain(int argc, _TCHAR* argv[])
{
	ChainBinTree * root = InitRoot();

	BinTreeAddNode(root, 1);
	BinTreeAddNode(root, 2);
	BinTreeAddNode(root->left, 1);
	BinTreeAddNode(root->left, 2);

	BinTreeAddNode(root->right, 1);
	BinTreeAddNode(root->right, 2);



	int len = getDepth(root);
	len--;
	//PreTravel(root);

	int nodeNums = getNumberOfNode(root);
	levelTravel(root);

	//printAllLevelNodes(root);
	int leavesNodeNum = getLeaveNodesNums(root);
	int kLeaves = getKLevelNodeNums(root, -1);
	bool isCmpTree = isCompleteBTree(root);
	
	ChainBinTree * node= lCA(root, root->left, root->right);

	return 0;
}