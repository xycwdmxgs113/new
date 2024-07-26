#include"Slist.h"




void SListTest02() {
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	//≤‚ ‘≤È’“
	SLTNode* ret = SLTFind(plist,3);
	SLTEraseAfter(ret);
	SLTPrint(plist);
	//if (!ret) {
	//	printf("NO FIND\n");
	//}
	//else
	//{
	//	printf("’“µΩ¡ÀOvO\n");
	//}

	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//
	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);



}

int main() {
	SListTest02();

	return 0;
 }