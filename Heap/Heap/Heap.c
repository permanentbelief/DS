#define _CRT_SECURE_NO_WARNINGS 1 

#include "Heap.h"

void Swap(HPDataType*num1, HPDataType* num2)  //交换函数
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
//void HeapInit(Heap* hp, HPDataType *a, int n) // 堆的初始化 建堆
//{
//	  
//		hp->_a = malloc(sizeof(HPDataType)*n);
//		memcpy(hp->_a, a, sizeof(HPDataType)*n);
//		hp->_size = n;
//		hp->_capacity = n;
//	//构建堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--) //调用向下调整法 构建堆。
//	{
//			AdjustDown(hp->_a, hp->_size, i);
//	}
//}

void AdjustDown(HPDataType* a, size_t n, size_t parent) //建小堆
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出小的那个孩纸
		if (child + 1 < n && a[child + 1] < a[child])
			++child;

		// 孩纸小于父亲，则交换
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
void HeapDestory(Heap* hp)	//销毁堆
{
	if (hp->_a != NULL)
	{
		free(hp->_a);
		hp->_a = NULL;
	}
	hp->_size = hp->_capacity = 0;
}
//void HeapPush(Heap*hp, HPDataType x)   注意malloc会使失败 因为memcpy将 数组的空间和值赋给hp->_a
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

void HeapPush(Heap* hp, HPDataType x)  // 堆的插入
{
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType*)* newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	// 原本就是堆,所以 堆向上调整法
	//AdjustDown(hp->_a, hp->_size, 0 );

	Ajustup(hp->_a, hp->_size - 1 );
}
//void Ajustup(int *a, size_t child) //堆的向上调整法
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


void Ajustup(int* a, size_t children) //堆向上调整法  children即为数组元素个数 O(logn)*n
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


void HeapPop(Heap* hp) //清除 堆顶那个最小的 O(logn)
{
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);	
}
HPDataType HeapTop(Heap* hp)  // 返回堆顶
{
	assert(hp);
	return hp->_a[0];
}
int HeapSize(Heap* hp)  // 返回容量
{
	assert(hp->_size > 0);
	return hp->_size;
}
int HeapEmpty(Heap* hp)  // 判断堆是否为空
{
	return hp->_size == 0;
}
void Adjust(HPDataType* a, size_t n, size_t parent) //建大堆
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
void HeapSort(int *a, int n)    //升序 建大堆
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
	printf("小堆 : \n");
	HeapInit(&myheap, arr, sizeof(arr) / sizeof(int));
	Print(&myheap);
	/*printf("堆排序 : \n");
	HeapSort((&myheap)->_a, sizeof(arr) / sizeof(int));
	Print(&myheap);*/
	printf("堆插入 9\n");
	HeapPush(&myheap,9);
	Print(&myheap);
	printf("堆插入 -1\n");
	HeapPush(&myheap, -1);
	Print(&myheap);
	printf("返回堆顶元素\n");
	printf("%d",HeapTop(&myheap));
	printf("\n");
	printf("删除堆顶元素\n");
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
	// 返回堆顶元素
	//printf("%d\n", HeapTop(&myheap));


	//while (!HeapEmpty(&myheap))
	//{
	//	HeapPop(&myheap); //清除 堆顶那个最小的
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
