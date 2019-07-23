#define _CRT_SECURE_NO_WARNINGS 1 
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

void CheckCapacity(SeqList* ps)
{
	assert(ps);
	
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity;
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
void SeqListPopBack(SeqList* ps)//尾删
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(SeqList* ps, SLDataType x)//前插
{
	assert(ps);
	CheckCapacity(ps);
	//这种写法 不闪退
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	//这种写法 闪退
	//size_t end = ps->size;      // 2 3 4 5
	//while (end > 0)            //  0 1 2 3 
	//{
	//	ps->array[end] = ps->array[end - 1];
	//	end--;
	//}
	
	//漏写一个条件
	ps->array[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)//前删
{
	assert(ps);
	size_t start = 0;
	while (start < ps->size - 1) //注意这里要-1，10个数，移动9个数，9次
	{
		ps->array[start] = ps->array[start + 1];
		//少写了
		start++;
	}
	ps->size--;
	
}

int SeqListFind(SeqList* ps, SLDataType x)//查找元素 ，返回下标
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
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)//插入坐标
{
	assert(ps);
	CheckCapacity(&ps);
	size_t end = ps->size;                  // 1 2 2 4 5
	size_t count = ps->size - pos;
	while ( count-- )                       // 0 1 2 3 4  end = 5  pos = 1
	{
		ps->array[end] = ps->array[end - 1];
		end--;
	}
	ps->array[pos] = x;
	ps->size++;


}
void SeqListErase(SeqList* ps, size_t pos)//释放某一点的
{
	assert(ps);
	size_t start = pos;
	size_t count = ps->size - pos - 1;
	while (count--)
	{
		ps->array[start] = ps->array[start + 1];
	}
}
void SeqListRemove(SeqList* ps, SLDataType x)//移动第一个为x的元素
{
	assert(ps);
	size_t i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == x)
		{
			size_t start = i;
			while (start < ps->size - 1)
			{
				ps->array[start] = ps->array[start + 1];
				start++;
			}
			/*for (int j = i; j <  ps->size; j++)
			{
				ps->array[j] = ps->array[j + 1];
			}*/
		}
	}
	ps->size--;
}
void SeqListModify(SeqList* ps, size_t pos, SLDataType x);
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
}

 扩展面试题实现 
void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		for (size_t j = 0; j < ps->size - 1 - i; j++)
		{
			if (ps->array[j] < ps->array[j + 1])
			{
				SLDataType temp = ps->array[j];
				ps->array[j] = ps->array[j + 1];
				ps->array[j + 1] = temp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	size_t start = 0;
	size_t end = ps->size - 1;
	size_t mid = (start + end) / 2;
	while (start <= end)
	{
		if (ps->array[mid] < x)
		{
			start = mid + 1;
		}
		if (ps->array[mid] > x)
		{
			end = mid - 1;
		}
		if (ps->array[mid] == x)
		{
			return mid;
		}
	}
	return -1;
}
 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x)//移除顺序表中所有为x的元素
{
	思路：统计不等于X的数值，把它放在第k的位置上，最后size--就可以了
	assert(ps);
	size_t k = 0;
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		if (ps->array[i] != x)
		{
			ps->array[k] = ps->array[i];
			k++;
		}
		ps->size -= k;
	}
}
