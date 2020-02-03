//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <stdio.h>
//#include <cstdbool>
//#include <assert.h>
//
//
//// 栈适合用数组实现，队列不适合找尾，出栈的时候，找尾麻烦。所以数组实现相较于链表更加简单方便。
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
//void CheckCapacity(Stack* S) // 检查空间大小，如果容量不够，需要增容
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
//	CheckCapacity(S); //检查栈的空间
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
//	printf("\n将栈顶数据出栈后:\n");
//	StackPop(&s);
//	StackPrint(&s);
//	printf("\n栈顶数据:%d \n", StackTop(&s));
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

void QueueInit(Queue* pq)      // 初始化队列
{
	assert(pq);
	pq->_front = pq->_tail = NULL;
}
void QueueDestory(Queue* pq)    //销毁队列
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
QueueNode* BuyQueueNode(QUDataType x)  //创建新节点
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QUDataType x)   //入队
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
void QueuePop(Queue* pq)             // 出队
{
	assert(pq && pq->_front != NULL);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;

	//需要注意的是，如果pq->_front为空的话，说明
	//上个节点释放的是pq->_tail. pq->_tail是野指针
	//所以将野指针置空
	if (pq->_front == NULL)
	{
		pq->_tail = NULL;
	}
}
QUDataType QueueFront(Queue* pq)        //返回队头数据
{
	assert(pq);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)        // 返回队尾数据
{
	assert(pq);
	return pq->_tail->_data;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL;
}
size_t QueueSize(Queue* pq)             // 队列中元素个数
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