#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
}
void SListInit(SList* plt)//初始化链表--
{
	assert(plt);
	plt->_head = NULL;
}
void SListDestory(SList* plt)
{
	assert(plt);
	SListNode *cur = plt->_head;
	if (cur == NULL)
	{
		return;
	}
	while (cur != NULL)
	{
		SListNode* temp = cur;
		cur = cur->_next;
		free(temp);
	}


}
void SListPushBack(SList* plt, SLTDataType x)//尾插
{
	assert(plt);
	SListNode* newnode = BuySListNode(x);
	
	SListNode* cur = plt->_head;
	//0个节点(链表为空)
	if (cur == NULL)
	{
		plt->_head = newnode;
	}
	
	//多个节点 需要找尾 !!! 这块我不理解
	else
	{
		while (cur->_next != NULL) //这里换成cur不是也可以，然后cur = newnode
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}
void SListPopBack(SList* plt)//后删
{
	assert(plt);
	SListNode* cur = plt->_head;
	//0个节点（链表为空）
	//1个节点
	//多个节点
	if (cur == NULL)
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		free(plt->_head);// 这里的释放空间是 cur与plt->_head 都可以
		plt->_head = NULL; //注意这里要是 plt->head
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}

}
void SListPushFront(SList* plt, SLTDataType x)//前插
{
	assert(plt);
	SListNode* newnode = BuySListNode(x);
	SListNode* cur = plt->_head;
	//链表为空
	if (cur == NULL)
	{
		plt->_head = newnode;
	}
	//链表不为空 
	else
	{
		newnode->_next = cur;
		plt->_head = newnode;
	}
}
void SListPopFront(SList* plt)//前删
{
	assert(plt);
	SListNode* cur = plt->_head;
	//链表为空
	//链表不为空
	if (cur == NULL)
	{
		return;
	}
	else
	{
		plt->_head = cur->_next;
		free(cur);
	}
}
SListNode* SListFind(SList* plt, SLTDataType x)//查找节点 并返回节点
{
	assert(plt);
	if (plt->_head == NULL)
	{
		return NULL;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur)
		{
			if (cur->_data == x)
			{
				return cur;
			}
			cur = cur->_next;
		}
	}
	return NULL;
}

void SListInsert(SListNode* pos, SLTDataType x)////在pos后面插入
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	if (pos->_next == NULL)
	{
		pos->_next = newnode;
	}
	else
	{
		newnode->_next = pos->_next;
		pos->_next = newnode;
	}
}
void SListPrint(SList* plt)
{
	assert(plt);
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

//移走第一个为x的节点
//方法一。
void SListRemove(SList* plt, SLTDataType x)
{
	assert(plt);
	SListNode *cur = plt->_head;
	SListNode *prev = NULL;
	//1 为空链表
	//2 不为空链表
	if (cur == NULL)
	{
		return;
	}
	else
	{
		while (cur)
		{

			if (cur->_data == x)
			{
				if (prev != NULL)
				{
					prev->_next = cur->_next;//此处需要判断prev是否为NULL
					free(cur);
				}
				else //说明prev还是NULL,这是链表中第一个数，相当于头删
				{
					SListNode* tmp = cur;
					plt->_head= cur->_next;//此处应该是plt->head,不应该是cur
					free(tmp);
				}
				
				return;
			}
			prev = cur;
			cur = cur->_next;
			
		}
		
	}
}
//方法二 
void SListRemove1(SList* plt, SLTDataType x)
{
	assert(plt);
	SListNode *cur = plt->_head;
	SListNode *prev = NULL;
	while (cur)
	{
		SListNode * del = NULL;
		if (cur->_data == x)
		{
			//删除
			if (cur == plt->_head)//删除第一个元素
			{
				//del = cur;
				plt->_head = cur->_next;
				free(cur);
			}
			else//删除非第一个元素
			{
				prev->_next = cur->_next;
				free(cur);
			}
			return;
		}
		prev = cur;
		cur = cur->_next;
	}
}

//移走链表上所有为x的节点    有问题!!!!!!!!!!!
void SListRemoveAll(SList* plt, SLTDataType x) //去掉循环中的return
{
	assert(plt);
	assert(plt);
	SListNode *cur = plt->_head;
	SListNode *prev = NULL;
	//SListNode* tmp = cur;
	//1 为空链表
	//2 不为空链表
	if (cur == NULL)
	{
		return;
	}
	else
	{
		while (cur)
		{
			
			if (cur->_data == x)
			{
				
					SListNode * tmp = cur;
					prev->_next = cur->_next;//此处需要判断prev是否为NULL
					free(cur);
					cur = tmp->_next;
			}
				//else //说明prev还是NULL,这是链表中第一个数，相当于头删
				//{
				//	//SListNode* tmp = cur;
				//	plt->_head = cur->_next;//此处应该是plt->head,不应该是cur
				//	free(cur);
				//}
				//
			
			else
			{
				prev = cur;
				cur = cur->_next;
			}
			
		}

	}
}


//释放pos节点后的那个节点
void SListEraseAfter(SListNode *pos)
{
	assert(pos);
	//pos->_next 为空
	if (pos->_next == NULL)
	{
		//printf("kong");
		return;
	}
	else
	{
		SListNode *tmp = pos->_next;
		pos->_next = pos->_next->_next;
		free(tmp);
	}
}
void SListDeleteAll(SList * plt, SLTDataType val)// 删除给定的val的所有节点 自己写的！！！。
{
	assert(plt);
	SListNode* tmp = NULL;
	SListNode* cur = plt->_head;
	SListNode* prev = NULL;
	if (cur == NULL)
	{
		return;
	}
	while (cur)
	{
		if (cur->_data == val)
		{
			if (prev == NULL)//头节点是val
			{
				tmp = cur;
				plt->_head = cur->_next;
				free(tmp);
				cur = cur->_next;
			}
			else
			{
				tmp = cur;
				prev->_next = cur->_next;
				free(cur);
				cur = tmp->_next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}
//方法二
//void SListDeleteAll(SList * plt, SLTDataType val)// 删除给定的val的所有节点
//{
//
//}






































//void SListInit(SList* plt)
//{
//	assert(plt);
//
//	plt->_head = NULL;
//}
//
//void SListPushBack(SList* plt, SLTDataType x)
//{
//	assert(plt);
//
//	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
//	newnode->_data = x;
//	newnode->_next = NULL;
//
//	// 1.空
//	// 2.非空
//	if (plt->_head == NULL)
//	{
//		plt->_head = newnode;
//	}
//	else
//	{
//		SListNode* cur = plt->_head;
//		// 找尾
//		while (cur->_next != NULL)
//		{
//			cur = cur->_next;
//		}
//
//		cur->_next = newnode;
//	}
//}
//
//void SListPushFront(SList* plt, SLTDataType x)
//{
//	assert(plt);
//
//	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
//	newnode->_data = x;
//	newnode->_next = NULL;
//
//	newnode->_next = plt->_head;
//	plt->_head = newnode;
//}
//
//void SListPopBack(SList* plt)
//{
//	assert(plt);
//	SListNode* cur = plt->_head;
//	if (cur == NULL)
//	{
//		return;
//	}
//	else if (cur->_next == NULL)
//	{
//		free(cur);
//		plt->_head = NULL;
//	}
//	else
//	{
//		while (cur->_next->_next != NULL)
//		{
//			cur = cur->_next;
//		}
//
//		free(cur->_next);
//		cur->_next = NULL;
//	}
//}
//
//void SListPopFront(SList* plt)
//{
//	assert(plt);
//
//	if (plt->_head == NULL)
//	{
//		return;
//	}
//	else
//	{
//		SListNode* cur = plt->_head;
//		plt->_head = cur->_next;
//		free(cur);
//		cur = NULL;
//	}
//}
//
//SListNode* SlistFind(SList* plt, SLTDataType x)
//{
//	assert(plt);
//	SListNode* cur = plt->_head;
//	while (cur != NULL)
//	{
//		if (cur->_data == x)
//		{
//			return cur;
//		}
//
//		cur = cur->_next;
//	}
//
//	return NULL;
//}
//
//void SListInsertAfter(SListNode* pos, SLTDataType x)
//{
//	assert(pos);
//	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
//	newnode->_data = x;
//	newnode->_next = NULL;
//
//	newnode->_next = pos->_next;
//	pos->_next = newnode;
//}
//
//void SListEraseAfter(SListNode* pos)
//{
//	assert(pos);
//	if (pos->_next == NULL)
//	{
//		return;
//	}
//	else
//	{
//		SListNode* next = pos->_next;
//		pos->_next = next->_next;
//		free(next);
//		next = NULL;
//	}
//}
//
//void SListRemove(SList* plt, SLTDataType x)
//{
//	assert(plt);
//
//	SListNode* prev = NULL;
//	SListNode* cur = plt->_head;
//	while (cur != NULL)
//	{
//		if (cur->_data == x)
//		{
//			if (prev == NULL)
//				plt->_head = cur->_next;
//			else
//				prev->_next = cur->_next;
//
//			free(cur);
//			cur = NULL;
//			return;
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->_next;
//		}
//	}
//}
//
//
//// 1.先画图分析考虑常规情况
//// 2.再画图分析考虑非常规情况(边界条件)
//
//void SListPrint(SList* plt)
//{
//	assert(plt);
//
//	SListNode* cur = plt->_head;
//	while (cur != NULL)
//	{
//		printf("%d->", cur->_data);
//		cur = cur->_next;
//	}
//	printf("NULL\n");
//}
//
//void SListDestory(SList* plt);
//
//
//
//void TestSList1()
//{
//	SList lt;
//	SListInit(&lt);
//	SListPushBack(&lt, 1);
//	SListPushBack(&lt, 2);
//	SListPushBack(&lt, 3);
//	SListPushBack(&lt, 4);
//	SListPushFront(&lt, 0);
//	SListPrint(&lt);
//
//	SListPopBack(&lt);
//	SListPopBack(&lt);
//	SListPopBack(&lt);
//	SListPrint(&lt);
//
//	SListPopFront(&lt);
//	SListPopFront(&lt);
//	SListPrint(&lt);
//}
//
//void TestSList2()
//{
//	SList lt;
//	SListInit(&lt);
//	SListPushBack(&lt, 1);
//	SListPushBack(&lt, 2);
//	SListPushBack(&lt, 3);
//	SListPushBack(&lt, 2);
//	SListPushBack(&lt, 4);
//	SListPushBack(&lt, 2);
//	SListPrint(&lt);
//
//	SListNode* pos = SlistFind(&lt, 3);
//	SListInsertAfter(pos, 30);
//	SListPrint(&lt);
//
//	SListEraseAfter(pos);
//	SListPrint(&lt);
//
//	SListRemove(&lt, 2);
//	SListPrint(&lt);
//}