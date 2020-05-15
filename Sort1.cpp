#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

//≤Â»Î≈≈–Ú
void InsertSort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (arr[j - 1] >= arr[j])
			{
				swap(arr[j - 1], arr[j]);
			}
			else
				break;
		}
	}
}
void InsertSort1(vector<int>& arr)
{
	for (int end = 1; end < arr.size(); end++)
	{
		int tmp = end;
		while (tmp >= 1)
		{
			if (arr[tmp] <= arr[tmp - 1])
			{
				swap(arr[tmp], arr[tmp - 1]);
			}
			else
			{
				break;
			}
			tmp--;
		}
	}
}

void InsertSort3(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
			}
			else
			{
				break;
			}
			end--;
			arr[end + 1] = tmp;
		}
	}
}

void ShellSort(vector<int>& arr)
{
	int gap = arr.size() - 1;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < arr.size(); i++)
		{
			int end = i;
			while (end >= gap)
			{
				if (arr[end] < arr[end - gap])
				{
					swap(arr[end], arr[end - gap]);
				}
				else
				{
					break;
				}
				end -= gap;
			}
		}
		//for (int i = 0; i < arr.size() - gap; i++)
		//{
		//	//gap = gap / 3 + 1;
		//	int end = i;
		//	int tmp = arr[end + gap];
		//	while (end >= 0)
		//	{
		//		if (arr[end] > arr[end + gap])
		//		{
		//			arr[end + gap] = arr[end];
		//		}
		//		else
		//			break;
		//		end -= gap;
		//		arr[end + gap] = tmp;
		//	}
		//}
	}

}

void SelectSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		int min_ = arr[i];
		int min_index = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] < min_)
			{
				min_index = j;
				min_ = arr[j];
			}
		}
		swap(arr[i], arr[min_index]);
	}
}

void SelectSort1(vector<int>& arr)
{
	int n = arr.size();
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
		swap(arr[begin], arr[minindex]);

		if (maxindex == begin)
		{
			maxindex = minindex;
		}
		swap(arr[end], arr[maxindex]);
		begin++;
		end--;
	}
}


void AdjustDown(vector<int>& arr, int n,  int parent)
{
	//int n = arr.size();
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
			child = child + 1;
		if (arr[parent] <= arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void heapSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr,arr.size(),i);
	}

	int end = n - 1;
	while (end > 0)
	{
		swap(arr[end], arr[0]);
		AdjustDown(arr,end, 0);
		end--;
	}
}

int QuickSort_1(vector<int>& arr, int begin , int end)
{
	int left = begin;
	int right = end;
	int key = arr[right];
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
		swap(arr[left], arr[right]);
	}
	swap(arr[right],arr[end]);
	return left;
}
int QuickSort_2(vector<int>& arr, int begin, int end)
{
	int left = begin;
	int right = end;
	int hole = arr[end];
	while (left < right)
	{
		while (left < right && arr[left] <= hole)
			left++;
		arr[right] = arr[left];
		while (left < right && arr[right] >= hole)
			right--;
		arr[left] = arr[right];

	}
	arr[right] = hole;
	return left;
}
void QuickSort(vector<int>& arr, int left, int right)
{
	if (left >= right)
		return;
	int mid = QuickSort_2(arr, left, right);
	QuickSort(arr, left , mid - 1);
	QuickSort(arr, mid + 1, right);
}
//int main()
//{
//	srand(time(nullptr));
//	vector<int> arr = { 24, 5 ,24 ,15, 7, 10 ,18 ,30, 11, 7, 34, 24};
//	for (int i = 0; i < arr.size(); i++)
//	{
//		arr[i] = rand() % 35 + 1;
//	}
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	QuickSort(arr,0,arr.size() - 1);
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	system("pause");
//}