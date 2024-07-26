#include"contact.h"

void menu(void) {
	printf("***********************************\n");
	printf("****  1.增加      2.删除  *********\n");
	printf("****  3.查找      4.改写  *********\n");
	printf("****  5.显示      6.排序  *********\n");
	printf("****  0.退出              *********\n");
	printf("***********************************\n");
}

int main() {
	int n;
	Contact con;//通讯录
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			SaveContact(&con);
			DESContact(&con);
			printf("退出通讯录\n");
			break;
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			SearchContact(&con);
			break;
		case 4:
			MidContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (n);


	return 0;
}