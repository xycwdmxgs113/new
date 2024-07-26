#include"Queue.h"
void QInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;

}

void QDestroy(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QPush(Queue* pq, QDataType x) {
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode) {
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	if (!pq->head) {
		assert(!pq->tail);
		pq->head = pq->tail = newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

void QPop(Queue* pq) {
	assert(pq&&pq->head);
	assert(pq->size);
	if (!pq->head->next)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* cur = pq->head->next;
		free(pq->head);
		pq->head = cur;
	}
	pq->size--;
}

int  QSize(Queue* pq) {
	assert(pq);
	return pq->size;
}

bool QEmpty(Queue* pq) {
	assert(pq);
	return pq->size == 0;
}

QDataType QFront(Queue* pq) {
	assert(pq);
	assert(!QEmpty(pq));
	return pq->head->data;
}

QDataType QBack(Queue* pq) {
	assert(pq);
	assert(!QEmpty(pq));
	return pq->tail->data;
}