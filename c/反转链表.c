#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
/*
��ת����
ԭ�� https://leetcode.cn/problems/UHnkqh/description/
���룺head = [1,2,3,4,5]
�����[5,4,3,2,1]


*/

 struct ListNode {
	int val;
	struct ListNode* next;
	
};


typedef struct ListNode ListNode;

//����һ :�����µ�����ѭ��ͷ��
struct ListNode* reverseList1(struct ListNode* head) {
	ListNode* newhead, * newtail;
	newhead = newtail = NULL;//����������
	ListNode* pcur = head; //��������ԭ����
	while (pcur)
	{
		ListNode* ret = pcur->next; //������ʱָ����������pcur����һ���ڵ�
		if (!newhead) {//��û������Ϊ��
			newhead = newtail = pcur;
			newtail->next = NULL;
		}
		else
		{
			pcur->next = newhead;
			newhead = pcur;
		}
		pcur = ret;
	}
	return newhead;
}

//������:��������ָ�����
struct ListNode* reverseList2(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	ListNode* n1, * n2, * n3;
	n1 = NULL, n2 = head, n3 = n2->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}