#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
/*
    Ѱ��������м�ڵ�
    ��Ŀԭ�⣺ https://leetcode.cn/problems/middle-of-the-linked-list/description/
    ���㵥�����ͷ��� head �������ҳ�������������м��㡣
    ����������м��㣬�򷵻صڶ����м��㡣

���룺head = [1,2,3,4,5]
�����[3,4,5]
���ͣ�����ֻ��һ���м��㣬ֵΪ 3 ��

���룺head = [1,2,3,4,5,6]
�����[4,5,6]
���ͣ��������������м��㣬ֵ�ֱ�Ϊ 3 �� 4 �����صڶ�����㡣
*/
 struct ListNode {
    int val;
    struct ListNode* next;
    
};

typedef struct ListNode ListNode;
//��������:����������������cnt��cnt/=2�����м�ڵ�

struct ListNode* middleNode1(struct ListNode* head) {
    int cnt = 0;
    ListNode* prev = head;
    if (!(head->next)) {
        return head;
    }
    while (prev) {
        prev = prev->next;
        cnt++;
    }
    if (cnt / 2 != 0) {
        cnt /= 2;
        prev = head;
        for (int i = 0;i < cnt;i++) {
            prev = prev->next;
        }
    }
    else {
        cnt /= 2;
        prev = head;
        for (int i = 0;i <= cnt;i++) {
            prev = prev->next;
        }
    }

    return prev;
}

//������������ָ��
struct ListNode* middleNode1(struct ListNode* head) {
    ListNode* fast, * slow;
    fast = slow = head;
    //2*slow=fast;
    while (fast&&fast->next)
    {
        slow = slow->next;//��һ��
        fast = fast->next->next;//������
    }
    return slow;
}