#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。



示例 1：

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int l1, l2, l3;
	l1 = m - 1;
	l2 = n - 1;
	l3 = m + n - 1;
	while (l1>=0&&l2>=0)
	{
		if (nums1[l1] < nums2[l2]) {
			nums1[l3--] = nums2[l2--];
		}
		else
		{
			nums1[l3--] = nums1[l1--];
		}
	}
	while (l2>=0)
	{
		nums1[l3--] = nums2[l2--];
	}
}
/*
解释:
先定义l1,l2,l3三个变量
l1:为nums1数组的有效位的最高位
l2:为nums2数组的有效位的最高位
l3:为nums1数组的最高位

接着写一个while循环,用来判断l2与l1是否都>=0 用来判断还能不能进行存放数据
	当nums1[l1] < nums2[l2] 及l1的最高位数据小于l2的最高位数据

				 l1	   l3
	nums1 = [1,2,3,0,0,0]
				 
				 l2
	nums2 = [2,5,6]

	nums1[l3--] = nums2[l2--];


			     l1	 l3
	nums1 = [1,2,3,0,0,6]

			   l2
	nums2 = [2,5,6]

	接着继续判断nums1[l1] 是否 < nums2[l2]
	如果条件成立
				l1	 l3
	nums1 = [1,2,3,0,0,6]

			   l2
	nums2 = [2,5,6]


	nums1[l3--] = nums2[l2--];

			    l1 l3
	nums1 = [1,2,3,0,5,6]

			 l2
	nums2 = [2,5,6]
	以此类推
	如果nums1[l1] > nums2[l2] 则相反

	最后出来判读l2是否>=0如果条件为真 表示数组还没放完
	执行接下来的循环 nums1[l3--] = nums2[l2--]; 
	直到l2<0
	https://leetcode.cn/problems/merge-sorted-array/ //具体题目
*/