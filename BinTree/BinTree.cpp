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

//初始化二叉树
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
//		puts("输入节点数据");
//		scanf_s("%c", &node->data);
//		node->left = NULL;
//		node->right = NULL;
//	}
//
//
//
//}

//获取左右子树
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

//获取二叉树状态
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

//层次遍历二叉树
//相当于广度优先搜索，使用队列实现。队列初始化，将根节点压入队列。
//当队列不为空，进行如下操作：弹出一个节点，访问，若左子节点或右子节点不为空，将其压入队列。
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



//打印单层节点
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


//层次遍历
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

//二叉树的节点个数
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


//二叉树叶子节点的个数
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

//K层节点的个数
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

//二叉树节点的最大距离 --本质上这两个节点的最大父节点
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

//判断是否为完全二叉树
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



/* 先序遍历(非递归)
思路：访问T->data后，将T入栈，遍历左子树；
遍历完左子树返回时，栈顶元素应为T，出栈，再先序遍历T的右子树。
*/

void PreOrder2(ChainBinTree* T){
	stack<ChainBinTree*> stack;
	//p是遍历指针
	ChainBinTree *p = T;
	//栈不空或者p不空时循环
	while (p || !stack.empty())
	{
		if (p != NULL)
		{
			//存入栈中
			stack.push(p);
			//访问根节点
			printf("%d ", p->data);
			//遍历左子树
			p = p->left;
		}
		else
		{
			//退栈
			p = stack.top();
			stack.pop();
			//访问右子树
			p = p->right;
		}
	}//while
}

//非递归后序遍历
void postOrder3(ChainBinTree *root)    
{
	stack<ChainBinTree*> s;
	ChainBinTree *cur;							//当前结点 
	ChainBinTree *pre = NULL;					//前一次访问的结点 
	s.push(root);
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->left == NULL&&cur->right == NULL) ||
			(pre != NULL && (pre == cur->left || pre == cur->right)))
		{
			cout << cur->data << " ";	//如果当前结点没有孩子结点
										//或者孩子节点都已被访问过 
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

//公共父节点
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