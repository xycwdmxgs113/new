#pragma once
#include<stdio.h>
#include<stdlib.h>

void PrintArray(int* a, int n);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);


// ������
void AdjustDwon(int* a, int n, int parent);
void HeapSort(int* a, int n);


//��������
void QuickSort(int* a, int left, int right);
