#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

SListNode* BuySListNode(SLTDataType x);//建立新节点，别的接口可以直接调用此接口，方便
void SListInit(SList* plist);
void SListDestory(SList* plist);
void SListPushBack(SList* plist, SLTDataType x);//尾插
void SListPopBack(SList* plist);//尾删
void SListPushFront(SList* plist, SLTDataType x);//头插
void SListPopFront(SList* plist);//头删
//返回pos节点
SListNode* SListFind(SList* plist, SLTDataType x);
//在pos后面插入
void SListInsert(SListNode* pos, SLTDataType x);

void SListPrint(SList* plist);//打印

//移走第一个为x的节点
void SListRemove(SList* plist, SLTDataType x);

//移走链表上所有为x的节点
void SListRemoveAll(SList* plist, SLTDataType x);

//释放pos节点后的那个节点
void SListEraseAfter(SListNode *pos);

//删除给定val的所有节点
void SListDeleteAll(SList * plist, SLTDataType val);

void SListRemove1(SList* plist, SLTDataType x);
