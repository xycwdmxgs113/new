#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio.h>


int main() {
	char ch;
	int flag = 0;
	int cnt = 0;
	while ((ch = getchar()) != '#') {
		switch (ch) {
			case 'e':
				if (flag)
					flag = 1;
				break;
			case 'i':
				if (!flag) {
					cnt++;
					flag = 0;
				}
				break;
			default :
				break;
		}
	}
	printf("%d", cnt);

	return 0;
}