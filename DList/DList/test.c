#define _CRT_SECURE_NO_WARNINGS 1 
#include "List.h"
void test1()
{
	List* mylist = NULL;
	/*ListInit(&mylist);
	ListPushBack(&mylist, 4);
	ListPushBack(&mylist, 4);
	ListPushBack(&mylist, 4);
	ListPushBack(&mylist, 4);
	ListPushBack(&mylist, 5);
	ListPopBack(&mylist);
	ListPopBack(&mylist);
	ListPopBack(&mylist);
	ListPopBack(&mylist);
	ListPopBack(&mylist);*/
	//ListInit(&mylist);
	//ListPopBack(mylist);
	//ListPrint(&mylist);

	
}
void test2()
{
	List mylist;
	ListInit(&mylist);
	ListPushBack(&mylist, 7);
	ListPushBack(&mylist, 6);
	ListPushBack(&mylist, 5);
	ListPushBack(&mylist, 4);
	ListPrint(&mylist);
	ListPopBack(&mylist);
	ListPopBack(&mylist);
	ListPopBack(&mylist);
	ListPopBack(&mylist);

	ListPrint(&mylist);
	ListPushFront(&mylist,99);
	ListPrint(&mylist);

}
int main()
{
	test2();
	system("pause");
}