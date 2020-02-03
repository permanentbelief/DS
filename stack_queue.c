//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <stdio.h>
//#include <cstdbool>
//#include <assert.h>
//
//
//// ջ�ʺ�������ʵ�֣����в��ʺ���β����ջ��ʱ����β�鷳����������ʵ�������������Ӽ򵥷��㡣
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* _array;
//	size_t _top;
//	size_t _capacity;
//}Stack;
//
//void StackInit(Stack* S)
//{
//	assert(S);  
//	S->_array = NULL;
//	S->_top = 0;
//	S->_capacity = 0;
//}
//void StackDestory(Stack* S)
//{
//	if (S->_array)
//	{
//		free(S->_array);
//		S->_array = NULL;
//	}
//	S->_top = 0;
//	S->_capacity = 0;
//}
//void CheckCapacity(Stack* S) // ���ռ��С�����������������Ҫ����
//{
//	assert(S);
//	if (S->_top == S->_capacity)
//	{
//		size_t new_capacity = S->_capacity == 0 ? 2 : 2 * S->_capacity;
//		S->_array = (STDataType*)realloc(S->_array,sizeof(STDataType)*new_capacity);
//		S->_capacity = new_capacity;
//	}
//}
//
//void StackPush(Stack* S, STDataType x)
//{
//	assert(S);
//	CheckCapacity(S); //���ջ�Ŀռ�
//	S->_array[S->_top] = x;
//	S->_top++;
//}
//
//void StackPop(Stack* S)
//{
//	assert(S && S->_top > 0);
//	S->_top--;
//}
//
//STDataType StackTop(Stack* S)
//{
//	assert(S && S->_top > 0);
//	return S->_array[S->_top-1];
//}
//
//bool StackEmpty(Stack* S)
//{
//	assert(S);
//	return (S->_top == 0);
//}
//
//size_t StackSize(Stack* S)
//{
//	assert(S);
//	return S->_top;
//}
//
//void StackPrint(Stack* S)
//{
//	for (int i = 0; i < StackSize(S); i++)
//	{
//		printf("%d ",S->_array[i]);
//
//	}
//	printf(" \n");
//}
//
//void Stacktest()
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, 2);
//	StackPush(&s, 5);
//	StackPush(&s, 10);
//	StackPush(&s, 20);
//	StackPrint(&s);
//	printf("\n��ջ�����ݳ�ջ��:\n");
//	StackPop(&s);
//	StackPrint(&s);
//	printf("\nջ������:%d \n", StackTop(&s));
//
//
//}
//int main()
//{
//	Stacktest();
//	system("pause");
//}

#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <cstdbool>
#include <assert.h>
#include <malloc.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
   
typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* pq)      // ��ʼ������
{
	assert(pq);
	pq->_front = pq->_tail = NULL;
}
void QueueDestory(Queue* pq)    //���ٶ���
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_tail = NULL;
}
QueueNode* BuyQueueNode(QUDataType x)  //�����½ڵ�
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QUDataType x)   //���
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_tail == NULL)
	{
		pq->_front = pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}
void QueuePop(Queue* pq)             // ����
{
	assert(pq && pq->_front != NULL);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;

	//��Ҫע����ǣ����pq->_frontΪ�յĻ���˵��
	//�ϸ��ڵ��ͷŵ���pq->_tail. pq->_tail��Ұָ��
	//���Խ�Ұָ���ÿ�
	if (pq->_front == NULL)
	{
		pq->_tail = NULL;
	}
}
QUDataType QueueFront(Queue* pq)        //���ض�ͷ����
{
	assert(pq);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)        // ���ض�β����
{
	assert(pq);
	return pq->_tail->_data;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL;
}
size_t QueueSize(Queue* pq)             // ������Ԫ�ظ���
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

void Test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 3);
	QueuePush(&q, 5);
	QueuePush(&q, 7);
	QueuePush(&q, 9);
	int c = QueueSize(&q);

	while (!QueueEmpty(&q))
	{
		printf("%d ",QueueFront(&q));
		QueuePop(&q);
	}
}
int  main()
{
	Test();
	system("pause");
} 