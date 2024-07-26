#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*
LCR 023. 相交链表
给定两个单链表的头节点 headA 和 headB ，请找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
原题为：https://leetcode.cn/problems/3u1WK4/description/
*/

 
struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    ListNode* tailA, * tailB;
    tailA = headA, tailB = headB;
    int lenA, lenB;
    lenA = lenB = 0;

    //如果两个链表相交，那么他们尾结尾必定相同
    while (tailA->next) {
        tailA = tailA->next;
        lenA++;
    }
    while (tailB->next) {
        tailB = tailB->next;
        lenB++;
    }

    //如果A的尾节点！=B 的尾节点则不相交
    if (tailA != tailB)
        return NULL;

    //计算两个节点长度的绝对值
    int gap = abs(lenA - lenB);

    //假设A节点为长节点
    ListNode* longlist = headA, * smalllist = headB;
    if (lenA < lenB)
    {
        //如果判断错误则改为B节点为长节点
        longlist = headB;
        smalllist = headA;
    }
    while (gap--)
    {
        longlist = longlist->next;
    }
    while (longlist != smalllist) {
        longlist = longlist->next;
        smalllist = smalllist->next;
    }
    return smalllist;
}
