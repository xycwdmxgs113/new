#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 13
#define MAX_ARR 20
#define DEFAULT 3
#define INT_ADD 2


typedef struct Stu
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tel[MAX_TEL];
	char arr[MAX_ARR];
}Stu;


typedef struct Contact
{
	Stu* p;
	int cnt;//记录人数
	int capacity; //记录容量


}Contact;


void Initial(Contact* con);//初始化结构体

void InCrease(Contact* con); //增加人员变量

void Reduce(Contact* con);//减少人员变量

void rewrite(Contact* con);//改写人员信息

void search(const Contact* con); //查找人员信息

void Look(const Contact* con); //显示所有人员信息

void sort(Contact* con);//排序人员信息

void Record(const Contact* con); //记录人员信息

void Free(Contact* con);//释放内存

