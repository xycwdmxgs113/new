#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
/*
    寻找链表的中间节点
    题目原题： https://leetcode.cn/problems/middle-of-the-linked-list/description/
    给你单链表的头结点 head ，请你找出并返回链表的中间结点。
    如果有两个中间结点，则返回第二个中间结点。

输入：head = [1,2,3,4,5]
输出：[3,4,5]
解释：链表只有一个中间结点，值为 3 。

输入：head = [1,2,3,4,5,6]
输出：[4,5,6]
解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。
*/
 struct ListNode {
    int val;
    struct ListNode* next;
    
};

typedef struct ListNode ListNode;
//基础方法:遍历整个链表并计数cnt，cnt/=2就是中间节点

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

//方法二：快慢指针
struct ListNode* middleNode1(struct ListNode* head) {
    ListNode* fast, * slow;
    fast = slow = head;
    //2*slow=fast;
    while (fast&&fast->next)
    {
        slow = slow->next;//走一步
        fast = fast->next->next;//走两步
    }
    return slow;
}