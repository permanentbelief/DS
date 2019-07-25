#define _CRT_SECURE_NO_WARNINGS 1 

#include "Heap.h"

void Swap(HPDataType*num1, HPDataType* num2)  //��������
{
	HPDataType  tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;

}
void HeapInit(Heap* hp, HPDataType *a, int n)
{
	hp->_a = malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}
//void HeapInit(Heap* hp, HPDataType *a, int n) // �ѵĳ�ʼ�� ����
//{
//	  
//		hp->_a = malloc(sizeof(HPDataType)*n);
//		memcpy(hp->_a, a, sizeof(HPDataType)*n);
//		hp->_size = n;
//		hp->_capacity = n;
//	//������
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--) //�������µ����� �����ѡ�
//	{
//			AdjustDown(hp->_a, hp->_size, i);
//	}
//}

void AdjustDown(HPDataType* a, size_t n, size_t parent) //��С��
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// ѡ��С���Ǹ���ֽ
		if (child + 1 < n && a[child + 1] < a[child])
			++child;

		// ��ֽС�ڸ��ף��򽻻�
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapDestory(Heap* hp)	//���ٶ�
{
	if (hp->_a != NULL)
	{
		free(hp->_a);
		hp->_a = NULL;
	}
	hp->_size = hp->_capacity = 0;
}
//void HeapPush(Heap*hp, HPDataType x)   ע��malloc��ʹʧ�� ��Ϊmemcpy�� ����Ŀռ��ֵ����hp->_a
//{
//	if (hp->_size == hp->_capacity)
//	{
//		size_t newcapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
//		hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*newcapacity);
//		hp->_capacity = newcapacity;
//	}
//	hp->_a[hp->_size] = x;
//	hp->_size++;
//	Ajustup(hp->_a, hp->_size - 1);
//}

void HeapPush(Heap* hp, HPDataType x)  // �ѵĲ���
{
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType*)* newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	// ԭ�����Ƕ�,���� �����ϵ�����
	//AdjustDown(hp->_a, hp->_size, 0 );

	Ajustup(hp->_a, hp->_size - 1 );
}
//void Ajustup(int *a, size_t child) //�ѵ����ϵ�����
//{
//	int parent = (child - 1) / 2;
//	while (child =  0)
//	{
//		if (a[child] < a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}


void Ajustup(int* a, size_t children) //�����ϵ�����  children��Ϊ����Ԫ�ظ��� O(logn)*n
{
	size_t parent = (children - 1) / 2;
	//while (parent >=0)
	while (children >= 0)
	{
		if (a[children] < a[parent])
		{
			Swap(&a[children], &a[parent]);
			children = parent;
			parent = (children - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPop(Heap* hp) //��� �Ѷ��Ǹ���С�� O(logn)
{
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);	
}
HPDataType HeapTop(Heap* hp)  // ���ضѶ�
{
	assert(hp);
	return hp->_a[0];
}
int HeapSize(Heap* hp)  // ��������
{
	assert(hp->_size > 0);
	return hp->_size;
}
int HeapEmpty(Heap* hp)  // �ж϶��Ƿ�Ϊ��
{
	return hp->_size == 0;
}
void Adjust(HPDataType* a, size_t n, size_t parent) //�����
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}
void HeapSort(int *a, int n)    //���� �����
{
	for (int i = (n - 2) / 2; i >= 0; --i) 
	{
		Adjust(a, n, i);
	}
	
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		Adjust(a, end, 0);
		--end;
	}

	
}

void Print(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void TestHeap()
{
	Heap myheap;
	HPDataType *arr[] = { 5, 7, 3, 4, 1, 2, 6 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	printf("С�� : \n");
	HeapInit(&myheap, arr, sizeof(arr) / sizeof(int));
	Print(&myheap);
	/*printf("������ : \n");
	HeapSort((&myheap)->_a, sizeof(arr) / sizeof(int));
	Print(&myheap);*/
	printf("�Ѳ��� 9\n");
	HeapPush(&myheap,9);
	Print(&myheap);
	printf("�Ѳ��� -1\n");
	HeapPush(&myheap, -1);
	Print(&myheap);
	printf("���ضѶ�Ԫ��\n");
	printf("%d",HeapTop(&myheap));
	printf("\n");
	printf("ɾ���Ѷ�Ԫ��\n");
	HeapPop(&myheap);
	Print(&myheap);
}
//void TestHeap()
//{
//	Heap myheap;
//	//HPDataType* arr[] = {7,3,8,9,2,1,6 };
//	HPDataType arr[] = { 9, 2, 3, 5, 8, 4 };
//	HeapInit(&myheap, arr, sizeof(arr)/sizeof(int));
//	//Print(&myheap);
//	Print(&myheap);
//
//	//HeapPush(&myheap, -1);
//	//Print(&myheap);
//	HeapSort(arr, sizeof(arr) / sizeof(HPDataType));
//	Print(&myheap);
//	//Print(&myheap);


	/*for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ",);
	}
	printf("\n");
*/
	// ���ضѶ�Ԫ��
	//printf("%d\n", HeapTop(&myheap));


	//while (!HeapEmpty(&myheap))
	//{
	//	HeapPop(&myheap); //��� �Ѷ��Ǹ���С��
	//	for (int i = 0; i < HeapSize(&myheap); i++)
	//	{
	//		printf("%d ", myheap._a[i]);
	//	}
	//	printf("\n");
	//}
	/*HeapPush(&myheap, 19);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", myheap._a[i]);
	}
	printf("\n");*/
	//Print(myheap._a, sizeof(arr) / sizeof(int));
	
//}

//void TestHeap()
//{
//	int a[] = { 7, 5, 2, 0, 6, 8, 3, 9, 1 };
//	Heap hp;
//	HeapInit(&hp, a, sizeof(a) / sizezof(int));
//	HeapPrint(&hp);
//	HeapPush(&hp, 3);
//	HeapPush(&hp, -1);
//	HeapPrint(&hp);
//	HeapPop(&hp);
//	HeapPrint(&hp);
//}
