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
	QueueNode* _front;  // ��ͷ
	QueueNode* _rear;   //  ��β
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
	while (cur != NULL)            //Ϊʲô��ֹ����������rear! rear��Ϊ�յĵط���ֵ���Ǹ�λ��rear��Ϊ�գ�
								   // ������һ��λ�ò�Ϊ��
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

void QueuePush(Queue* ps, QUDataType x) //��� ��β����
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

void QueuePop(Queue* ps)  // ���� 
{
	assert(ps && ps->_front);
	QueueNode* next = ps->_front->_next; //�����е�ֵ
	free(ps->_front);
	ps->_front = next;
	if (ps->_front != NULL)// ����ɾ������,front��tailָ��β�ڵ㣬��һ�ͷŵĻ�,ps->_rear ��ΪҰָ����
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
	//  return QueueSize(ps) == 0; O(n)���㷨
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