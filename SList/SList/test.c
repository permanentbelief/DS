#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"
void  TestSList1()// ������ ������ɾ��
{
	
	SList mySList; 
	SListInit(&mySList);//ע�����Ҫ��ʼ������Ȼ�Ļ����л�����
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
	SListNode* pos = SListFind(&mySList, 4);//���Ҳ�����4����ڵ�,���ۺ���������ӿ�
	SListInsert(pos, 999);
	SListPrint(&mySList);
	SListRemove(&mySList, 999);//����4���ͷ���
	SListPrint(&mySList);
	SListRemove(&mySList, 4);
	SListPrint(&mySList);
	//SListRemoveAll(&mySList, 4);
	SListNode* pos1 = SListFind(&mySList, 4);//���Ҳ�����4����ڵ�,���ۺ���������ӿ�
	SListEraseAfter(pos1);// �ͷ�pos�ڵ���һλ
	SListPrint(&mySList);
	SListNode* pos2 = SListFind(&mySList, 2);//���Ҳ�����4����ڵ�,���ۺ���������ӿ�
	SListEraseAfter(pos2);
	SListPrint(&mySList);
	SListDestory(&mySList);
}
void TestSList3() //����RemoveAll �����Ĵ���
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