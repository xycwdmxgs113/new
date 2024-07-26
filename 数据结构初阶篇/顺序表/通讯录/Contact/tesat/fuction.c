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
			printf("扩容成功\n");
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
	Check(con);//检查是否需要扩容
	printf("请输入人员姓名:>");
	scanf("%s", con->p[con->cnt].name);
	printf("请输入人员性别:>");
	scanf("%s", con->p[con->cnt].sex);
	printf("请输入人员年龄:>");
	scanf("%d", &con->p[con->cnt].age);
	printf("请输入人员电话号码:>");
	scanf("%s", con->p[con->cnt].tel);
	printf("请输入人员家庭住址:>");
	scanf("%s", con->p[con->cnt].arr);
	con->cnt++;

}

void Reduce(Contact* con) {
	if (con->cnt == 0) {
		printf("该通讯录再无人员信息，无法进行删除\n");
		return;
	}
	printf("请输入要删除的人员姓名:>");
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
		printf("删除成功\n");
	}
	else
	{
		printf("暂无此人信息,请重新输入后再试\n");
		return;
	}

}

void rewrite(Contact* con) {

	if (con->cnt == 0) {
		printf("该通讯录再无人员信息，无法进行修改\n");
		return;
	}
	printf("请输入要修改的人员姓名:>");
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
		printf("请输入人员姓名:>");
		scanf("%s", con->p[i].name);
		printf("请输入人员性别:>");
		scanf("%s", con->p[i].sex);
		printf("请输入人员年龄:>");
		scanf("%d", &con->p[i].age);
		printf("请输入人员电话号码:>");
		scanf("%s", con->p[i].tel);
		printf("请输入人员家庭住址:>");
		scanf("%s", con->p[i].arr);
		printf("修改成功\n");
	}
	else
	{
		printf("暂无此人信息,请重新输入后再试\n");
		return;
	}

	
}

void search(const Contact* con) {

	if (con->cnt == 0) {
		printf("该通讯录再无人员信息\n");
		return;
	}
	printf("请输入要查找的人员姓名:>");
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
		printf("%-10s%-10s%-10s%-20s%-20s\n", "姓名", "性别", "年龄", "电话号码", "家庭住址");
		printf("%-10s%-10s%-10d%-20s%-20s\n", con->p[i].name, con->p[i].sex, con->p[i].age, con->p[i].tel, con->p[i].arr);
	}
	else
	{
		printf("暂无此人员信息\n");
	}


}

void Look(const Contact* con) {
	int i = 0;
	printf("%-10s%-10s%-10s%-20s%-20s\n", "姓名", "性别", "年龄", "电话号码", "家庭住址");
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
	printf("请输入要排序的方式\n");
	printf("1:按名字排序 2:按性别排序\n3:按年龄排序 4:按家庭住址排序\n");
	int n;
	scanf("%d", &n);
	int (*p[5])(const void* e1, const void* e2) = { 0,cmp_name,cmp_sex,cmp_age,cmp_tel };
	bullue_sort(con->p, con->cnt, sizeof(con->p[0]), p[n]);
	printf("排序完成\n");

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