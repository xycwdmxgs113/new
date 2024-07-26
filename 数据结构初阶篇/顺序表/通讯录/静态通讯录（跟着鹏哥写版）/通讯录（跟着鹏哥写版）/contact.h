#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>
/*
实现一个通讯录
人的信息：名字+年龄+性别+电话+地址

要求：实现通讯录的增删查改排序
*/
#define MAX_DATE 100
#define MAX_NMAE 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFULT_SZIE 3
#define INC_SIZE 2
//类型的声明

//人的信息
typedef struct PeoInfo
{
	char name[MAX_NMAE];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


//静态通讯录
//typedef struct Contact
//{
//	PeoInfo date[MAX_DATE];//存放人的信息
//	int count;//记录当前通讯录中实际人的个数
//}Contact;

//动态版本
typedef struct Contact
{
	PeoInfo *date;//存放人的信息
	int count;//记录当前通讯录中实际人的个数
	int capacity;//记录当前通讯录容量
}Contact;


//初始化通讯录
void InitContact(Contact* pc);

//加载通讯录
LondContact(Contact* pc);

//销毁通讯录
void DESContact(Contact* pc);

//增加通讯录
void AddContact(Contact* pc);

//显示通讯录
void ShowContact(const Contact* pc);

//删除指定通讯录指定人的信息
void DelContact(Contact* pc);

//查找通讯录指定人的信息
void SearchContact(const Contact* pc);

//修改通讯录人的信息
void MidContact(Contact* pc);

//排序通讯录
void SortContact(const Contact* pc);

//保存通讯录
void SaveContact(const Contact* pc);