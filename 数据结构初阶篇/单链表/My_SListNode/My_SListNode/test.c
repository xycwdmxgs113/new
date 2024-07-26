#include"My_SListNode.h"

void SLTNodeTest01() {
	SLTNode* p = NULL;
	SLTPushBack(&p, 1);
	SLTPushBack(&p, 2);
	SLTPushBack(&p, 3);
	SLTPushBack(&p, 4);
	SLTPrint(p);
	//SLTNode* ret = SLTFind(p, 3);
	//SLTEraseAfter(ret);
	//SLTPrint(p);
	SListDesTroy(&p);
	SLTPrint(p);
}


int main() {
	SLTNodeTest01();


	return 0;
}