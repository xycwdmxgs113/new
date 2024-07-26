#include"List.h"

bool LTEmpty(LTNode* phead) {
	assert(phead);
	return phead->next == phead; //为真返回1，为假返回0 
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (!newnode) {
		perror("malloc fali");
		exit(1);
	}
	newnode->data = x;
	newnode->next = newnode->prev = newnode;
	return newnode;
}

LTNode* LTInit() {
	LTNode* phead = BuyListNode(-1);
	return phead;
}

void LTPrint(LTNode* phead) {
	assert(phead);
	LTNode* cur = phead->next;
	printf("head<=>");
	while (cur!=phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LTDestory(LTNode* phead) {
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyListNode(x);
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;
}
void LTPopBack(LTNode* phead) {
	assert(phead);
	assert(!LTEmpty(phead));
	LTNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	tail = NULL;
}
void LTPushFront(LTNode* phead, LTDataType x) {
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//newnode->next = phead->next;
	//newnode->prev = phead;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	LTInsert(phead->next, x);
}
void LTPopFront(LTNode* phead) {
	assert(phead);
	assert(!LTEmpty(phead));
	LTNode* first = phead->next;
	phead->next = first->next;
	first->next->prev = phead;
	free(first);
	first = NULL;
}

LTNode* Find(LTNode* phead, LTDataType x) {
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data == x)
			return cur;
	}
	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x) {
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	newnode->prev = pos->prev;
	newnode->next = pos;
	pos->prev->next = newnode;
	pos->prev = newnode;
}

void LTErase(LTNode* pos) {
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}