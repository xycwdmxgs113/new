#include"My_List.h"



void ListNodeTest01() {
	ListNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPrint(plist);
	LTPushBack(plist, 2);
	LTPrint(plist);
	LTPushBack(plist, 3);
	LTPrint(plist);
	LTPushBack(plist, 4);
	LTPrint(plist);

	ListNode* ret = Find(plist, 4);
	LTErase(ret);
	LTPrint(plist);
	
	LTDisTroy(plist);
	plist = NULL;
}


int main() {
	ListNodeTest01();


	return 0;
}