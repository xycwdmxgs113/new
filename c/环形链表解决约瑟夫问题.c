#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*
 ���������Լɪ������
 ͨ������������Լɪ������
 ԭ��: https://www.nowcoder.com/practice/41c399fdb6004b31a6cbb047c641ed8a?tpId=196&tqId=37145&ru=/exam/oj
*/

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;

//����������
ListNode* BuyNode(int x) {
	ListNode* ret = (ListNode*)malloc(sizeof(ListNode));
	if (!ret) {
		perror("malloc error");
		exit(1);
	}
	ret->next = NULL;
	ret->val = x;
	return ret;
}

//����ѭ������
ListNode* creat_CirNode(int n) {
	//�ȴ����׸�����
	ListNode* phead = BuyNode(1);
	ListNode* ptail = phead->next;
	for (int i = 2;i <= n;i++) {
		ptail = BuyNode(i);
		ptail = ptail->next;
	}
	//�����׽ڵ� ʹ��Ϊ������
	ptail->next = phead;
	return ptail;
}

int ysf(int n, int m) {
	//����һ����������
	ListNode* prev = creat_CirNode(n);
	ListNode* pcur = prev->next;
	int cnt = 1;
	while ((prev!=prev->next))
	{
		if (cnt == m) {
			//��������
			prev->next = pcur->next;
			free(pcur);
			pcur = prev->next;
			cnt = 1;//ɱ������¼���
		}
		else
		{
			//���·�����ʼ����
			prev = prev->next;
			pcur = pcur->next;
			cnt++;
		}
	}
	return prev->val;
}

int main() {




	return 0;
}