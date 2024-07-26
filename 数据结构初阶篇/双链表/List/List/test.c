#include"List.h"

void ListTest01() {
	/*LTNode* plist = NULL;*/
	LTNode* plist = LTInit();
	LTInit(&plist);
	LTPushBack(plist, 1);
	LTPrint(plist);
	LTPushBack(plist, 2);
	LTPrint(plist);
	LTPushBack(plist, 3);
	LTPrint(plist);

	LTNode* ret=Find(plist, 2);
	LTErase(ret);
	ret=NULL;
	LTPrint(plist);
	plist = NULL;
}

int main() {
	ListTest01();

	return 0;
}