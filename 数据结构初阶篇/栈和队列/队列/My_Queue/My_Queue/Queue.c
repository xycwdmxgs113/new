#include"Queue.h"

void QInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QDestroy(Queue* pq) {
	assert(pq);
	QueueNode* pcur = pq->head;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->size = 0;
}

void QPush(Queue* pq, QueDataType x) {
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (!newnode) {
		perror("malloc fail");
		exit(1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (!pq->head)
	{
		pq->head = pq->tail = newnode;
	}
	else 
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

bool QEmpty(Queue* pq) {
	assert(pq);
	return pq->size == 0;
}

void QPop(Queue* pq) {
	assert(pq);
	assert(!QEmpty(pq));
	if (!pq->head->next)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;

	}
		pq->size--;
}

int  QSize(Queue* pq) {
	assert(pq);
	return pq->size;
}

QueDataType QFront(Queue* pq) {
	assert(pq);
	return pq->head->val;
}

QueDataType QBack(Queue* pq) {
	assert(pq);
	return pq->tail->val;
}