#include"head.h"

void menu(void) {
	printf("*********************\n");
	printf("**1.����    2.ɾ�� **\n");
	printf("**3.��д    4.���� **\n");
	printf("**5.��ʾ    6.���� **\n");
	printf("**0.�˳�    *********\n");
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
	Initial(&con); //��ʼ��

	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case Exit:
			Record(&con);
			Free(&con);
			printf("�˳�ͨѶ¼\n");
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
			printf("��������ȷѡ��\n");
			break;
		}


	} while (n);





	return 0;
}