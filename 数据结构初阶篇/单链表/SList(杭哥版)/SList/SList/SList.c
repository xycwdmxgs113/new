#include"SList.h"

void SLPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

SLTNode* BuyNode(SLTDataTpye x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode) {
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//尾插链表
void SLPushBack(SLTNode** pphead, SLTDataTpye x) {
	assert(pphead);
	SLTNode* ptail = *pphead;
	SLTNode* newnode = BuyNode(x);
	if (!*pphead)
	{
		*pphead = newnode;
	}
	else
	{
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}

void SLPushFront(SLTNode** phead, SLTDataTpye x) {
	assert(phead);
	SLTNode* newnode = BuyNode(x);
	newnode->next = *phead;
	*phead = newnode;

}

//链表尾删
void SLPopBack(SLTNode** phead) {
	assert(*phead&&phead);
	if ((*phead)->next == NULL) {
		free(*phead);
		*phead = NULL;
	}
	else
	{
		SLTNode* prev, * pcur;
		prev = NULL,pcur = *phead;
		while (pcur->next)
		{
			prev = pcur;
			pcur = pcur->next;
		}
		free(pcur);	
		prev->next = NULL;
	}
}

//链表头删
void SLPopFront(SLTNode** phead) {
	assert(*phead);
	SLTNode* pcur = (*phead)->next;
	free(*phead);
	*phead = pcur;
}

//单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataTpye x) {
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;
}
//pos之前插入
void SListInsert(SLTNode** phead, SLTNode* pos, SLTDataTpye x){
	assert(pos&&phead);
	if (*phead==pos) {
		SLPushFront(phead, x);
	}
	else
	{
		SLTNode* newnode = BuyNode(x);
		SLTNode* pcur = *phead;
		while (pcur->next!=pos)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
		newnode->next = pos;
	}
}
//pos位置删除
void SListErase(SLTNode** phead, SLTNode* pos) {
	assert(pos && phead);
	if (pos == *phead) {
		SLPopFront(phead);
	}
	else
	{
		SLTNode* pcur = *phead;
		while (pcur->next!=pos)
		{
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}

}
//pos之后插入
void SListInsertAfter(SLTNode* pos, SLTDataTpye x) {
	assert(pos);
	SLTNode* newnode = BuyNode(x);
	SLTNode* pcur = pos->next;
	pos->next = newnode;
	newnode->next = pcur;
}
//pos位置后面删除
void SListEraseAfter(SLTNode* pos) {
	assert(pos && pos->next !=NULL);
	SLTNode* pcur = pos->next->next;
	free(pos->next);
	pos->next = pcur;
}

void SLTDestroy(SLTNode** pphead) {
	assert(pphead && *pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}