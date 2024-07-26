#include"contact.h"


//静态版本
//void InitContact(Contact* pc) {
//	assert(pc);
//	pc->count = 0;
//	memset(pc->date, 0, sizeof(pc->date));
//}


//动态版本

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


//动态版本初始化
void InitContact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	pc->date=(PeoInfo*)calloc(DEFULT_SZIE, sizeof(PeoInfo));
	if (pc->date == NULL) {
		printf("InitContact::%s", strerror(errno));
		return;
	}
	pc->capacity = DEFULT_SZIE;
	//初始化通讯录
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

//静态版本增加
//void AddContact(Contact* pc) {
//	assert(pc);
//	if (pc->count == MAX_DATE) {
//		printf("通讯录已满，无法添加\n");
//		return;	
//	}
//	printf("请输入姓名;>");
//	scanf("%s", pc->date[pc->count].name);
//	printf("请输入年龄;>");
//	scanf("%d", &(pc->date[pc->count].age));
//	printf("请输入性别:>");
//	scanf("%s", pc->date[pc->count].sex);
//	printf("请输入电话;>");
//	scanf("%s", pc->date[pc->count].tele);
//	printf("请输入地址:>");
//	scanf("%s", pc->date[pc->count].addr);
//	pc->count++;
//	printf("增加成功\n");
//}


void AddContact(Contact* pc) {
	assert(pc);
	if (pc->count == MAX_DATE) {
		printf("通讯录已满，无法添加\n");
		return;
	}
	check(pc);
	printf("请输入姓名;>");
	scanf("%s", pc->date[pc->count].name);
	printf("请输入年龄;>");
	scanf("%d", &(pc->date[pc->count].age));
	printf("请输入性别:>");
	scanf("%s", pc->date[pc->count].sex);
	printf("请输入电话;>");
	scanf("%s", pc->date[pc->count].tele);
	printf("请输入地址:>");
	scanf("%s", pc->date[pc->count].addr);
	pc->count++;
	printf("增加成功\n");
}


void ShowContact(const Contact* pc) {
	assert(pc);
	int i;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "住址");
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
		printf("通讯录为空,暂无信息删除.\n");
		return;
	}
	printf("请输入要删除人的姓名:>");
	char name[MAX_NMAE] = {0};
	scanf("%s", name);
	//查找
	int ret = FindByName(pc, name);
	//删除
	if (ret == -1) {
		printf("查无此人\n");
		return ;
	}
	else
	{
		for (int i = ret;i < pc->count - 1;i++)
			pc->date[i] = pc->date[i + 1]; //覆盖
	}
	pc->count--;
	printf("删除成功\n");
}

void SearchContact(const Contact* pc) {
	assert(pc);
	if (pc->count == 0) {
		printf("通讯录为空,暂无信息.\n");
		return;
	}
	printf("请输入要查找人的姓名:>");
	char name[MAX_NMAE] = { 0 };
	scanf("%s", name);
	//查找
	int ret = FindByName(pc, name);
	if (ret == -1) {
		printf("查无此人\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "住址");
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
		printf("通讯录为空,暂无信息修改.\n");
		return;
	}
	printf("请输入要修改人的姓名:>");
	char name[MAX_NMAE] = { 0 };
	scanf("%s", name);

	int ret = FindByName(pc, name);
	//修改
	if (ret == -1) {
		printf("查无此人\n");
		return;
	}
	else
	{
		printf("请输入姓名;>");
		scanf("%s", pc->date[ret].name);
		printf("请输入年龄;>");
		scanf("%d", &(pc->date[ret].age));
		printf("请输入性别:>");
		scanf("%s", pc->date[ret].sex);
		printf("请输入电话;>");
		scanf("%s", pc->date[ret].tele);
		printf("请输入地址:>");
		scanf("%s", pc->date[ret].addr);
		printf("修改成功\n");
	}

}

int cmp_name(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(const Contact* pc) {
	assert(pc);
	qsort(pc->date, pc->count, sizeof(PeoInfo), cmp_name);
	printf("排序完成\n");

}

void SaveContact(const Contact* pc) {
	assert(pc);
	FILE* pfWritr = fopen("Contact.txt", "wb");
	if (pfWritr == NULL) {
		perror(SaveContact);
		return ;
	}
	//写文件-二进制的形式写
	int i = 0;
	for (i = 0;i < pc->count;i++) {
		fwrite(pc->date + i, sizeof(PeoInfo), 1, pfWritr);
	}	

	fclose(pfWritr);
	pfWritr == NULL;


}