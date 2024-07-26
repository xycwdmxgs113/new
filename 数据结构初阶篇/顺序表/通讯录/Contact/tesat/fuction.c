#include"head.h"

void Check(Contact* con) {
	assert(con);
	if (con->cnt == con->capacity) {
		Stu* ret = (Stu*)realloc(con->p, (con->capacity + INT_ADD)*sizeof(Stu));
		if (!ret) {
			perror("realloc");
			return;
		}
		else
		{
			con->capacity += INT_ADD;
			con->p = ret;
			ret = NULL;
			printf("���ݳɹ�\n");
		}
	}
}

void Load(Contact* con) {
	FILE* ptr = fopen("Contact.txt", "rb");
	if (!ptr) {
		perror("fopen");
		return;
	}
	Stu tem = { 0 };
	while (fread(&tem,sizeof(Stu),1,ptr)==1)
	{
		Check(con);
		con->p[con->cnt] = tem;
		con->cnt++;
	}
	fclose(ptr);
	ptr = NULL;
}

void Initial(Contact* con) {
	assert(con);
	con->cnt = 0;
	con->capacity = DEFAULT;
	con->p = (Stu*)calloc(DEFAULT, sizeof(Stu));
	if (con->p==NULL) {
		perror("calloc");
		return;
	}
	Load(con);
}

void InCrease(Contact* con) {
	assert(con);
	Check(con);//����Ƿ���Ҫ����
	printf("��������Ա����:>");
	scanf("%s", con->p[con->cnt].name);
	printf("��������Ա�Ա�:>");
	scanf("%s", con->p[con->cnt].sex);
	printf("��������Ա����:>");
	scanf("%d", &con->p[con->cnt].age);
	printf("��������Ա�绰����:>");
	scanf("%s", con->p[con->cnt].tel);
	printf("��������Ա��ͥסַ:>");
	scanf("%s", con->p[con->cnt].arr);
	con->cnt++;

}

void Reduce(Contact* con) {
	if (con->cnt == 0) {
		printf("��ͨѶ¼������Ա��Ϣ���޷�����ɾ��\n");
		return;
	}
	printf("������Ҫɾ������Ա����:>");
	char myname[MAX_NAME] = { 0 };
	scanf("%s", myname);
	int i, j;
	int flag = 0;
	for (i = 0;i < con->cnt;i++) {
		if (strcmp(myname, con->p[i].name) == 0) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		for (j = i;j < con->cnt;j++) {
			con->p[j] = con->p[j + 1];
		}
		con->cnt--;
		printf("ɾ���ɹ�\n");
	}
	else
	{
		printf("���޴�����Ϣ,���������������\n");
		return;
	}

}

void rewrite(Contact* con) {

	if (con->cnt == 0) {
		printf("��ͨѶ¼������Ա��Ϣ���޷������޸�\n");
		return;
	}
	printf("������Ҫ�޸ĵ���Ա����:>");
	char myname[MAX_NAME] = { 0 };
	scanf("%s", myname);
	int i;
	int flag = 0;
	for (i = 0;i < con->cnt;i++) {
		if (strcmp(myname, con->p[i].name) == 0) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		printf("��������Ա����:>");
		scanf("%s", con->p[i].name);
		printf("��������Ա�Ա�:>");
		scanf("%s", con->p[i].sex);
		printf("��������Ա����:>");
		scanf("%d", &con->p[i].age);
		printf("��������Ա�绰����:>");
		scanf("%s", con->p[i].tel);
		printf("��������Ա��ͥסַ:>");
		scanf("%s", con->p[i].arr);
		printf("�޸ĳɹ�\n");
	}
	else
	{
		printf("���޴�����Ϣ,���������������\n");
		return;
	}

	
}

void search(const Contact* con) {

	if (con->cnt == 0) {
		printf("��ͨѶ¼������Ա��Ϣ\n");
		return;
	}
	printf("������Ҫ���ҵ���Ա����:>");
	char myname[MAX_NAME] = { 0 };
	scanf("%s", myname);
	int i;
	int flag = 0;
	for (i = 0;i < con->cnt;i++) {
		if (strcmp(myname, con->p[i].name) == 0) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		printf("%-10s%-10s%-10s%-20s%-20s\n", "����", "�Ա�", "����", "�绰����", "��ͥסַ");
		printf("%-10s%-10s%-10d%-20s%-20s\n", con->p[i].name, con->p[i].sex, con->p[i].age, con->p[i].tel, con->p[i].arr);
	}
	else
	{
		printf("���޴���Ա��Ϣ\n");
	}


}

void Look(const Contact* con) {
	int i = 0;
	printf("%-10s%-10s%-10s%-20s%-20s\n", "����", "�Ա�", "����", "�绰����", "��ͥסַ");
	for (i = 0;i < con->cnt;i++) {
		printf("%-10s%-10s%-10d%-20s%-20s\n", con->p[i].name, con->p[i].sex, con->p[i].age, con->p[i].tel, con->p[i].arr);
	}


}

int cmp_name(const void* e1, const void* e2) {
	return strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);
}

int cmp_sex(const void* e1, const void* e2) {
	return strcmp(((Stu*)e1)->sex, ((Stu*)e2)->sex);
}

int cmp_age(const void* e1, const void* e2) {
	return ((Stu*)e1)->age-((Stu*)e2)->age;
}

int cmp_tel(const void* e1, const void* e2) {
	return strcmp(((Stu*)e1)->tel, ((Stu*)e2)->tel);
}

void Temp(char* arr1, char* arr2, int size) {
	char temp;
	for (int i = 0;i < size;i++) {
		temp = *arr1;
		*arr1 = *arr2;
		*arr2 = temp;
		arr1++;
		arr2++;
	}
}

void bullue_sort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num - 1 - i;j++) {
			if (compar((char*)base + j * size, (char*)base + ((j + 1) * size)) > 0) {
				Temp((char*)base + j * size, (char*)base + ((j + 1) * size),size);
			}
		}
	}
}

void sort(Contact* con) {
	printf("������Ҫ����ķ�ʽ\n");
	printf("1:���������� 2:���Ա�����\n3:���������� 4:����ͥסַ����\n");
	int n;
	scanf("%d", &n);
	int (*p[5])(const void* e1, const void* e2) = { 0,cmp_name,cmp_sex,cmp_age,cmp_tel };
	bullue_sort(con->p, con->cnt, sizeof(con->p[0]), p[n]);
	printf("�������\n");

}

void Record(const Contact* con) {
	FILE* ptr = fopen("Contact.txt", "wb");
	if (!ptr) {
		perror("fopen");
		return;
	}

	for (int i = 0;i < con->cnt;i++) {
		fwrite(con->p + i, sizeof(Stu), 1, ptr);
	}

	fclose(ptr);
	ptr = NULL;
}

void Free(Contact* con) {
	free(con->p);
	con->p = NULL;
}