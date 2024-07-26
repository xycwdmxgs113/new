#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*

给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。

示例 1：

输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
示例 2：

输入：nums = [-1,0]
输出：[-1,0]
示例 3：

输入：nums = [0,1]
输出：[1,0]
 */

//暴力求解算法
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int* b = (int*)malloc(numsSize * sizeof(int));  // 动态分配内存
    int k = 0;
    int num = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j] && i != j) {
                num++;
                break;
            }
        }
        if (num == 0) {  // 不重复的数字
            b[k] = nums[i];
            k++;
        }
        num = 0;
    }

    *returnSize = k;  // 将数组长度赋值给 *returnSize
    return b;
}


//异或算法
void  find_single_dog(int nums[], int sz, int* p1, int* p2) {
    int i = 0;
    int ret = 0;
    //1 异或
    for (int i = 0;i < sz;i++) {
        ret ^= nums[i];
        //1,2,3,4,5,1,2,3,4,6
    }
    //计算ret中的二进制左右边的第几位是1 
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
    暴力求解算法
     int* size = NULL;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int* p = singleNumber(nums, numsSize, &numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", p[i]);
    }
    free(p);  // 释放动态分配的数组内存
 */ 
    /*
        异或算法
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