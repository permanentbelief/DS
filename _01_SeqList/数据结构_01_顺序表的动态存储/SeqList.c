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
void SeqListPushBack(SeqList* ps, SLDataType x)//β��
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SeqList* ps)//βɾ
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(SeqList* ps, SLDataType x)//ǰ��
{
	assert(ps);
	CheckCapacity(ps);
	//����д�� ������
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	//����д�� ����
	//size_t end = ps->size;      // 2 3 4 5
	//while (end > 0)            //  0 1 2 3 
	//{
	//	ps->array[end] = ps->array[end - 1];
	//	end--;
	//}
	
	//©дһ������
	ps->array[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)//ǰɾ
{
	assert(ps);
	size_t start = 0;
	while (start < ps->size - 1) //ע������Ҫ-1��10�������ƶ�9������9��
	{
		ps->array[start] = ps->array[start + 1];
		//��д��
		start++;
	}
	ps->size--;
	
}

int SeqListFind(SeqList* ps, SLDataType x)//����Ԫ�� �������±�
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
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)//��������
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
void SeqListErase(SeqList* ps, size_t pos)//�ͷ�ĳһ���
{
	assert(ps);
	size_t start = pos;
	size_t count = ps->size - pos - 1;
	while (count--)
	{
		ps->array[start] = ps->array[start + 1];
	}
}
void SeqListRemove(SeqList* ps, SLDataType x)//�ƶ���һ��Ϊx��Ԫ��
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

 ��չ������ʵ�� 
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
 ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* ps, SLDataType x)//�Ƴ�˳���������Ϊx��Ԫ��
{
	˼·��ͳ�Ʋ�����X����ֵ���������ڵ�k��λ���ϣ����size--�Ϳ�����
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
