#include"head.h"

void menu(void) {
	printf("*********************\n");
	printf("**1.增加    2.删除 **\n");
	printf("**3.改写    4.查找 **\n");
	printf("**5.显示    6.排序 **\n");
	printf("**0.退出    *********\n");
	printf("*********************\n");
}

enum Option
{
	Exit,
	Add,
	Delete,
	Rewrite,
	Search,
	Show,
	Sort
};



int main() {

	int n;
	Contact con = { 0 };
	Initial(&con); //初始化

	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case Exit:
			Record(&con);
			Free(&con);
			printf("退出通讯录\n");
			break;
		case Add:
			InCrease(&con);
			break;
		case Delete:
			Reduce(&con);
			break;
		case Rewrite:
			rewrite(&con);
			break;
		case Search:
			search(&con);
			break;
		case Show:
			Look(&con);
			break;
		case Sort:
			sort(&con);
			break;
		default:
			printf("请输入正确选项\n");
			break;
		}


	} while (n);





	return 0;
}