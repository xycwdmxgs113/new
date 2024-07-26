#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

//	移除指定链表元素
// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
题目原题 https://leetcode.cn/problems/remove-linked-list-elements/description/
*/

 struct ListNode {
	int val;
	struct ListNode* next;	
};

typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val) {
	//重新创建一个空链表
	ListNode* newhead;
	ListNode* newtail;
	newhead = newtail = NULL;
	ListNode* pcur = head;
	while (pcur)
	{
		if (pcur->val != val) {
			//判断链表是否为空
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