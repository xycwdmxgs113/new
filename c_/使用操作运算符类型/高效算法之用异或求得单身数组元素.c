#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*

����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�����԰� ����˳�� ���ش𰸡�

�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨�ҽ�ʹ�ó�������ռ�����������⡣

ʾ�� 1��

���룺nums = [1,2,1,3,2,5]
�����[3,5]
���ͣ�[5, 3] Ҳ����Ч�Ĵ𰸡�
ʾ�� 2��

���룺nums = [-1,0]
�����[-1,0]
ʾ�� 3��

���룺nums = [0,1]
�����[1,0]
 */

//��������㷨
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int* b = (int*)malloc(numsSize * sizeof(int));  // ��̬�����ڴ�
    int k = 0;
    int num = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j] && i != j) {
                num++;
                break;
            }
        }
        if (num == 0) {  // ���ظ�������
            b[k] = nums[i];
            k++;
        }
        num = 0;
    }

    *returnSize = k;  // �����鳤�ȸ�ֵ�� *returnSize
    return b;
}


//����㷨
void  find_single_dog(int nums[], int sz, int* p1, int* p2) {
    int i = 0;
    int ret = 0;
    //1 ���
    for (int i = 0;i < sz;i++) {
        ret ^= nums[i];
        //1,2,3,4,5,1,2,3,4,6
    }
    //����ret�еĶ��������ұߵĵڼ�λ��1 
    int pos = 0;
    for (pos = 0;pos < 32;pos++) {
        if (((ret >> pos) & 1) == 1) {
            break;
        }
    }

    for (i = 0;i < sz;i++) {
        if (((nums[i] >> pos) & 1) == 1){
            *p1 ^= nums[i];
        }
        else
        {
            *p2 ^= nums[i];
        }
    }
}

int main() {
    int nums[] = {1,2,3,4,5,1,2,3,4,6};
/*
    ��������㷨
     int* size = NULL;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int* p = singleNumber(nums, numsSize, &numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", p[i]);
    }
    free(p);  // �ͷŶ�̬����������ڴ�
 */ 
    /*
        ����㷨
       A: 1 1 3 3 5
       B: 2 2 4 4 6
       5:101
       6:110
       ^:011
    */
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int dog1 = 0;
    int dog2 = 0;
    find_single_dog(nums, numsSize, &dog1, &dog2);
    printf("%d %d", dog1, dog2);
    return 0;
}