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

SListNode* BuySListNode(SLTDataType x);//�����½ڵ㣬��Ľӿڿ���ֱ�ӵ��ô˽ӿڣ�����
void SListInit(SList* plist);
void SListDestory(SList* plist);
void SListPushBack(SList* plist, SLTDataType x);//β��
void SListPopBack(SList* plist);//βɾ
void SListPushFront(SList* plist, SLTDataType x);//ͷ��
void SListPopFront(SList* plist);//ͷɾ
//����pos�ڵ�
SListNode* SListFind(SList* plist, SLTDataType x);
//��pos�������
void SListInsert(SListNode* pos, SLTDataType x);

void SListPrint(SList* plist);//��ӡ

//���ߵ�һ��Ϊx�Ľڵ�
void SListRemove(SList* plist, SLTDataType x);

//��������������Ϊx�Ľڵ�
void SListRemoveAll(SList* plist, SLTDataType x);

//�ͷ�pos�ڵ����Ǹ��ڵ�
void SListEraseAfter(SListNode *pos);

//ɾ������val�����нڵ�
void SListDeleteAll(SList * plist, SLTDataType val);

void SListRemove1(SList* plist, SLTDataType x);
