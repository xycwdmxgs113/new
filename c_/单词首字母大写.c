#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {
	char ch, p = ' ';
	while ((ch = getchar()) != '\n') {
		if ((ch >= 'a' && ch <= 'z') && p == ' ') {
			ch = ch - 'a' + 'A';
		}
		/*
		if (ch>='a'&&ch<='z'&&prev==' ') ch=ch-'a'+'A';:
		���д���ʹ����������� if��
		�����ȼ�鵱ǰ�ַ� ch �Ƿ���Сд��ĸ���� ASCII ���� 'a' �� 'z' ֮�䣩
		ͬʱ��һ���ַ� p �Ƿ�Ϊ�ո�
		����������㣬����ǰ�ַ��ǵ��ʵĵ�һ����ĸ��ǰ���пո���ôִ�д�дת��������ǰ�ַ���ȥСд��ĸ 'a' �� ASCII ��
		Ȼ����ϴ�д��ĸ 'A' �� ASCII �룬�Ӷ���Сд��ĸת��Ϊ��д��ĸ��
		*/
		printf("%c", ch);
		p = ch;
	}


	return 0;
}