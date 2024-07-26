#pragma once
#include<stdio.h>
#include<stdlib.h>

void PrintArray(int* a, int n);

// ²åÈëÅÅĞò
void InsertSort(int* a, int n);

// Ï£¶ûÅÅĞò
void ShellSort(int* a, int n);
// Ñ¡ÔñÅÅĞò
void SelectSort(int* a, int n);


// ¶ÑÅÅĞò
void AdjustDwon(int* a, int n, int parent);
void HeapSort(int* a, int n);


//¿ìËÙÅÅĞò
void QuickSort(int* a, int left, int right);
