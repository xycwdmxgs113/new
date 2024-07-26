#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*
 环形链表的约瑟夫问题
 通过环形链表解决约瑟夫问题
 原题: https://www.nowcoder.com/practice/41c399fdb6004b31a6cbb047c641ed8a?tpId=196&tqId=37145&ru=/exam/oj
*/

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;

//创建单链表
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

//创建循环链表
ListNode* creat_CirNode(int n) {
	//先创建首个链表
	ListNode* phead = BuyNode(1);
	ListNode* ptail = phead->next;
	for (int i = 2;i <= n;i++) {
		ptail = BuyNode(i);
		ptail = ptail->next;
	}
	//链接首节点 使成为环链表
	ptail->next = phead;
	return ptail;
}

int ysf(int n, int m) {
	//创建一个环形链表
	ListNode* prev = creat_CirNode(n);
	ListNode* pcur = prev->next;
	int cnt = 1;
	while ((prev!=prev->next))
	{
		if (cnt == m) {
			//进行销毁
			prev->next = pcur->next;
			free(pcur);
			pcur = prev->next;
			cnt = 1;//杀掉后从新计数
		}
		else
		{
			//无事发生开始计数
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