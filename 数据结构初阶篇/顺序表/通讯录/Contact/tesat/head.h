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
	int cnt;//��¼����
	int capacity; //��¼����


}Contact;


void Initial(Contact* con);//��ʼ���ṹ��

void InCrease(Contact* con); //������Ա����

void Reduce(Contact* con);//������Ա����

void rewrite(Contact* con);//��д��Ա��Ϣ

void search(const Contact* con); //������Ա��Ϣ

void Look(const Contact* con); //��ʾ������Ա��Ϣ

void sort(Contact* con);//������Ա��Ϣ

void Record(const Contact* con); //��¼��Ա��Ϣ

void Free(Contact* con);//�ͷ��ڴ�

