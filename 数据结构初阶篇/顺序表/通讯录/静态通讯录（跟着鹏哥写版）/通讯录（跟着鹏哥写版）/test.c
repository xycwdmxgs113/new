#include"contact.h"

void menu(void) {
	printf("***********************************\n");
	printf("****  1.����      2.ɾ��  *********\n");
	printf("****  3.����      4.��д  *********\n");
	printf("****  5.��ʾ      6.����  *********\n");
	printf("****  0.�˳�              *********\n");
	printf("***********************************\n");
}

int main() {
	int n;
	Contact con;//ͨѶ¼
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			SaveContact(&con);
			DESContact(&con);
			printf("�˳�ͨѶ¼\n");
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
			printf("ѡ�����\n");
			break;
		}

	} while (n);


	return 0;
}