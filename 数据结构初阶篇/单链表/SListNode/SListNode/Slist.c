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

//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
		SLTNode* newnode = SLTBuyNode(x);
	//��������ǿ������������
	if (!*pphead) {

		*pphead = newnode;
	}
	else
	{
		//��β
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		//ptialָ��ľ���β�ڵ�
		ptail->next = newnode;
	}
}

//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x); 
	newnode->next = *pphead;
	*pphead = newnode;

}

//βɾ
void SLTPopBack(SLTNode** pphead) {
	//	assert(*pphead);������Ϊ�գ���Ȼɾ˭
	assert(pphead&&*pphead);
	//���������:ֻ��һ��������������
	if ((*pphead)->next == NULL) { //  ->�����ȼ�����*
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

//ͷɾ
void SLTPopFront(SLTNode** pphead) {
	assert(pphead && *pphead);
	SLTNode* ptail = (*pphead)->next;
	free(*pphead);
	*pphead = ptail;
}

//����
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

//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead && *pphead);
	assert(pos);

	//��pos==*pphead��ʾͷ��
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

//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(*pphead && pphead);
	assert(pos);
	//pos��ͷ�ڵ��Լ�pos����ͷ�ڵ�
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

//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos) {
	assert(pos&&pos->next);
	SLTNode* ret = pos->next;
	//pos del del->next
	pos->next = ret->next;
	free(ret);
	ret = NULL;
}

//��������
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