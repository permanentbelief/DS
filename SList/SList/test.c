#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"
void  TestSList1()// 基本的 插入与删除
{
	
	SList mySList; 
	SListInit(&mySList);//注意必须要初始化，不然的话运行会闪退
	SListPushBack(&mySList, 4);
	SListPushBack(&mySList, 3);
	SListPushBack(&mySList, 2);
	SListPushBack(&mySList, 4);
	SListPopBack(&mySList);
	SListPopBack(&mySList);
	SListPopBack(&mySList);
	SListPopBack(&mySList);
	SListPushFront(&mySList, 3);
	SListPushFront(&mySList, 4);
	SListPushFront(&mySList, 5);
	SListPushFront(&mySList, 6);
	SListPushFront(&mySList, 7);
	SListPrint(&mySList);

	SListPopFront(&mySList);
	SListPrint(&mySList);

	SListPopFront(&mySList);
	SListPrint(&mySList);

	SListPopFront(&mySList);
	SListPrint(&mySList);

	//SListPopFront(&mySList);
	//SListPrint(&mySList);




	SListPrint(&mySList);
	//SListDestory(&mySList);
}
void TestSList2()
{
	SList mySList;
	SListInit(&mySList);
	SListPushBack(&mySList, 4);
	SListPushBack(&mySList, 3);
	SListPushBack(&mySList, 2);
	SListPushBack(&mySList, 4);
	SListPrint(&mySList);
	SListNode* pos = SListFind(&mySList, 4);//查找并返回4这个节点,得综合来用这个接口
	SListInsert(pos, 999);
	SListPrint(&mySList);
	SListRemove(&mySList, 999);//移走4这个头结点
	SListPrint(&mySList);
	SListRemove(&mySList, 4);
	SListPrint(&mySList);
	//SListRemoveAll(&mySList, 4);
	SListNode* pos1 = SListFind(&mySList, 4);//查找并返回4这个节点,得综合来用这个接口
	SListEraseAfter(pos1);// 释放pos节点后的一位
	SListPrint(&mySList);
	SListNode* pos2 = SListFind(&mySList, 2);//查找并返回4这个节点,得综合来用这个接口
	SListEraseAfter(pos2);
	SListPrint(&mySList);
	SListDestory(&mySList);
}
void TestSList3() //测试RemoveAll 函数哪错了
{
	SList mySList;
	SListInit(&mySList);
	SListPushFront(&mySList, 1);
	SListPushFront(&mySList, 2);
	SListPushFront(&mySList, 3);
	SListPushFront(&mySList, 3);
	SListPushFront(&mySList, 6);
	SListPushFront(&mySList, 5);
	SListPushFront(&mySList, 4);
	SListPrint(&mySList);
	SListRemove1(&mySList, 4);
	SListPrint(&mySList);

	SListDestory(&mySList);
}
int main()
{
	//TestSList1();
	//TestSList2();
	TestSList3();
	system("pause");
}