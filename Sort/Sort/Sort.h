#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>


void Swap(int *a, int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}
void InsertSort(int *arr, int n) // 插入排序
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1]; //临时变量 存住arr[end]的值
		while (end >= 0)
		{
			if (tmp < arr[end])  //排升序
				arr[end + 1] = arr[end]; // 将arr[end+1]覆盖
			
			else
			{
				break;
			}
			end--;
			arr[end + 1] = tmp;// 把存放arr[end+1]的临时变量tmp赋给arr[end]
		}
		
	}
	
}
void ShellSort(int* arr, int n) //希维尔排序
{
	int gap = n-1;
	for (int i = 0; i < n - gap; i++)
	{
		gap = gap / 3 + 1;
		int end = i;
		int tmp = arr[end + gap];
		while (end >= 0)
		{
			if (arr[end] < arr[end + gap])
			{
				Swap(&arr[end], &arr[end + gap]);
			}

			else
			{
				break;
			}
			end -= gap;
			arr[end + gap] = tmp;
		}
	}
}
void SelectSort(int *arr, int n) // 选择排序
{
	int begin = 0;
	int end = n - 1;
	int maxindex = 0;
	int minindex = 0;
	while (begin <= end)
	{
		maxindex = minindex = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] > arr[maxindex])
				maxindex = i;
			if (arr[i] < arr[minindex])
				minindex = i;
		}
		
		Swap(&arr[begin], &arr[minindex]);
		if (maxindex == begin)
		{
			
			maxindex = minindex;
		}
		Swap(&arr[end], &arr[maxindex]);
		begin++;
		end--;
	}
}
void PrintArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void AdjustDown(int *arr, int n, int parent) //向下排序法
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child] < arr[child + 1])
			child++;
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int *arr, int n)  //升序 建大堆  堆排序
{
	for (int i = (n - 2) / 2; i >= 0; i--)  //建大堆
	{
		AdjustDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}


void TestSeletTest()
{
	//int arr[] = { 11, 2, 4, 5, 7, 9, 6 };
	int arr1[] = { 1, 3, 9, 4, 6, 7, 8 };
	PrintArr(arr1, sizeof(arr1) / sizeof(int));

	//SelectSort(arr, sizeof(arr) / sizeof(int));
	//InsertSort(arr, sizeof(arr) / sizeof(int));
	//ShellSort(arr, sizeof(arr) / sizeof(int));
	HeapSort(arr1, sizeof(arr1) / sizeof(int));
	PrintArr(arr1, sizeof(arr1) / sizeof(int));
}
void TestOP()
{
	const int n = 10000;
	int * arr = (int*)malloc(sizeof(int)*n);
	//unsigned(time(NULL));
	//int start1 = .clock;

}