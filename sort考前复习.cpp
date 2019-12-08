#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <cstdlib>

void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1]; //临时变量 
		while (end >= 0)
		{
			if (tmp < arr[end]) // 将arr[end+1]覆盖
			{
				arr[end + 1] = arr[end];
			}
			else
			{
				break;
			}
			end--;

			arr[end + 1] = tmp; //将存放arr[end+1]的临时变量tmp赋给arr[end]
		}
	}
}
void ShellSort(int *arr, int n)
{
	int gap = n - 1;
	for (int i = 0; i < n - gap; i++)
	{
		gap = n / 3 + 1;;
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
		}
		end -= gap;
		arr[end + gap] = tmp;
	}
}


void BubbleSort1(int* arr, int n)
{
	int end = n; // n个数 数组的下标是[0,n-1];，数组的下标取不到n
	while (end > 0)
	{
		for (int i = 0; i < end - 1; i++)
		{
			if (arr[i] > arr[i + 1])  // 在个循环中的的第一次 i+1正好可以取到end-1的位置，因为 i< end - 1, i+1在第一次循环中就是取到数组的最后一个位置
			{
				Swap(&arr[i], &arr[i + 1]); //交换两个值， 排序排的是升序
			}
		}
		end--; //最后一个位置减减 因为已经将最大的数排到最后一个位置， 也就是数组下标是n-1的位置
	}
}

void BubbleSort2(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void BubbleSort3(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (arr[j] < arr[j - 1])
			{
				Swap(&arr[j], &arr[j - 1]);
			}
		}
	}
}
void SelectSort(int *arr, int n)
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
			{
				maxindex = i;
			}
			if (arr[i] < arr[minindex])
			{
				minindex = i;
			}
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

void AdjustDown(int* arr, int n, int parent) //向下排序法
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
			child++;
		if (arr[child] >arr[parent])
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
void HeapSort(int* arr, int n) //升序 建大堆  堆排序
{
	for (int i = (n - 2) / 2; i >= 0; i--) //建大堆
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

// 快排部分 选出中间节点
//左边选大的数，右边选小的数
int PartSort(int* arr, int left, int right) //闭区间 这个right是数组最后元素的下标
{
	int key = arr[right];
	int k = right;
	while (left < right)
	{
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		if (left < right)
		{
			Swap(&arr[left], &arr[right]);
			left++;
			right--;
		}

	}
	Swap(&arr[left], &arr[k]);
	return left;
}
void QuickSort(int *arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = PartSort(arr, left, right);
	QuickSort(arr, 0, mid - 1);
	QuickSort(arr, mid + 1, right);
}

//挖坑法实现快排
int PartSort1(int *arr, int left, int right)
{
	int hole = arr[right];
	while (left < right)
	{
		while (left < right &&  arr[left] <= hole)//选出比坑大的值，放在右边
			left++;
		arr[right] = arr[left];
		while (left < right && a[right] >= hole) //选出小的， 放在原来的坑上
			right--;
		arr[left] = arr[right];
	}
	arr[left] = hole;
	return left;

}
void QuickSort1(int *arr, int left, int right)
{
	if (left > right)
		return;
	int hole = PartSort1(arr, left, right);
	QuickSort1(arr, 0, hole - 1);
	QuickSort1(arr, hole, right);
}
void PrintArray(int*arr, int n) // 打印数组
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}
int main()
{
	int  arr[] = { 1, 3, 4, 9, 3, 5, 7, 0 ,8, 6, 2};
	int size = sizeof(arr) / sizeof(int);
	printf("原来的数组arr\n");
	PrintArray(arr, size);
	printf("冒泡排序之后的数组\n");
	BubbleSort1(arr, size);
	PrintArray(arr, size);
	BubbleSort2(arr, size);
	PrintArray(arr, size);
	BubbleSort3(arr, size);
	PrintArray(arr,size);
	printf("快排实现\n");
	QuickSort(arr, 0, size - 1);
	PrintArray(arr, size);

	system("pause");


}
	/*printf("堆排序之后的数组arr\n");
	HeapSort(arr,sizeof(arr)/sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));




	SelectSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
	InsertSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
	ShellSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));*/
