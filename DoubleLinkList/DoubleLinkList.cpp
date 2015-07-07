// DoubleLinkList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

struct node
{
	node* previous;
	node* next;
	int element;
	node()
	{
		previous = next = NULL;
		element = 0;
	}
	node(int element)
	{
		previous = next = NULL;
		this->element = element;
	}
};
typedef node* node_pointer;
//pick the list recommended out
void func(int n, int m, int s)
{
	//there is only one element in the list
	if (n == 1)
	{
		printf("1\n");
	}
	//there is only two element in the list
	else if (n == 2)
	{
		if (m & 1)
		{
			printf("%d %d\n", s, 3 - s);
		}
		else
		{
			printf("%d %d\n", 3 - s, s);
		}
	}
	else
	{
		//size:the size of the list
		//cnt:the counter to find the start pointer
		int size = n, cnt = 1;
		node_pointer head = new node(1);//the first node pointer built
		node_pointer current = head, start_pointer; //start_pointer:the start pointer
		if (s == 1)
		{
			start_pointer = current;
		}
		for (int i = 2; i <= size; i++)
		{
			node_pointer tmp = new node(i);
			current->next = tmp;
			tmp->previous = current;
			current = tmp;
			if (++cnt == s)
			{
				start_pointer = current;
			}
		}
		current->next = head;
		head->previous = current;

		current = start_pointer;
		cnt = 1;
		//the loop to pick the list out
		while (true)
		{
			if (cnt == m)
			{
				if (size >= 3)
				{
					printf("%d ", current->element);
					node_pointer tmp1 = current->previous;
					node_pointer tmp2 = current->next;
					tmp1->next = tmp2;
					tmp2->previous = tmp1;

					delete current;
					current = tmp2;
					cnt = 1;

					size--;
				}
				else if (size == 2)
				{
					printf("%d ", current->element);
					node_pointer tmp = current->next;
					tmp->previous = tmp->next = tmp;

					delete current;
					current = tmp;
					cnt = 1;

					size--;
				}
				else if (size == 1)
				{
					printf("%d\n", current->element);
					delete current;
					break; //over
				}
			}
			else
			{
				current = current->next;
				cnt++;
			}
		}
	}
}
int main()
{
	int n, m, s;//n:the total number , m:every m is picked , s:the start
	while (scanf("%d%d%d", &n, &m, &s) == 3)
	{
		func(n, m, s);
	}
	return 0;
}

