#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

/*
���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��

���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�

ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��



ʾ�� 1��

���룺nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
�����[1,2,2,3,5,6]
���ͣ���Ҫ�ϲ� [1,2,3] �� [2,5,6] ��
�ϲ������ [1,2,2,3,5,6] ������б��Ӵֱ�ע��Ϊ nums1 �е�Ԫ�ء�
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
����:
�ȶ���l1,l2,l3��������
l1:Ϊnums1�������Чλ�����λ
l2:Ϊnums2�������Чλ�����λ
l3:Ϊnums1��������λ

����дһ��whileѭ��,�����ж�l2��l1�Ƿ�>=0 �����жϻ��ܲ��ܽ��д������
	��nums1[l1] < nums2[l2] ��l1�����λ����С��l2�����λ����

				 l1	   l3
	nums1 = [1,2,3,0,0,0]
				 
				 l2
	nums2 = [2,5,6]

	nums1[l3--] = nums2[l2--];


			     l1	 l3
	nums1 = [1,2,3,0,0,6]

			   l2
	nums2 = [2,5,6]

	���ż����ж�nums1[l1] �Ƿ� < nums2[l2]
	�����������
				l1	 l3
	nums1 = [1,2,3,0,0,6]

			   l2
	nums2 = [2,5,6]


	nums1[l3--] = nums2[l2--];

			    l1 l3
	nums1 = [1,2,3,0,5,6]

			 l2
	nums2 = [2,5,6]
	�Դ�����
	���nums1[l1] > nums2[l2] ���෴

	�������ж�l2�Ƿ�>=0�������Ϊ�� ��ʾ���黹û����
	ִ�н�������ѭ�� nums1[l3--] = nums2[l2--]; 
	ֱ��l2<0
	https://leetcode.cn/problems/merge-sorted-array/ //������Ŀ
*/