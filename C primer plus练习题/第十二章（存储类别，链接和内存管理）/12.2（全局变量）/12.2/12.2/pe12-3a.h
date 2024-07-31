#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include<ctype.h>

//用户选择 美国计算还是欧洲计算
int  set_mode(int n);
double get_info1(int flag);
double get_info2(int flag);
void  show_info(double num1,double num2, int flag);

