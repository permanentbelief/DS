#pragma once 
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>

typedef int  QUDataType;


typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;  // 对头
	QueueNode* _rear;   //  队尾
}Queue;

void QueueInit(Queue * ps)
{
	assert(ps);
	ps->_front = ps->_rear = NULL;
	//ps->_front = NULL;

}
void QueueDestory(Queue* ps)
{
	//assert(ps && ps->_front);
	QueueNode* cur = ps->_front ;
	while (cur != NULL)            //为什么终止条件不等于rear! rear不为空的地方有值，那个位置rear不为空，
								   // 它的下一个位置才为空
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	ps->_front =ps->_rear =  NULL;
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue* ps, QUDataType x) //入队 队尾插入
{
	assert(ps);
	QueueNode* newnode = BuyQueueNode(x);
	//QueueNode* last = ps->_rear;
	if (ps->_rear == NULL)
	{
		ps->_front = ps->_rear = newnode;
	}
	else
	{
		ps->_rear->_next = newnode;
	}
	
	ps->_rear = newnode;
}

void QueuePop(Queue* ps)  // 出队 
{
	assert(ps && ps->_front);
	QueueNode* next = ps->_front->_next; //出队列的值
	free(ps->_front);
	ps->_front = next;
	if (ps->_front != NULL)// 链表删完的情况,front和tail指向尾节点，在一释放的话,ps->_rear 就为野指针了
	{
		ps->_rear = NULL;
	}

}
QUDataType QueueFront(Queue *ps)
{
	assert(ps && ps->_front);
	return ps->_front->_data;
}
QUDataType QueueBack(Queue *ps)
{
	assert(ps && ps->_rear);
	return ps->_rear->_data;
}
bool QueueEmpty(Queue* ps)
{
	assert(ps);
	//  return QueueSize(ps) == 0; O(n)的算法
	return ps->_front == NULL;
}
int QueueSize(Queue* ps)
{
	assert(ps);
	QueueNode* cur = ps->_front ;
	size_t count = 0;
	while (cur != NULL)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,6);
	QueuePush(&q,7);
	QueuePush(&q, 7);
	QueuePush(&q, 7);
	QueuePush(&q, 7);
	QueuePush(&q, 7);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestory(&q);

}