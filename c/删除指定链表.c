#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

//	�Ƴ�ָ������Ԫ��
// ����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
���룺head = [1,2,6,3,4,5,6], val = 6
�����[1,2,3,4,5]
��Ŀԭ�� https://leetcode.cn/problems/remove-linked-list-elements/description/
*/

 struct ListNode {
	int val;
	struct ListNode* next;	
};

typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val) {
	//���´���һ��������
	ListNode* newhead;
	ListNode* newtail;
	newhead = newtail = NULL;
	ListNode* pcur = head;
	while (pcur)
	{
		if (pcur->val != val) {
			//�ж������Ƿ�Ϊ��
			if (!newhead) {
				newhead = newtail = pcur;
			}
			else
			{
				newtail->next = pcur;
				newtail = newtail->next;
			}
		}
		pcur = pcur->next;
	}
	if (newtail)
		newtail->next = NULL;
	return newhead;
}