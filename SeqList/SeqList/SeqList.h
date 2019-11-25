#pragma once
#include <stdio.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType * array;    // 指向动态开辟的数组
	size_t size;           // 有效数据的个数
	size_t capacity;       // 容量空间的大小
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);
void CheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps); 
void SeqListPushFront(SeqList* ps,SLDataType x);
void SeqListPopFront(SeqList* ps);

size_t SeqListSize(SeqList* ps);//链表大小

SLDataType SeqListAt(SeqList* ps, size_t pos);//定位于链表中的某一元素

int SeqListFind(SeqList* ps, SLDataType x);

void SeqListInert(SeqList * ps, size_t pos, SLDataType x);

void SeqListErase(SeqList* ps, size_t pos);

void SeqListRemove(SeqList* ps, SLDataType x);

void SeqListPrint(SeqList* ps);

void SeqListBubbleSort(SeqList* ps); 

int SeqListBinaryFind(SeqList* ps, SLDataType x);

//时间复杂度o(n),空间复杂度o(1)
void SeqListRemoveAll(SeqList* ps, SLDataType);