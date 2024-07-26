#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*
随机链表的复制
https://leetcode.cn/problems/copy-list-with-random-pointer/description/
*/



struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};
 

typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
    Node* pcur = head;
    //将每一个拷贝节点复制到源节点后面
    while (pcur) {
        Node* next = pcur->next;
        Node* copy = (Node*)malloc(sizeof(Node));
        pcur->next = copy;
        copy->next = next;
        copy->val = pcur->val;
        pcur = next;
    }

    //修改复制节点中random的指向
    pcur = head;
    while (pcur && pcur->next) {
        Node* copy = pcur->next;
        if (pcur->random == NULL) {
            copy->random = NULL;
        }
        else {
            copy->random = pcur->random->next;//拷贝节点的random==源节点的random->next节点
        }
        pcur = pcur->next->next;
    }

    //将所有插入的拷贝节点解出来，形成新链表,并还原源链表
    pcur = head;
    Node* newnodehead, * newnodetail;
    newnodehead = newnodetail = NULL;
    while (pcur) {
        Node* copy = pcur->next;
        Node* next = copy->next;
        if (newnodehead == NULL) {
            newnodehead = newnodetail = copy;
        }
        else {
            newnodetail->next = copy;
            newnodetail = newnodetail->next;
        }
        pcur->next = next;
        pcur = next;
    }
    return newnodehead;
}
