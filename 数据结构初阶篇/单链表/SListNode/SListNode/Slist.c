#include"Slist.h"

void SLTPrint(SLTNode* phead) {
	SLTNode* pur = phead;
	while (pur)
	{
		printf("%d->", pur->data);
		pur = pur->next;
	}
	printf("NULL\n");
}

SLTNode* SLTBuyNode(SLTDataType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode) {
		perror("malloc error");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
		SLTNode* newnode = SLTBuyNode(x);
	//空链表与非空链表两种情况
	if (!*pphead) {

		*pphead = newnode;
	}
	else
	{
		//找尾
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		//ptial指向的就是尾节点
		ptail->next = newnode;
	}
}

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x); 
	newnode->next = *pphead;
	*pphead = newnode;

}

//尾删
void SLTPopBack(SLTNode** pphead) {
	//	assert(*pphead);链表不能为空，不然删谁
	assert(pphead&&*pphead);
	//分情况处理:只有一个链表与多个链表
	if ((*pphead)->next == NULL) { //  ->的优先级高于*
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

//头删
void SLTPopFront(SLTNode** pphead) {
	assert(pphead && *pphead);
	SLTNode* ptail = (*pphead)->next;
	free(*pphead);
	*pphead = ptail;
}

//查找
SLTNode* SLTFind(SLTNode* pphead, SLTDataType x) {

	SLTNode* ptial = pphead;
	while (ptial)
	{
		if (ptial->data == x) {
			return ptial;
		}
		ptial = ptial->next;
	}
	return NULL;	
}

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead && *pphead);
	assert(pos);

	//若pos==*pphead表示头插
	if (pos == *pphead) {
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode *newnode = SLTBuyNode(x);
		SLTNode* prev = *pphead;
		while (prev->next!=pos)
		{
			prev = prev->next;
		}
		//prev->newnode->pos
		prev->next = newnode;
		newnode->next = pos;
	}
}

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(*pphead && pphead);
	assert(pos);
	//pos是头节点以及pos不是头节点
	if (*pphead == pos) {

		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos) {
	assert(pos&&pos->next);
	SLTNode* ret = pos->next;
	//pos del del->next
	pos->next = ret->next;
	free(ret);
	ret = NULL;
}

//销毁链表
void SListDesTroy(SLTNode** pphead) {
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	SLTNode* next = *pphead;
	while (pcur)
	{
		next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}