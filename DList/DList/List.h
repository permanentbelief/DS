#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;
ListNode* BuyNode(LTDataType x);                 // 创建新的节点
void ListInit(List* plist);                      // 双链表的初始化
void ListDestory(List* plist);

void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);

ListNode* ListFind(List* plist, LTDataType x);
// 在pos的前面进行插入

void ListInsert(ListNode* pos, LTDataType x);

void ListErase(ListNode * pos);

void ListPrint(List*plist);