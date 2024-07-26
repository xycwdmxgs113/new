#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*
�������ĸ���
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
    //��ÿһ�������ڵ㸴�Ƶ�Դ�ڵ����
    while (pcur) {
        Node* next = pcur->next;
        Node* copy = (Node*)malloc(sizeof(Node));
        pcur->next = copy;
        copy->next = next;
        copy->val = pcur->val;
        pcur = next;
    }

    //�޸ĸ��ƽڵ���random��ָ��
    pcur = head;
    while (pcur && pcur->next) {
        Node* copy = pcur->next;
        if (pcur->random == NULL) {
            copy->random = NULL;
        }
        else {
            copy->random = pcur->random->next;//�����ڵ��random==Դ�ڵ��random->next�ڵ�
        }
        pcur = pcur->next->next;
    }

    //�����в���Ŀ����ڵ��������γ�������,����ԭԴ����
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
