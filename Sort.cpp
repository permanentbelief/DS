#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


/*
void TestQuickSort()
{
int a[] = { 9, 5, 7, 8, 6, 1, 3, 4, 2 };
//int a[] = { 9,8,7,6,5,4,3,2,1,0 };
QuickSortNonR(a, 0, sizeof(a) / sizeof(int)-1);
PrintArray(a, sizeof(a) / sizeof(int));
}
*/

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int x = *p1;
	*p1 = *p2;
	*p2 = x;
}
int PartSort1(int* a, int left, int right)
{
	int key = a[right];
	int keyindex = right;
	while (left < right)
	{
		// left找大 right找小 再交换

		while (left < right && a[right] >= key)
		{
			--right;
		}
		while (left < right && a[left] <= key)
		{
			++left;
		}


		if (left < right)
		{
			Swap(&a[left], &a[right]);
			++left;
			--right;
		}
	}
		Swap(&a[left], &a[keyindex]);
		return left;

}
int PartSort2(int* a, int left, int right)
{
	int hole = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= hole)
			left++;
		a[right] = a[left];
		while (left < right &&  a[right] >= hole)
			right--;
		a[left] = a[right];

	}
	a[left] = hole;
	return left;
}

int PartSort3(int *a, int left, int right)
{
	
	int key = a[right];
	int prev = left - 1;
	int cur = left;
	while (cur < right)
	{
		if (a[cur] <= key && ++prev != cur) //找小的
		{
			//++prev;
			Swap(&a[prev], &a[cur]);
		}
			

		++cur;

	}
	Swap(&a[++prev], &a[right]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

		int keyindex = PartSort1(a, left, right);
		// [left, keyindex-1] key [keyindex+1, right]
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	

}

int main()
{
	//int a[] = { 9, 5, 7, 8, 6, 1, 3, 4, 2 };
	//QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//PrintArray(a, sizeof(a) / sizeof(a[0]));


	int b[] = { 8,1,2,7,9,3,4,5,10,8 };
	QuickSort(b, 0, sizeof(b) / sizeof(b[0]) - 1);
	PrintArray(b, sizeof(b) / sizeof(b[0]));


	//int c[] = { 6 ,1 ,2 ,5 ,3 ,6 };
	//QuickSort(c, 0, sizeof(c) / sizeof(c[0]) - 1);
	//PrintArray(c, sizeof(c) / sizeof(c[0]));

	system("pause");
}