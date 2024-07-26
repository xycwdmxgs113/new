#include"List2.h"


void ListNodeTest01() {
	SLTNode* plist = Init();
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	
	SLTNode* ret = SLTFind(plist, 4);
	SLTInsert(&plist, ret, 66);
	SLTPrint(plist);
	SListDesTroy(&plist);
}

int main() {
	ListNodeTest01();



	return 0;
}