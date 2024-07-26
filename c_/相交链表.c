#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*
LCR 023. �ཻ����
���������������ͷ�ڵ� headA �� headB �����ҳ������������������ཻ����ʼ�ڵ㡣�����������û�н��㣬���� null ��
ԭ��Ϊ��https://leetcode.cn/problems/3u1WK4/description/
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

    //������������ཻ����ô����β��β�ض���ͬ
    while (tailA->next) {
        tailA = tailA->next;
        lenA++;
    }
    while (tailB->next) {
        tailB = tailB->next;
        lenB++;
    }

    //���A��β�ڵ㣡=B ��β�ڵ����ཻ
    if (tailA != tailB)
        return NULL;

    //���������ڵ㳤�ȵľ���ֵ
    int gap = abs(lenA - lenB);

    //����A�ڵ�Ϊ���ڵ�
    ListNode* longlist = headA, * smalllist = headB;
    if (lenA < lenB)
    {
        //����жϴ������ΪB�ڵ�Ϊ���ڵ�
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
