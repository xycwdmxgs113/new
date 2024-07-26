#include"My_List.h"


void LTPrint(ListNode* phead) {
	ListNode* pcur = phead->next;
	while (pcur!=phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

//查找节点
ListNode* Find(ListNode* phead, ListNodeDataType x) {
	assert(phead);
	ListNode* pcur = phead->next;
	while (pcur!=phead)
	{
		if (pcur->data == x)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

//申请链表
ListNode* BuyNode(ListNodeDataType x) {
	ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
	if (!ret) {
		perror("malloc error");
		exit(1);
	}
	ret->prev=ret->next = ret;
	ret->data = x;
	return ret;
}

//初始化链表
ListNode* LTInit
() {
	ListNode* plist = BuyNode(-1);
	return plist;
}

//尾插
void LTPushBack(ListNode* phead, ListNodeDataType x) {
	assert(phead);
	ListNode* newnode = BuyNode(x);
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;

}

//头插
void LTPushFront(ListNode* phead, ListNodeDataType x) {
	assert(phead);
	ListNode* newnode = BuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

//尾巴删
void LTPopBack(ListNode* phead) {
	assert(phead && phead->next != phead);
	ListNode* ret = phead->next;
	phead->next = ret->next;
	ret->next->prev = phead;
	free(ret);
	ret = NULL;
}

//头删
void LTPopFront(ListNode* phead) {
	assert(phead && phead->next != phead);
	ListNode* ret = phead->prev;
	phead->prev = phead->prev->prev;
	phead->prev->prev->next = phead;
	free(ret);
	ret = NULL;
}

//在pos后插入数据
void LTInsert(ListNode* pos, ListNodeDataType x) {
	assert(pos);
	ListNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

//删除pos位置数据
void LTErase(ListNode* pos) {
	assert(pos && pos->next != pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

//销毁链表
void LTDisTroy(ListNode* phead) {
	ListNode* pcur = phead->next;
	while (pcur!=phead)
	{
		ListNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(pcur);
}