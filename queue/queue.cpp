// queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>


#define CIRCULAR_QUEUE_LEN 100


struct CircularQueue
{
	int * base;
	int front;
	int rear;
};


bool InitCircularQueue(CircularQueue &Q)
{
	Q.base = (int *)malloc(sizeof(int)*CIRCULAR_QUEUE_LEN);
	if (!Q.base)
	{
		return false;
	}
	Q.front = 0;
	Q.rear = 0;
	
	return true;
}
 

bool PushCircularQueue(CircularQueue &Q,int e)
{
	if ((Q.rear+1) % CIRCULAR_QUEUE_LEN == Q.front)
	{
		return false;		//队列满		
	}

	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % CIRCULAR_QUEUE_LEN;
	return true;
}

bool popCircularQueue(CircularQueue &Q,int &e)
{
	if (Q.front==Q.rear)
	{
		return false;		//队列空
	}

	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % CIRCULAR_QUEUE_LEN;
	return true;
}

int CircularQueueLen(CircularQueue &Q)
{
	return(Q.rear-Q.front+CIRCULAR_QUEUE_LEN)%CIRCULAR_QUEUE_LEN;
}


int main()
{
	return 0;
}

