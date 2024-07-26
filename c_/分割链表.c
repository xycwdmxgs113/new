#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
/*
�ָ�����	
ԭ�� ��https://leetcode.cn/problems/partition-list-lcci/description/
����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
ʾ��1��
���룺head = [1,4,3,2,5,2], x = 3
�����[1,2,2,4,3,5]
ʾ�� 2��

���룺head = [2,1], x = 2
�����[1,2]
*/

struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
	if (!head)
		return head;
	//������С����
	ListNode* lessHead, * lessTail;
	ListNode* greaterHead, * greaterTail;
	lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode)); //С����
	greaterHead=greaterTail= (ListNode*)malloc(sizeof(ListNode));//������

	//����Դ����
	ListNode* pcur = head;
	while (pcur)
	{
		if (pcur->val < x)
		{
			//����С����
			lessTail->next = pcur;
			lessTail = lessTail->next;
		}
		else
		{
			greaterTail->next = pcur;
			greaterTail = greaterTail->next;
		}
		pcur = pcur->next;
	}

	//���������β�ڵ��ʼ��ΪNULL����ֹ��ѭ��
	greaterTail->next = NULL;
	
	//������β����
	lessTail->next = greaterHead->next;
	ListNode* ret = lessHead->next;
	free(lessHead);
	free(greaterHead);
	lessHead = greaterHead = NULL;
	return ret;
}
int main() {




	return 0;
}