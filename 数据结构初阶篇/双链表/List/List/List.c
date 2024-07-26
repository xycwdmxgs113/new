#include"List.h"

void LTPrint(LTNode* phead) {
	LTNode* pcur = phead->next;
	while (pcur!=phead)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

//申请节点
LTNode* LTBuyNode(LTDataType x) {
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (!node) {
		perror("malloc error");
		exit(1);
	}
	node->data = x;
	node->next =node;
	node->prev =node;
	return node;
}
//初始化
//void LTInit(LTNode** pphead) {
//	//给双向链表创建一个哨兵位
//	*pphead = LTBuyNode(-1);
//}
LTNode* LTInit() {
	LTNode*phead = LTBuyNode(-1);
	return phead;
}


//尾插
void LTPushBack(LTNode* phead, LTDataType x) {
	assert(phead);
	LTNode* newnode = LTBuyNode(x);  
	
	//phead,phead->prev.newnode
	newnode->prev = phead->prev; 
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode; 
}

//头插
void LTPushFront(LTNode* phead, LTDataType x) {

	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->next 
	newnode->next = phead->next;
	newnode->prev = phead;
	//phead->	next->prev = newnode;
	phead->next = newnode;
	newnode->next->prev = newnode;
}

//尾删
void LTPopBack(LTNode* phead) {
	assert(phead&&phead->next!=phead);
	LTNode* ret = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(ret);
	ret = NULL;
}

//头删
void LTPopFront(LTNode* phead) {
	assert(phead && phead->next != phead);
	LTNode* ret = phead->next;
	phead->next = ret->next;
	ret->next->prev = phead;
	free(ret);
	ret = NULL;
}

//查找pos位置数据
LTNode* Find(LTNode* phead, LTDataType x) {
	LTNode* pcur = phead->next;
	while (pcur!=phead)
	{
		if (pcur->data == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	//没有找到
	return NULL;
}

//在pos后插入数据
void LTInsert(LTNode* pos, LTDataType x) {
	assert(pos);
		LTNode* newnode = LTBuyNode(x);

		newnode->prev = pos;
		newnode->next = pos->next;
		pos->next->prev = newnode; 
		pos->next = newnode;
}

//删除pos位置数据
void LTErase(LTNode* pos) {
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

//销毁链表
void LTDisTroy(LTNode* phead) {
	assert(phead);
	LTNode* pcur = phead->next;

	while (pcur!=phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//此时pcur指向phead；
	free(phead);
	phead == NULL;
}