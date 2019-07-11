#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->array = NULL;
	ps->capacity = ps->size = 0;

}
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
	}
	ps->capacity = ps->size = 0;
}
void CheckCapacity(SeqList* ps)
{
	assert(ps);

	if (ps->array == ps->capacity)
	{

		size_t newcapacity = (ps->capacity == 0) ? 4: ps->capacity * 2;
		ps->array  = realloc(sizeof(SLDataType)*newcapacity);
		ps->capacity = newcapacity;
	}
}
void SeqListPushBack(SeqList* ps, SLDataType x)//尾插
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(SeqList* ps, SLDataType x)//前插
{
	assert(ps);
	size_t end = ps->size;
	while (end > 0)
	{
		ps->array[end] = ps->array[end - 1];
		end--;
	}
	ps->array[0] = x;
	ps->size--;
}
void SeqListPopFront(SeqList* ps)//前删
{
	assert(ps);
	size_t start = 0;
	while (start < ps->size )
	{
		ps->array[start] = ps->array[start + 1];
		start++;
	}
	ps->size--;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d->", ps->array[i]);
	}
	printf("\n");
}



size_t SeqListSize(SeqList* ps)//链表大小
{
	assert(ps);
	return ps->size;
}
SLDataType SeqListAt(SeqList* ps, size_t pos)//定位于链表中的某一元素
{
	assert(ps);
	return ps->array[pos];
}
int SeqListFind(SeqList* ps, SLDataType x)//查找
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	size_t end = ps->size;
	while (end >= pos + 1)
	{
		ps->array[end] = ps->array[end - 1];
		end--;
	}
	ps->array[pos] = x;
	ps->size++;
}
void SeqListErease(SeqList* ps, size_t pos)
{
	assert(ps);
	size_t start = pos;
	while (start < ps->size)
	{
		ps->array[start] = ps->array[start + 1];
		start++;
	}
	ps->size--;
}