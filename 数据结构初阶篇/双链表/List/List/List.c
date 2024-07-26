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

//����ڵ�
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
//��ʼ��
//void LTInit(LTNode** pphead) {
//	//��˫��������һ���ڱ�λ
//	*pphead = LTBuyNode(-1);
//}
LTNode* LTInit() {
	LTNode*phead = LTBuyNode(-1);
	return phead;
}


//β��
void LTPushBack(LTNode* phead, LTDataType x) {
	assert(phead);
	LTNode* newnode = LTBuyNode(x);  
	
	//phead,phead->prev.newnode
	newnode->prev = phead->prev; 
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode; 
}

//ͷ��
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

//βɾ
void LTPopBack(LTNode* phead) {
	assert(phead&&phead->next!=phead);
	LTNode* ret = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(ret);
	ret = NULL;
}

//ͷɾ
void LTPopFront(LTNode* phead) {
	assert(phead && phead->next != phead);
	LTNode* ret = phead->next;
	phead->next = ret->next;
	ret->next->prev = phead;
	free(ret);
	ret = NULL;
}

//����posλ������
LTNode* Find(LTNode* phead, LTDataType x) {
	LTNode* pcur = phead->next;
	while (pcur!=phead)
	{
		if (pcur->data == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	//û���ҵ�
	return NULL;
}

//��pos���������
void LTInsert(LTNode* pos, LTDataType x) {
	assert(pos);
		LTNode* newnode = LTBuyNode(x);

		newnode->prev = pos;
		newnode->next = pos->next;
		pos->next->prev = newnode; 
		pos->next = newnode;
}

//ɾ��posλ������
void LTErase(LTNode* pos) {
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

//��������
void LTDisTroy(LTNode* phead) {
	assert(phead);
	LTNode* pcur = phead->next;

	while (pcur!=phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	//��ʱpcurָ��phead��
	free(phead);
	phead == NULL;
}