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
		int tmp = arr[end + 1]; //��ʱ���� 
		while (end >= 0)
		{
			if (tmp < arr[end]) // ��arr[end+1]����
			{
				arr[end + 1] = arr[end];
			}
			else
			{
				break;
			}
			end--;

			arr[end + 1] = tmp; //�����arr[end+1]����ʱ����tmp����arr[end]
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
	int end = n; // n���� ������±���[0,n-1];��������±�ȡ����n
	while (end > 0)
	{
		for (int i = 0; i < end - 1; i++)
		{
			if (arr[i] > arr[i + 1])  // �ڸ�ѭ���еĵĵ�һ�� i+1���ÿ���ȡ��end-1��λ�ã���Ϊ i< end - 1, i+1�ڵ�һ��ѭ���о���ȡ����������һ��λ��
			{
				Swap(&arr[i], &arr[i + 1]); //��������ֵ�� �����ŵ�������
			}
		}
		end--; //���һ��λ�ü��� ��Ϊ�Ѿ����������ŵ����һ��λ�ã� Ҳ���������±���n-1��λ��
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

void AdjustDown(int* arr, int n, int parent) //��������
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
void HeapSort(int* arr, int n) //���� �����  ������
{
	for (int i = (n - 2) / 2; i >= 0; i--) //�����
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

// ���Ų��� ѡ���м�ڵ�
//���ѡ��������ұ�ѡС����
int PartSort(int* arr, int left, int right) //������ ���right���������Ԫ�ص��±�
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

//�ڿӷ�ʵ�ֿ���
int PartSort1(int *arr, int left, int right)
{
	int hole = arr[right];
	while (left < right)
	{
		while (left < right &&  arr[left] <= hole)//ѡ���ȿӴ��ֵ�������ұ�
			left++;
		arr[right] = arr[left];
		while (left < right && a[right] >= hole) //ѡ��С�ģ� ����ԭ���Ŀ���
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
void PrintArray(int*arr, int n) // ��ӡ����
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
	printf("ԭ��������arr\n");
	PrintArray(arr, size);
	printf("ð������֮�������\n");
	BubbleSort1(arr, size);
	PrintArray(arr, size);
	BubbleSort2(arr, size);
	PrintArray(arr, size);
	BubbleSort3(arr, size);
	PrintArray(arr,size);
	printf("����ʵ��\n");
	QuickSort(arr, 0, size - 1);
	PrintArray(arr, size);

	system("pause");


}
	/*printf("������֮�������arr\n");
	HeapSort(arr,sizeof(arr)/sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));




	SelectSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
	InsertSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
	ShellSort(arr, sizeof(arr) / sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));*/
