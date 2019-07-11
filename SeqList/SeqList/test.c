#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"
void test1()
{
	SeqList mySeqList;
	SeqListInit(&mySeqList);
	SeqListPushBack(&mySeqList, 3);
	SeqListPushBack(&mySeqList, 4);
	SeqListPushBack(&mySeqList, 5);
	SeqListPushBack(&mySeqList, 7);
	SeqListPushBack(&mySeqList, 9);
	for (size_t i = 0; i < SeqListSize(&mySeqList); i++)
	{
		printf("%d ", SeqListAt(&mySeqList,i));
	}

}
int main()
{
	test1();
	system("pause");
}