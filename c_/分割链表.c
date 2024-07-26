#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
/*
分割链表	
原题 ：https://leetcode.cn/problems/partition-list-lcci/description/
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
示例1：
输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：

输入：head = [2,1], x = 2
输出：[1,2]
*/

struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
	if (!head)
		return head;
	//创建大小链表
	ListNode* lessHead, * lessTail;
	ListNode* greaterHead, * greaterTail;
	lessHead = lessTail = (ListNode*)malloc(sizeof(ListNode)); //小链表
	greaterHead=greaterTail= (ListNode*)malloc(sizeof(ListNode));//大链表

	//遍历源链表
	ListNode* pcur = head;
	while (pcur)
	{
		if (pcur->val < x)
		{
			//插入小链表
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

	//将大链表的尾节点初始化为NULL，防止死循环
	greaterTail->next = NULL;
	
	//进行首尾相连
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