#include"List2.h"

//���뵥����ڵ�
SLTNode* BuySlt(SLTDataType x) {
	SLTNode* ret = (SLTNode*)malloc(sizeof(SLTNode));
	if (!ret) {
		perror("malloc");
		exit(1);
	}
	ret->n = x;
	ret->next = NULL;
	return ret;
}

//��ʼ������
SLTNode* Init(void) {
	SLTNode* newnode = BuySlt(-1);
	return newnode;
}

//��ӡ����
void SLTPrint(const SLTNode* pphead) {
	assert(pphead);
	SLTNode* pcur = pphead->next;
	while (pcur)
	{
		printf("%d->", pcur->n);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//������β��
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead&&*pphead);
	SLTNode* newnode = BuySlt(x);
	if ((*pphead)->next == NULL) {
		(*pphead)->next = newnode;
	}
	else
	{
		SLTNode* pcur = (*pphead)->next;
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}

//ͷ������
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead && *pphead);
	SLTNode* newnode = BuySlt(x);
	if ((*pphead)->next == NULL) {
		(*pphead)->next = newnode;
	}
	else
	{
		newnode->next = (*pphead)->next;
		(*pphead)->next = newnode;
	}
}

//βɾ��
void SLTPopBack(SLTNode** pphead) {
	assert(pphead && (*pphead));
	SLTNode* pcur = (*pphead)->next;
	SLTNode* prev = (*pphead)->next;
	if (!prev->next) {
		free(prev);
		prev = NULL;
		pcur = NULL;
	}
	else
	{
		pcur = pcur->next;
		while (pcur->next)
		{
			prev = prev->next;
			pcur = pcur->next;
		}
		free(pcur);
		pcur = NULL;
		prev->next = pcur;
	}
}

//����ͷɾ
void SLTPopFront(SLTNode** pphead) {
	SLTNode* pcur = (*pphead)->next;
	
	(*pphead)->next = pcur->next;
	free(pcur);
	pcur = NULL;

}

//����
SLTNode* SLTFind(SLTNode* pphead, SLTDataType x) {
	SLTNode* pcur = pphead->next;
	while (pcur)
	{
		if (pcur->n == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	if (!pos->next) {
		SLTPushBack(&pos, x);
	}
	else
	{
		SLTNode* newnode = BuySlt(x);
		newnode->next = pos->next;
		pos->next = newnode;
	}
}

//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pos && pphead);
	if (pos==(*pphead)->next)
	{
		SLTPopFront(pphead);
	}
	else if (pos->next == NULL) {
		SLTPopBack(pphead);
	}
	else
	{
		SLTNode* pcur = (*pphead)->next;
		while (pcur->next!=pos)
		{
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos) {
	assert(pos && pos->next != NULL);
	SLTNode* pcur = pos->next;
	pos->next = pcur->next;
	free(pcur);
	pcur = NULL;
	
}

//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead && pos);
	if ((*pphead)->next == pos)
	{
		SLTPushFront(pphead, x);
	}
	else {
		SLTNode* newnode = BuySlt(x);
		SLTNode* pcur = (*pphead)->next;
		while (pcur->next!=pos)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
		newnode->next = pos;
	}
}

//��������
void SListDesTroy(SLTNode** pphead) {
	SLTNode* pcur = (*pphead)->next;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free((*pphead));
	*pphead = NULL;
}