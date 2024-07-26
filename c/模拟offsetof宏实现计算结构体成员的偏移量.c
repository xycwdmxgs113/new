#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<ctype.h>
#include<assert.h>

#include<stddef.h>


struct S
{
	char c1;
	int i;
	char c2;
};
#define OFFSETOF(type,m_name)    (size_t)&(((type*)0)->m_name)      
			//   类型 成员
int main() {
	struct S s;
	printf("%d\n",OFFSETOF(struct S,c1));
	printf("%d\n", OFFSETOF(struct S, i));
	printf("%d\n", OFFSETOF(struct S, c2));


	return 0;
}