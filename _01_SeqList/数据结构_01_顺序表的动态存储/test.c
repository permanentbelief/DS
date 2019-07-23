#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"
//验证头插 尾插 头删 尾删
void test1()
{
	SeqList my_S;
	SeqListInit(&my_S);
	//尾插了五个数
	SeqListPushBack(&my_S, 1);
	SeqListPushBack(&my_S, 2);
	SeqListPushBack(&my_S, 3);
	SeqListPushBack(&my_S, 4);
	SeqListPushBack(&my_S, 5);
	SeqListPrint(&my_S);
	////前插了五个数
	//SeqListPushFront(&my_S, 10);
	//SeqListPushFront(&my_S, 9);
	//SeqListPushFront(&my_S, 8);
	//SeqListPushFront(&my_S, 7);
	//SeqListPushFront(&my_S, 6);
	////前删
	//SeqListPopFront(&my_S);
	//SeqListPopFront(&my_S);
	////尾删
	//SeqListPopBack(&my_S);
	//SeqListPopBack(&my_S);
	//SeqListPrint(&my_S);
	////前删
	/*SeqListPopFront(&my_S);
	SeqListPopFront(&my_S);
	SeqListPrint(&my_S);*/
	//查找数据]
	//SeqListRemove(&my_S, 10);
	//SeqListPrint(&my_S);
	//printf("%d",SeqListFind(&my_S, 10));
	

}
int main()
{
	
	test1();
	system("pause");
}