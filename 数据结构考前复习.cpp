#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
using namespace std;

//typedef char BTDataType;
//
//typedef struct BTNode
//{
//	BTDataType _data;
//	BTNode* _left;
//	BTNode* _right;
//}BTNode;
////通过前序遍历数组"ABD##E##CF##G##"  构建二叉树
//BTNode* BinaryTreeCreate(BTDataType * a, int*p)
//{
//	if (a[*pi] == '#')
//	{
//
//	}
//}

void AdjustDown(int*arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
			child++; //选出最大的那个孩子
		if (arr[child] > arr[parent])
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void HeapSort(int* arr, int n) //升序 建大堆
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}
void InsertSort(int* arr, int n) // 1  2  3
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{

			if (tmp > arr[end])
				arr[end + 1] = arr[end];
			else
				break;

			end--;
			arr[end + 1] = tmp;
		}
		
	}

}
// 快排
int partSort(int* a, int left, int right)
{
	int key = a[right];
	int k = right;
	while (left < right)
	{
		while (left < right && a[left] <= key)
			left++;
		while (left < right && a[right] >= key)
			right--;
		if (left < right)
		{
			swap(a[left], a[right]);
			left++;
			right--;
		}
	}
	swap(a[left], a[k]);
	return left;

}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int mid = partSort(a, left, right);
	QuickSort(a, 0, mid - 1);
	QuickSort(a, mid + 1, right);

}
//选择排序
void SelectSort(int* arr, int n)
{
	for (int i = 0; i < n - 1 ; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}

		if (min != i)
			swap(arr[i], arr[min]);

		PrintArray(arr, n);
	}
	

}
void InSertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
				arr[end + 1] = arr[end];
			else
				break;
			end--;

			arr[end + 1] = tmp;
		}
	}
}

void ShellSort(int* arr, int n) //希维尔排序
{
	int gap = n;
	for (int i = 0; i < n - gap; i++)
	{
		gap = gap / 3 + 1;
		int end = i;
		int tmp = arr[end + gap];
		while (end >= 0)
		{
			if (tmp < arr[end + gap])
			{
				swap(arr[end], arr[end + gap]);
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


int main()
{
	int  arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	PrintArray(arr, sizeof(arr) / sizeof(int));
	cout << endl;
	SelectSort(arr, sizeof(arr) / sizeof(int));
	//PrintArray(arr, sizeof(arr) / sizeof(int));

	//PrintArray(arr, sizeof(arr) / sizeof(int));
	//InSertSort(arr, sizeof(arr) / sizeof(int));
	//ShellSort(arr, sizeof(arr) / sizeof(int));
	//PrintArray(arr, sizeof(arr) / sizeof(int));
	//int  arr[] = { 1, 3, 4, 9, 3, 5, 7, 0, 8, 6, 2 };
	//printf("原来的数组arr\n");
	//PrintArray(arr, sizeof(arr) / sizeof(int));
	//printf("堆排序之后的数组arr\n");
	//HeapSort(arr, sizeof(arr) / sizeof(int));
	//PrintArray(arr, sizeof(arr) / sizeof(int));
	system("pause");

}
/*
算法的评价标准包括：
正确性 可读性 健壮性 时间特性 空间特性
算法的五个重要特性：
有穷性 确定性 可6信性 输入 输出

画出森林对应的二叉树

*/