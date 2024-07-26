#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
/*
反转链表
原题 https://leetcode.cn/problems/UHnkqh/description/
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]


*/

 struct ListNode {
	int val;
	struct ListNode* next;
	
};


typedef struct ListNode ListNode;

//方法一 :创建新的链表，循环头插
struct ListNode* reverseList1(struct ListNode* head) {
	ListNode* newhead, * newtail;
	newhead = newtail = NULL;//创建新链表
	ListNode* pcur = head; //用来遍历原链表
	while (pcur)
	{
		ListNode* ret = pcur->next; //创建临时指针用来保存pcur的下一个节点
		if (!newhead) {//当没有链表为空
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

//方法二:创建三个指针变量
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