#include"contact.h"


//��̬�汾
//void InitContact(Contact* pc) {
//	assert(pc);
//	pc->count = 0;
//	memset(pc->date, 0, sizeof(pc->date));
//}


//��̬�汾

void check(Contact* pc) {
	if (pc->count == pc->capacity) {
		PeoInfo* ret = (PeoInfo*)realloc(pc->date, (pc->capacity + INC_SIZE) * sizeof(PeoInfo));
		if (ret == NULL) {
			printf("AddContact::%s", strerror(errno));
		}
		else
		{
			pc->date = ret;
			pc->capacity += INC_SIZE;
		}
	}
}


//��̬�汾��ʼ��
void InitContact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	pc->date=(PeoInfo*)calloc(DEFULT_SZIE, sizeof(PeoInfo));
	if (pc->date == NULL) {
		printf("InitContact::%s", strerror(errno));
		return;
	}
	pc->capacity = DEFULT_SZIE;
	//��ʼ��ͨѶ¼
	LondContact(pc);
}

LondContact(Contact* pc) {
	FILE* pfread = fopen("Contact.txt", "rb");
	if (pfread==NULL)
	{
		perror(LondContact);
		return;
	}

	PeoInfo tmp = { 0 };
	while (fread(&tmp,sizeof(PeoInfo),1,pfread)==1)
	{
		check(pc);
		pc->date[pc->count] = tmp;
		pc->count++;
	}

	fclose(pfread);
	pfread == NULL;
}


void DESContact(Contact* pc) {
	free(pc->date);
	pc->date = NULL;
}

//��̬�汾����
//void AddContact(Contact* pc) {
//	assert(pc);
//	if (pc->count == MAX_DATE) {
//		printf("ͨѶ¼�������޷����\n");
//		return;	
//	}
//	printf("����������;>");
//	scanf("%s", pc->date[pc->count].name);
//	printf("����������;>");
//	scanf("%d", &(pc->date[pc->count].age));
//	printf("�������Ա�:>");
//	scanf("%s", pc->date[pc->count].sex);
//	printf("������绰;>");
//	scanf("%s", pc->date[pc->count].tele);
//	printf("�������ַ:>");
//	scanf("%s", pc->date[pc->count].addr);
//	pc->count++;
//	printf("���ӳɹ�\n");
//}


void AddContact(Contact* pc) {
	assert(pc);
	if (pc->count == MAX_DATE) {
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	check(pc);
	printf("����������;>");
	scanf("%s", pc->date[pc->count].name);
	printf("����������;>");
	scanf("%d", &(pc->date[pc->count].age));
	printf("�������Ա�:>");
	scanf("%s", pc->date[pc->count].sex);
	printf("������绰;>");
	scanf("%s", pc->date[pc->count].tele);
	printf("�������ַ:>");
	scanf("%s", pc->date[pc->count].addr);
	pc->count++;
	printf("���ӳɹ�\n");
}


void ShowContact(const Contact* pc) {
	assert(pc);
	int i;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "סַ");
	for (i = 0;i < pc->count;i++) {
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->date[i].name,
												    pc->date[i].age,
													pc->date[i].sex,
													pc->date[i].tele,
													pc->date[i].addr);
	}
}

static int FindByName(const Contact* pc, char* name) {
	int i;
	for (i = 0;i < pc->count;i++) {
		if (strcmp(pc->date[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* pc) {
	assert(pc);
	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ��,������Ϣɾ��.\n");
		return;
	}
	printf("������Ҫɾ���˵�����:>");
	char name[MAX_NMAE] = {0};
	scanf("%s", name);
	//����
	int ret = FindByName(pc, name);
	//ɾ��
	if (ret == -1) {
		printf("���޴���\n");
		return ;
	}
	else
	{
		for (int i = ret;i < pc->count - 1;i++)
			pc->date[i] = pc->date[i + 1]; //����
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(const Contact* pc) {
	assert(pc);
	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ��,������Ϣ.\n");
		return;
	}
	printf("������Ҫ�����˵�����:>");
	char name[MAX_NMAE] = { 0 };
	scanf("%s", name);
	//����
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("���޴���\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->date[ret].name,
			pc->date[ret].age,
			pc->date[ret].sex,
			pc->date[ret].tele,
			pc->date[ret].addr);
	}

}

void MidContact(Contact* pc) {
	assert(pc);
	if (pc->count == 0) {
		printf("ͨѶ¼Ϊ��,������Ϣ�޸�.\n");
		return;
	}
	printf("������Ҫ�޸��˵�����:>");
	char name[MAX_NMAE] = { 0 };
	scanf("%s", name);

	int ret = FindByName(pc, name);
	//�޸�
	if (ret == -1) {
		printf("���޴���\n");
		return;
	}
	else
	{
		printf("����������;>");
		scanf("%s", pc->date[ret].name);
		printf("����������;>");
		scanf("%d", &(pc->date[ret].age));
		printf("�������Ա�:>");
		scanf("%s", pc->date[ret].sex);
		printf("������绰;>");
		scanf("%s", pc->date[ret].tele);
		printf("�������ַ:>");
		scanf("%s", pc->date[ret].addr);
		printf("�޸ĳɹ�\n");
	}

}

int cmp_name(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(const Contact* pc) {
	assert(pc);
	qsort(pc->date, pc->count, sizeof(PeoInfo), cmp_name);
	printf("�������\n");

}

void SaveContact(const Contact* pc) {
	assert(pc);
	FILE* pfWritr = fopen("Contact.txt", "wb");
	if (pfWritr == NULL) {
		perror(SaveContact);
		return ;
	}
	//д�ļ�-�����Ƶ���ʽд
	int i = 0;
	for (i = 0;i < pc->count;i++) {
		fwrite(pc->date + i, sizeof(PeoInfo), 1, pfWritr);
	}	

	fclose(pfWritr);
	pfWritr == NULL;


}