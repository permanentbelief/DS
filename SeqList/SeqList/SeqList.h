#pragma once
#include <stdio.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType * array;    // ָ��̬���ٵ�����
	size_t size;           // ��Ч���ݵĸ���
	size_t capacity;       // �����ռ�Ĵ�С
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);
void CheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps); 
void SeqListPushFront(SeqList* ps,SLDataType x);
void SeqListPopFront(SeqList* ps);

size_t SeqListSize(SeqList* ps);//�����С

SLDataType SeqListAt(SeqList* ps, size_t pos);//��λ�������е�ĳһԪ��

int SeqListFind(SeqList* ps, SLDataType x);

void SeqListInert(SeqList * ps, size_t pos, SLDataType x);

void SeqListErase(SeqList* ps, size_t pos);

void SeqListRemove(SeqList* ps, SLDataType x);

void SeqListPrint(SeqList* ps);

void SeqListBubbleSort(SeqList* ps); 

int SeqListBinaryFind(SeqList* ps, SLDataType x);

//ʱ�临�Ӷ�o(n),�ռ临�Ӷ�o(1)
void SeqListRemoveAll(SeqList* ps, SLDataType);