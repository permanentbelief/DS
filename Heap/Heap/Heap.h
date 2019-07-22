// 最小堆


#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>



typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;


void AdjustDown(HPDataType* a, size_t n, size_t parent);//堆向下调整算法
void Swap(HPDataType x, HPDataType y);
void HeapInit(Heap* hp, HPDataType *a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

//堆排序
void HeapSort(int *a, int n);

//向上调算法
void Ajustup(int* a, size_t n);
void TestHeap();
