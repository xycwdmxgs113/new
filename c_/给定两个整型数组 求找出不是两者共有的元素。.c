#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include <string.h>


int main() {
	int n;
	scanf("%d", &n);
	int a1[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a1[i]);
	}
	int m;
	scanf("%d", &m);
	int a2[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &a2[i]);
	}

	int c[n + m];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int k = 0; k < m; k++) {
			if (a1[i] == a2[k]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			c[cnt] = a1[i];
			cnt++;
		}
	}

	for (int i = 0; i < m; i++) {
		int flag = 1;
		for (int k = 0; k < n; k++) {
			if (a2[i] == a1[k]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			c[cnt] = a2[i];
			cnt++;
		}
	}
	printf("%d", c[0]);
	for (int i = 1; i < cnt; i++) {
		int flag = 1;
		for (int k = 0; k < i; k++) {
			if (c[i] == c[k]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			printf(" %d", c[i]);
		}
	}


	return 0;
}
