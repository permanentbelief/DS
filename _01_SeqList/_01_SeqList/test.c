#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"
void test()
{
	SeqList myseqlist;
	SeqListInit(&myseqlist);
	SeqListPushBack(&myseqlist, 99);
	SeqListPushBack(&myseqlist, 99);
	SeqListPushBack(&myseqlist, 99);
	SeqListPushBack(&myseqlist, 99);
	SeqListPopBack(&myseqlist);

	SeqListPopBack(&myseqlist);
	SeqListPrint(&myseqlist);
	SeqListPushFront(&myseqlist, 8);
	SeqListPushFront(&myseqlist, 7);
	SeqListInit(&myseqlist);
	SeqListPushFront(&myseqlist, 6);
	SeqListPushFront(&myseqlist, 5);
	SeqListPushFront(&myseqlist, 6);
	SeqListPushFront(&myseqlist, 5);
	SeqListPushFront(&myseqlist, 4);
	SeqListPushFront(&myseqlist, 3);
	SeqListPushFront(&myseqlist, 2);
	SeqListPushFront(&myseqlist, 2);
	SeqListPushFront(&myseqlist, 2);
	SeqListPushFront(&myseqlist, 2);
	SeqListPushFront(&myseqlist, 2);
	SeqListPushFront(&myseqlist, 2);

	SeqListPrint(&myseqlist);
	SeqListPopFront(&myseqlist);
	SeqListPopFront(&myseqlist);
	SeqListPopFront(&myseqlist);
	SeqListPrint(&myseqlist);

}
void test1()
{
	SeqList a;
	SeqListInit(&a);
	SeqListPushBack(&a, 3);
	SeqListPushBack(&a, 2);
	SeqListPushBack(&a, 3);
	SeqListPushBack(&a, 3);
	SeqListPushBack(&a, 3);
	SeqListPrint(&a);
	int ret = SeqListFind(&a, 2);

	SeqListInsert(&a, ret, 7);
	SeqListPrint(&a);
	int pos = SeqListFind(&a, 2);
	SeqListErase(&a, pos);
	SeqListPrint(&a);
	SeqListRemove(&a, 3);
	SeqListPrint(&a);
	SeqListModify(&a, 2, 99);
	SeqListPrint(&a);
	SeqListBubbleSort(&a);


}
void test2()
{
	SeqList a;
	SeqListInit(&a);
	SeqListPushBack(&a, 6);
	SeqListPushBack(&a, 5);
	SeqListPushBack(&a, 4);
	SeqListPushBack(&a, 1);
	SeqListPushBack(&a, 7);
	SeqListPrint(&a);
	//SeqListRemoveAll(&a,7);
	SeqListBubbleSort(&a);
	SeqListPrint(&a);
	printf("%d", SeqListBinaryFind(&a, 7));

}
int main()
{
	test2();
	system("pause");
}