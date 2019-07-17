#define _CRT_SECURE_NO_WARNINGS 1 
#include "List.h"

ListNode* BuyNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_next = NULL;
	newnode->_data = x;
	newnode->_prev = NULL;
	return newnode;
}
void ListInit(List* plist)
{
	//assert(plist->_head);
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void ListDestory(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	if (head == NULL)
	{
		return;
	}
	ListNode* cur = head->_next;
	while (cur != head)
	{
		ListNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	free(head);
}

void ListPushBack(List* plist, LTDataType x)//尾插
{
	assert(plist);
	/*ListNode * head = plist->_head;
	ListNode*  newnode = BuyNode(x);
	head->_prev->_next = newnode;
	newnode->_prev = head->_prev;
	newnode->_next = head;
	head->_prev = newnode;*/
	ListInsert(plist->_head->_prev->_next, x);

}
void ListPopBack(List* plist) //尾删
{
	assert(plist->_head);
	/*ListNode* head = plist->_head;
	head->_prev->_prev->_next = head; 
	head->_prev = head->_prev->_prev;
	*/
	ListErase(plist->_head->_prev->_prev->_next);
}
void ListPushFront(List* plist, LTDataType x) // 前插
{
	assert(plist);
	/*ListNode* newnode = BuyNode(x);
	ListNode* head = plist->_head;
	newnode->_next = head->_next;
	head->_next = newnode;
	newnode->_prev = head;
	head->_next->_prev = newnode;*/
	ListInsert(plist->_head->_prev, x);

}
void ListPopFront(List* plist)    //前删
{
	assert(plist->_head);
	//ListNode* head = plist->_head;
	//ListNode* first = plist->_head->_next;
	//first->_next->_prev = head;
	//head->_next = first->_next;
	//free(first);
	//first = NULL;
	
	ListErase(plist->_head->_next);
}

ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist->_head && plist->_head->_next);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyNode(x);
	pos->_prev->_next = newnode;
	newnode->_prev = pos->_prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

void ListErase(ListNode * pos)
{
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
	pos = NULL;



}

void ListPrint(List*plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	printf("head<=>");
	while (cur != head)
	{
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("head\n");
}