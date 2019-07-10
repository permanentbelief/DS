#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
}
void SListInit(SList* plt)//��ʼ������--
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
void SListPushBack(SList* plt, SLTDataType x)//β��
{
	assert(plt);
	SListNode* newnode = BuySListNode(x);
	
	SListNode* cur = plt->_head;
	//0���ڵ�(����Ϊ��)
	if (cur == NULL)
	{
		plt->_head = newnode;
	}
	
	//����ڵ� ��Ҫ��β !!! ����Ҳ����
	else
	{
		while (cur->_next != NULL) //���ﻻ��cur����Ҳ���ԣ�Ȼ��cur = newnode
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}
void SListPopBack(SList* plt)//��ɾ
{
	assert(plt);
	SListNode* cur = plt->_head;
	//0���ڵ㣨����Ϊ�գ�
	//1���ڵ�
	//����ڵ�
	if (cur == NULL)
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		free(plt->_head);// ������ͷſռ��� cur��plt->_head ������
		plt->_head = NULL; //ע������Ҫ�� plt->head
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
void SListPushFront(SList* plt, SLTDataType x)//ǰ��
{
	assert(plt);
	SListNode* newnode = BuySListNode(x);
	SListNode* cur = plt->_head;
	//����Ϊ��
	if (cur == NULL)
	{
		plt->_head = newnode;
	}
	//����Ϊ�� 
	else
	{
		newnode->_next = cur;
		plt->_head = newnode;
	}
}
void SListPopFront(SList* plt)//ǰɾ
{
	assert(plt);
	SListNode* cur = plt->_head;
	//����Ϊ��
	//����Ϊ��
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
SListNode* SListFind(SList* plt, SLTDataType x)//���ҽڵ� �����ؽڵ�
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

void SListInsert(SListNode* pos, SLTDataType x)////��pos�������
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

//���ߵ�һ��Ϊx�Ľڵ�
//����һ��
void SListRemove(SList* plt, SLTDataType x)
{
	assert(plt);
	SListNode *cur = plt->_head;
	SListNode *prev = NULL;
	//1 Ϊ������
	//2 ��Ϊ������
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
					prev->_next = cur->_next;//�˴���Ҫ�ж�prev�Ƿ�ΪNULL
					free(cur);
				}
				else //˵��prev����NULL,���������е�һ�������൱��ͷɾ
				{
					SListNode* tmp = cur;
					plt->_head= cur->_next;//�˴�Ӧ����plt->head,��Ӧ����cur
					free(tmp);
				}
				
				return;
			}
			prev = cur;
			cur = cur->_next;
			
		}
		
	}
}
//������ 
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
			//ɾ��
			if (cur == plt->_head)//ɾ����һ��Ԫ��
			{
				//del = cur;
				plt->_head = cur->_next;
				free(cur);
			}
			else//ɾ���ǵ�һ��Ԫ��
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

//��������������Ϊx�Ľڵ�    ������!!!!!!!!!!!
void SListRemoveAll(SList* plt, SLTDataType x) //ȥ��ѭ���е�return
{
	assert(plt);
	assert(plt);
	SListNode *cur = plt->_head;
	SListNode *prev = NULL;
	//SListNode* tmp = cur;
	//1 Ϊ������
	//2 ��Ϊ������
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
					prev->_next = cur->_next;//�˴���Ҫ�ж�prev�Ƿ�ΪNULL
					free(cur);
					cur = tmp->_next;
			}
				//else //˵��prev����NULL,���������е�һ�������൱��ͷɾ
				//{
				//	//SListNode* tmp = cur;
				//	plt->_head = cur->_next;//�˴�Ӧ����plt->head,��Ӧ����cur
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


//�ͷ�pos�ڵ����Ǹ��ڵ�
void SListEraseAfter(SListNode *pos)
{
	assert(pos);
	//pos->_next Ϊ��
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
void SListDeleteAll(SList * plt, SLTDataType val)// ɾ��������val�����нڵ� �Լ�д�ģ�������
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
			if (prev == NULL)//ͷ�ڵ���val
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
//������
//void SListDeleteAll(SList * plt, SLTDataType val)// ɾ��������val�����нڵ�
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
//	// 1.��
//	// 2.�ǿ�
//	if (plt->_head == NULL)
//	{
//		plt->_head = newnode;
//	}
//	else
//	{
//		SListNode* cur = plt->_head;
//		// ��β
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
//// 1.�Ȼ�ͼ�������ǳ������
//// 2.�ٻ�ͼ�������Ƿǳ������(�߽�����)
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