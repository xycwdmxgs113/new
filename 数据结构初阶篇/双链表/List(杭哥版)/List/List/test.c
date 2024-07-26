#include"List.h"


void TestList1(void) {
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	
	LTPushFront(plist, 5);
	LTPrint(plist);
	LTPushFront(plist, 6);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);

}

int main() {
	TestList1();
	

	return 0;
}