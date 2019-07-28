
#include <stdio.h>
#include <malloc.h>


void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//快排的第三种方法 前后指针
int PartSort(int* a, int left, int right) //闭区间
{
	
	int cur = left;
	int prev = cur - 1;                   //这为什么不能用0 或-1;
	int key = a[right];
	while (cur < right)
	{
		if (a[cur] >key && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	++prev;
	Swap(&a[prev], &a[right]);
	return prev;
}
void QuickSort(int *a, int left, int right)
{

	if (left >= right)
	{
		return;
	}
	int mid = PartSort(a, left, right);
	QuickSort(a, left, mid - 1);
	QuickSort(a,  mid + 1, right);
}
void PrintArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//快排的非递归实现
#include "Stack.h"
void QuickSortNonR(int * a, int left, int right)
{
	Stack mystack;
	StackInit(&mystack);

	StackPush(&mystack, left);
	StackPush(&mystack, right);
	//StackPop(&mystack);
	while (!StackEmpty(&mystack))
	{
		int end = StackTop(&mystack);
		StackPop(&mystack);
		int begin = StackTop(&mystack);
		StackPop(&mystack);
		int div = PartSort(a, begin, end);
		if (begin < div - 1)
		{
			StackPush(&mystack, begin);
			StackPush(&mystack, div - 1);
		}
		if (div + 1 < end)
		{
			StackPush(&mystack, div + 1);
			StackPush(&mystack, end);
		}
	}
}
// 归并排序
void Merge(int* arr,int mid ,int left, int right)
{
	int * tmp = (int*)malloc(sizeof(int)*(right - left + 1));
	int left_low = left;         //     
	int left_high = mid ;        //     
	int right_low = mid + 1;     //     
	int right_high = right;      //     
	int k = 0;
	while (left_low <= left_high && right_low <= right_high)
	{
		if (arr[left_low] <= arr[left_high])
		{
			tmp[k++] = arr[left_low];
			left_low++;
		}
		if (arr[right_low] < arr[right_low])
		{
			tmp[k++] = arr[right_low];
			right_low++;

		}
	}
	while (left_low > left_high)
	{
		tmp[k++] = arr[right_low++];
	}
	while (right_low > right_high)
	{
		tmp[k++] = arr[left_low++];
	}
	/*for (int i = 0; i <= right_high; i++)
	{
		arr[left + i] = arr[i];
	}*/
}
void MergeSort(int* arr, int left , int right) // 0 1  的 时候
{
	if (left == right)  // 已理解
	{
		return;
	}
	//分治算法
	int mid = (left + right) / 2; // mid = 0
	MergeSort(arr, left, mid ); //arr  
	MergeSort(arr, mid+1 , right);
	//归并
	Merge(arr,mid , left, right);  // arr 0 

}
void test()
{
	int a[] = {6,8,9,4,1 };
	PrintArray(a, sizeof(a)/sizeof(int));
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
	//QuickSortNonR(a, 0, sizeof(a) / sizeof(int)-1);
	MergeSort(a, 0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));

}