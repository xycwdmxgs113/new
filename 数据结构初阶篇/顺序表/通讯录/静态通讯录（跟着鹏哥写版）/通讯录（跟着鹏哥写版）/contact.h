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
ʵ��һ��ͨѶ¼
�˵���Ϣ������+����+�Ա�+�绰+��ַ

Ҫ��ʵ��ͨѶ¼����ɾ�������
*/
#define MAX_DATE 100
#define MAX_NMAE 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFULT_SZIE 3
#define INC_SIZE 2
//���͵�����

//�˵���Ϣ
typedef struct PeoInfo
{
	char name[MAX_NMAE];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


//��̬ͨѶ¼
//typedef struct Contact
//{
//	PeoInfo date[MAX_DATE];//����˵���Ϣ
//	int count;//��¼��ǰͨѶ¼��ʵ���˵ĸ���
//}Contact;

//��̬�汾
typedef struct Contact
{
	PeoInfo *date;//����˵���Ϣ
	int count;//��¼��ǰͨѶ¼��ʵ���˵ĸ���
	int capacity;//��¼��ǰͨѶ¼����
}Contact;


//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//����ͨѶ¼
LondContact(Contact* pc);

//����ͨѶ¼
void DESContact(Contact* pc);

//����ͨѶ¼
void AddContact(Contact* pc);

//��ʾͨѶ¼
void ShowContact(const Contact* pc);

//ɾ��ָ��ͨѶ¼ָ���˵���Ϣ
void DelContact(Contact* pc);

//����ͨѶ¼ָ���˵���Ϣ
void SearchContact(const Contact* pc);

//�޸�ͨѶ¼�˵���Ϣ
void MidContact(Contact* pc);

//����ͨѶ¼
void SortContact(const Contact* pc);

//����ͨѶ¼
void SaveContact(const Contact* pc);