#include "SeqList.h"
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;

}
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	if (ps->array)
	{
		free(ps->array);
		ps->array = NULL;
	}
	ps->capacity = 0;
	ps->size = 0;
}

void CheckCapacity(SeqList* ps) //检查空间 容积是否足够
{
	assert(ps);
	
	
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->array = realloc(ps->array, sizeof(SLDataType)* newcapacity);
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
void SeqListPrint(SeqList*ps) 
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl && psl->size>0);
	psl->size--;

}
void SeqListPushFront(SeqList* ps, SLDataType x) //前插 插入数据首先要检查空间
{
	assert(ps);
	CheckCapacity(ps);
	int end = ps->size;
	while (end > 0)
	{
		ps->array[end] = ps->array[end - 1];
		end--;
	}
	ps->array[0] = x;
	ps->size++;

}
void SeqListPopFront(SeqList* ps)
{
	assert(ps && ps->size > 0);
	int  start = 0;
	while (start < ps->size)
	{
		ps->array[start] = ps->array[start + 1];
		start++;
	}
	ps->size--;
}
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == x)
		{
			return i;
		}
	}
	return NULL;
}
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	size_t  end = ps->size;
	while (end > pos)
	{
		ps->array[end] = ps->array[end - 1];
		end--;
	}
	ps->array[pos] = x;
	ps->size++;
}
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	size_t  end = pos;
	while (end < ps->size)
	{
		ps->array[end] = ps->array[end + 1];
		end++;
	}
	ps->size--;
}
void SeqListRemove(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == x)
		{
			int end = i;
			while (end < ps->size - 1)
			{
				ps->array[end] = ps->array[end + 1];
				end++;
			}
			ps->size--;
			return;
		}
	}
	
}
void SeqListModify(SeqList* ps, size_t pos, SLDataType x) // 修改
{
	assert(ps);
	assert(pos >=0 && pos < ps->size);
	ps->array[pos] = x;
}

//// 扩展面试题实现 
void SeqListBubbleSort(SeqList* ps)
{
	for (int i = 0; i < ps->size; i++)// 7 5 4 1 7
	{
		for (int j = 0; j < ps->size - i - 1; j++)
		{
			if (ps->array[j] < ps->array[j + 1])
			{
				SLDataType tmp = ps->array[j];
				ps->array[j] = ps->array[j + 1];
				ps->array[j + 1] = tmp;
			}
		}
		
	}
}
int SeqListBinaryFind(SeqList* ps, SLDataType x) //二分法查找
{
	if (ps->array[0] < x)     // 7 6 5 4 1
	{
		return;
	}
	if (ps->array[ps->size - 1] > x)
	{
		return;
	}
	int left = 0;
	int right = ps->size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (ps->array[mid] < x)
		{
			right = mid - 1;
		}
		if (ps->array[mid] >x)
		{
			left = mid + 1;
		}
		if (ps->array[mid] == x)
		{
			return mid;
		}
	}
	return -1;
}

// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x)
{
		assert(ps);
		size_t k = 0;
		for (size_t i = 0; i <=ps->size - 1; i++)    // 7 5 1 4 7
		{
			if (ps->array[i] != x)
			{
				ps->array[k] = ps->array[i];
				k++;
			}
			
		}
		ps->size = k;
	

}
