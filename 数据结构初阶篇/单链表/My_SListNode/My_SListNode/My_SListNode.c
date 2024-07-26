#include"My_SListNode.h"

void SLTPrint(const SLTNode *pphead) {
	while (pphead)
	{
		printf("%d->", pphead->n);
		pphead = pphead->next;
	}
	printf("NULL\n");
}


//添加一个链表函数
SLTNode* SLTBuyNode(SLTDataType x) {
	SLTNode* ret = (SLTNode*)malloc(sizeof(SLTNode));//申请大小为一个链表的字节数据
	if (!ret) {
		perror("malloc fail");
		exit(1);
	}
	ret->n = x;
	ret->next = NULL;
	return ret;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newNode = SLTBuyNode(x);
	if ((*pphead) == NULL) { //表示此时链表为空链表
		*pphead = newNode;
	}
	else
	{
		SLTNode* ptail = *pphead;
		while (ptail->next)//寻找尾链表
		{
			ptail = ptail->next;
		}
		ptail->next = newNode;
	}
}

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newNode = SLTBuyNode(x);
	newNode->next = *pphead;
	(*pphead) = newNode;
}

//尾删
void SLTPopBack(SLTNode** pphead) {
	assert(pphead && *pphead);
	//分类讨论 单链表删除与多链表删除
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = *pphead; //找最后一个节点的上一个节点
		SLTNode* ptail = *pphead; //找最后一个节点
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = ptail;
	}
}
//链表头删
void SLTPopFront(SLTNode** pphead) {
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//查找
SLTNode* SLTFind(SLTNode* pphead, SLTDataType x) {
	assert(pphead);
	SLTNode *ret = pphead;
	while (ret)
	{
		if ((ret->n) == x) {
			return ret;
		}
		ret = ret->next;
	}
	return NULL;
}

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead && *pphead);
	assert(pos);
	//分两种情况,在头部插入与后面插入
	if (*pphead==pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		SLTNode* prev = *pphead;
		while (prev->next!=pos)//寻找要插入节点的上一个节点
		{
			prev = prev->next;
		}
		//prev->newnode->pos
		newnode->next = prev->next;
		prev->next = newnode;
	}
}

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead && *pphead);
	assert(pos);
	//分类讨论,当只有一个节点与多个节点
	if (*pphead == pos) {//头删
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* pur = *pphead;
		while (pur->next!=pos)
		{
			pur = pur->next;
		}
		pur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos) {
	assert(pos&&pos->next);
	SLTNode* ret = pos->next;
	pos->next = ret->next;
	free(ret);
	ret = NULL;
}

//销毁链表
void SListDesTroy(SLTNode** pphead) {
	assert(pphead && *pphead);
	SLTNode* ret = *pphead;
	while (ret)
	{
		SLTNode* next = ret->next;
		free(ret);
		ret = next;
	}
	*pphead = NULL;
}

