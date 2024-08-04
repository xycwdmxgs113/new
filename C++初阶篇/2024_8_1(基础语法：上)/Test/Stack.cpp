#include"Stack.h"
;

namespace cat
{
	void STInit(ST* ps, int n=4)
	{
		assert(ps);
		ps->a = (STDataType*)malloc(n * sizeof(STDataType));
		ps->top = 0;
		ps->capacity = n;
	}
	// Õ»¶¥
	void STPush(ST* ps, STDataType x)
	{// ÂúÁË£¬ À©ÈÝ
		if (ps->top == ps->capacity)
		{
			printf("À©ÈÝ\n");
			int newcapacity = ps->capacity == 0 ? 4 : ps->capacity
				* 2;
			STDataType* tmp = (STDataType*)realloc(ps->a,
				newcapacity * sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}ps->a = tmp;
			ps->capacity = newcapacity;
		}

		ps->a[ps->top] = x;
		ps->top++;
	}
}