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
	//ListPushBack(&mylist, 99);
	//ListPushBack(&mylist, 99);
	//ListPushBack(&mylist, 99);
	//ListPushBack(&mylist, 98);
	//ListPushBack(&mylist, 99);
	//ListPushBack(&mylist, 99);
	//ListPushBack(&mylist, 99);
	//ListPrint(&mylist);
	//
	//ListPrint(&mylist);
	////ListErase(pos);
	//ListPrint(&mylist);
	ListPushFront(&mylist, 990);
	ListPushFront(&mylist, 990);
	ListPushFront(&mylist, 990);
	ListPushFront(&mylist, 990);
	ListPrint(&mylist);
	ListPushFront(&mylist, 6);
	ListPushFront(&mylist, 6);
	ListPushFront(&mylist, 6);
	ListPushFront(&mylist, 6);

	ListPrint(&mylist);

	//ListPopFront(&mylist); 前删两次以上有问题
	//ListPopFront(&mylist);
	ListPushBack(&mylist, 99);
	ListPushBack(&mylist, 99);
	ListPushBack(&mylist, 99);
	ListPushBack(&mylist, 99);
	ListPushBack(&mylist, 99);

	


	ListPrint(&mylist);
	/*ListPopBack(&mylist);
	ListPopBack(&mylist);
	ListPopBack(&mylist);
	ListPopBack(&mylist);
	ListPopBack(&mylist);

	ListPopBack(&mylist);*/
	ListPopFront(&mylist);
	ListPopFront(&mylist);
	ListPopFront(&mylist);

	ListPopFront(&mylist);
	ListPrint(&mylist);


	/*ListNode* pos = ListFind(&mylist, 99);
	ListErase(pos);
	ListErase(pos);
	ListErase(pos);
	
	ListPrint(&mylist);*/

	//ListInsert(pos, 100);

	//ListPrint(&mylist);
	//ListPopFront(&mylist);
	//ListPopFront(&mylist);
	//ListPopFront(&mylist);
	//ListPopFront(&mylist);
	//ListPopFront(&mylist);
	//ListPopBack(&mylist);
	//ListPopBack(&mylist);
	//ListPrint(&mylist);


	/*ListPushBack(&mylist, 7);
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
	ListPrint(&mylist);*/
	ListDestory(&mylist);
	

}
void  test3()
{
	List my;
	ListInit(&my);
	ListPushBack(&my, 121);
	ListPushBack(&my,909);
	ListPrint(&my);
}
int main()
{
	test2();
	system("pause");
}