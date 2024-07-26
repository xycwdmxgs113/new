#include"SList.h"

void TestSList1() {

	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLPushBack(&plist, 5);
	SLPushBack(&plist, 6);
	SLPushBack(&plist, 7);
	SLPushFront(&plist, 8);
	SLPushFront(&plist, 9);
	SLPrint(plist);

	SLPopBack(&plist);
	SLPrint(plist);
	SLPopFront(&plist);
	SLPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	SListInsert(&plist, pos, 66);
	SLPrint(plist);
	SListInsertAfter(pos, 77);
	SLPrint(plist);
	SListEraseAfter(pos);
	SLPrint(plist);
	SLTDestroy(&plist);
	SLPrint(plist);
}

int main() {
	TestSList1();


	return 0;
}