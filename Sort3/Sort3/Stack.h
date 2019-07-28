#pragma once 
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType *_a;
	int _top;
	int _capacity;
}Stack;
void StackInit(Stack* ps)
{
	// 1 初始化为kong      ps->array = NULL;
	assert(ps);
	ps->_a = NULL;
	//ps->_a = (STDataType*)malloc(sizeof(STDataType));
	ps->_top = ps->_capacity = 0;
}
void StackDestory(Stack* ps)
{
	if (ps->_a != NULL)
	{
		free(ps->_a);
		ps->_a = NULL;
	}
	ps->_top = ps->_capacity = 0;
}
void StackPush(Stack* ps, STDataType x) // 相当于顺序表
{
	assert(ps);


	//ps->_capacity = ps->_capacity == 0  ?  2 : ps->_capacity * 2;
	//ps->_a = (STDataType *)realloc(ps->_a, sizeof(STDataType)*ps->_capacity);
	////ps->_capacity = newcapacity;
	//ps->_a[ps->_top] = x;
	//ps->_top++;
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)* newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;

}
void StackPop(Stack *ps)
{
	assert(ps && ps->_top > 0);   // 注意top是否为0
	ps->_top--;
}
STDataType StackTop(Stack* ps)    // 返回栈顶的数据
{
	assert(ps && ps->_top > 0);   //top的值必须为大于0
	return ps->_a[ps->_top - 1];
}
int StackSize(Stack* ps)           //返回数据个数
{
	assert(ps);
	return ps->_top;
}
bool StackEmpty(Stack * ps)
{
	assert(ps);
	return ps->_top == 0;
}
void TestStack()
{
	Stack mystack;
	StackInit(&mystack);
	/*
	StackPush(&mystack, 5);
	StackPush(&mystack, 6);
	StackPush(&mystack, 7);
	StackPush(&mystack, 7);
	StackPush(&mystack, 7);*/
	StackPush(&mystack, 7);
	StackPush(&mystack, 8);
	StackPush(&mystack, 9);
	StackPush(&mystack, 9);
	StackPush(&mystack, 9);

	int n = StackSize(&mystack);
	//printf("%d\n", n);
	// 这里要注意 有问题 StackPopback 会改变_top的值，会影响到StackSize的值
	// 应该将StackSize(&mystack)的值存起来
	for (int i = 0; i < n; i++)
	{
		printf("%d ", StackTop(&mystack));
		//int a = StackTop(&mystack);
		//printf("%d",a);
		StackPop(&mystack);
	}
	/*while (!StackEmpty(&mystack))
	{
	printf("%d ", StackTop(&mystack));
	StackPop(&mystack);
	}
	printf("\n");
	*/
	StackDestory(&mystack);
}