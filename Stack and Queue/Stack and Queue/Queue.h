
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>
typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode *_next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _tail;
}Queue;
void QueueInit(Queue* pq) // 初始化队列
{
	assert(pq);
	pq->_front = pq->_tail = NULL;
}
void QueueDestory(Queue* pq)
{
	QueueNode* cur = pq->_front;
	while (cur != NULL)
	{
		QueueNode* tmp = cur;
		cur = cur->_next;
		free(tmp);
		/*QueueNode* next = cur->_next;
		free(cur);
		cur = next;*/
	}
	
	pq->_front = pq->_tail = NULL;
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;

	return node;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_front == NULL)
	{
		pq->_front = pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq && pq->_front);
	
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next; 
	if (pq->_front == NULL)
	{
		pq->_tail = NULL;
	}
	
	
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq&&pq->_front);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_tail);
	return pq->_tail->_data;
}
bool QueueEmpty(Queue* pq)
{
	return  (pq->_front == NULL && pq->_tail == NULL);
}
int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	size_t count = 0;
	while (cur)
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
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}