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
////ͨ��ǰ���������"ABD##E##CF##G##"  ����������
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
			child++; //ѡ�������Ǹ�����
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

void HeapSort(int* arr, int n) //���� �����
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
// ����
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
//ѡ������
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

void ShellSort(int* arr, int n) //ϣά������
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
	//printf("ԭ��������arr\n");
	//PrintArray(arr, sizeof(arr) / sizeof(int));
	//printf("������֮�������arr\n");
	//HeapSort(arr, sizeof(arr) / sizeof(int));
	//PrintArray(arr, sizeof(arr) / sizeof(int));
	system("pause");

}
/*
�㷨�����۱�׼������
��ȷ�� �ɶ��� ��׳�� ʱ������ �ռ�����
�㷨�������Ҫ���ԣ�
������ ȷ���� ��6���� ���� ���

����ɭ�ֶ�Ӧ�Ķ�����

*/