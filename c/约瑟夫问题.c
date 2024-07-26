#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define MAXN 20

void CountOff( int n, int m, int out[] ) {
	int finger = 0; //计数从零开始
	int cnt = 1;		//统计人数从一开始
	int i;
	for (i = 0; i < n; i++)
		out[i] = 0; //初始化退出人的数组为0；

	while (cnt <= n) { //当退出人数只剩下最后一个人的时候退出循环
		for (i = 0; i < n; i++) { //每一次循环都可以看作是一轮游戏，当每一轮退出完就进行下一轮
			if (out[i] == 0) { //循环遍历数组out，如果元素为0则表示当前人还没有退出
				finger++;//指向下一个人
			}
			if (finger == m) {//当指的次数等于m
				out[i] = cnt;//将该人员的编号标记为 cnt，即将 out[i] 的值设为 cnt，表示该人员已经出列,下次循环就会跳过当前人
				cnt++;// 踢出当前的人
				finger = 0;//开始重新计数
			}
		}
	}
}

int main() {
	int out[MAXN], n, m;
	int i;

	scanf("%d %d", &n, &m);
	CountOff( n, m, out );
	for ( i = 0; i < n; i++ )
		printf("%d ", out[i]);
	printf("\n");
	return 0;
}

