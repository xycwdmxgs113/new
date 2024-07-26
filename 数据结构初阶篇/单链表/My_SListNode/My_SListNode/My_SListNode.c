#include"My_SListNode.h"

void SLTPrint(const SLTNode *pphead) {
	while (pphead)
	{
		printf("%d->", pphead->n);
		pphead = pphead->next;
	}
	printf("NULL\n");
}


//���һ��������
SLTNode* SLTBuyNode(SLTDataType x) {
	SLTNode* ret = (SLTNode*)malloc(sizeof(SLTNode));//�����СΪһ��������ֽ�����
	if (!ret) {
		perror("malloc fail");
		exit(1);
	}
	ret->n = x;
	ret->next = NULL;
	return ret;
}

//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newNode = SLTBuyNode(x);
	if ((*pphead) == NULL) { //��ʾ��ʱ����Ϊ������
		*pphead = newNode;
	}
	else
	{
		SLTNode* ptail = *pphead;
		while (ptail->next)//Ѱ��β����
		{
			ptail = ptail->next;
		}
		ptail->next = newNode;
	}
}

//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newNode = SLTBuyNode(x);
	newNode->next = *pphead;
	(*pphead) = newNode;
}

//βɾ
void SLTPopBack(SLTNode** pphead) {
	assert(pphead && *pphead);
	//�������� ������ɾ���������ɾ��
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = *pphead; //�����һ���ڵ����һ���ڵ�
		SLTNode* ptail = *pphead; //�����һ���ڵ�
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
//����ͷɾ
void SLTPopFront(SLTNode** pphead) {
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//����
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

//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead && *pphead);
	assert(pos);
	//���������,��ͷ��������������
	if (*pphead==pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		SLTNode* prev = *pphead;
		while (prev->next!=pos)//Ѱ��Ҫ����ڵ����һ���ڵ�
		{
			prev = prev->next;
		}
		//prev->newnode->pos
		newnode->next = prev->next;
		prev->next = newnode;
	}
}

//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead && *pphead);
	assert(pos);
	//��������,��ֻ��һ���ڵ������ڵ�
	if (*pphead == pos) {//ͷɾ
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

//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos) {
	assert(pos&&pos->next);
	SLTNode* ret = pos->next;
	pos->next = ret->next;
	free(ret);
	ret = NULL;
}

//��������
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

