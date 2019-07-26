#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

// ��������
//void InSertSwap(int * arr, int n)
//{
//	for (int i = 0; i < n - 1; i++) //��n-1������ tmp����ȡ��arr[n-1]�������ⲻ��ȡ��
//	{
//		int end = i;
//		int tmp = arr[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//				arr[end + 1] = arr[end]; //���� tmp
//			else
//				break;
//			end--;
//			arr[end + 1] = tmp;
//		}
//	}
//
//}
void InSertSort(int*arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int  end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] < tmp)
				arr[end + 1] = arr[end];
			else
			{
				break;
			}
			end--;
			arr[end + 1] = tmp;
		}
	}
}
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void ShellSort(int* arr, int n) // ϣά������
{
	int gap = 3;
	for (int j = 0; j < n / gap; j++)
	{
		for (int i = 0; i < n / gap; i++)
		{
			while (i < n)
			{
				if (arr[i] < arr[i + gap])
				{
					Swap(&arr[i], &arr[i + gap]);
				}
				i += gap;
			}
		}
		
			/*int end = i;
			int tmp = arr[end + gap];*/
			/*while (end >= 0)
			{
				if (arr[end] > tmp)
					arr[end + gap] = arr[end];
				else
					break;
				end -= gap;
				arr[end + gap] = tmp;*/
			
		}
	}
	


void Print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

void BubbleSort1(int *arr, int n)
{
	int end = n;
	while (end > 0)
	{
		for (int i = 0; i < end - 1; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				Swap(&arr[i], &arr[i + 1]);
			}
		}
		end--;
	}
}

//���� ȡ�з�
int MID(int*a, int left, int right)
{
	int last = a[right];
	int mid = a[left] + (a[right] - a[left]) / 2;
	int first = a[left];
	int k = 0;
	if (last < first)
	{
		if (first < mid)
		{
			k = first;
		}
		if (first > mid)
		{
			if (mid > last)
			{
				k = mid;
			}
			else
			{
				k = last;
			}
		}
		
	}
	else // last > first
	{
		if (first > mid)
		{
			k = first;
		}
		if (mid < last)
		{
			if (mid > first)
			{
				k = mid;
			}
			else
			{
				k = first;
			}
		}
	}
	return k;
}
// ���Ų��� ѡ���м�ڵ�
//���ѡ��������ұ�ѡС����
int PartSort(int *a, int left, int right) //������ ���right���������Ԫ�ص��±�
{
	int key = a[right];
	int k = right;
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			left++;
		}
		while (left < right && a[right] >= key)
		{
			right--;
		}
		if (left < right)
		{
			Swap(&a[left], &a[right]);
			left++;
			right--;
		}
			
	}
	Swap(&a[left], &a[k]);
	return left;
}
// ���� �ݹ�ʵ��
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return ;
	}
	int mid = PartSort(a, left, right);
	QuickSort(a, 0, mid - 1);
	QuickSort(a, mid + 1, right);
}

//�ڿӷ� ʵ�ֿ���
int PartSort1(int *a , int left, int right)
{
	int hole = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= hole) //ѡ����ȿӴ��ֵ �����ұ�
		{
			left++;
		}
		a[right] = a[left];
		while (left < right && a[right] >= hole)//ѡ��С�� ����ԭ���Ŀ���
		{
			right--;
		}
		a[left] = a[right];
	}
	a[left] = hole;
	return left;
}

void QuickSort1(int* a, int left, int right)
{
	if (left > right)
	{
		return;
	}
	int hole = PartSort1(a, left, right);
	QuickSort1(a, 0, hole - 1);
	QuickSort1(a, hole + 1, right);
}

void test()
{
	int a[]   = { 9,5,7,8,6,1,3,4,2};
	//BubbleSort1(a, sizeof(a) / sizeof(int));

	//QuickSort(a, 0, sizeof(a) / sizeof(int) -1);
	//QuickSort1(a, 0, sizeof(a) / sizeof(int)-1);
	//InSertSort(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void top()
{
	srand((unsigned int )time(NULL));
	const int n = 5000;
	int *a1 = (int*)malloc(sizeof(int*)*n);
	int *a2 = (int*)malloc(sizeof(int*)*n);
	//int *a3 = (int*)malloc(sizeof(int*)*n);
	//int *a4 = (int*)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		//a3[i] = a2[i];
	}

	int start1 = clock();
	BubbleSort1(a1, n);
	int end1 = clock();

	int start2 = clock();
	QuickSort(a2, 0, n-1);
	int end2 = clock();

	printf("BubbleSort : %d\n ", end1 - start1);
	printf("QuickSort  : %d ", end2 - start2);

}