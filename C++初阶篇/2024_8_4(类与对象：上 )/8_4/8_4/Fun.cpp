#include"Fun.h"

void  Stack:: STInit(int  capaticy)
{
	a = (int*)malloc(sizeof(int) * capaticy);
	_top = 0;
	_capaticy = capaticy;
}

void  Stack::STPush(int x)
{
	a[_top++] = x;
}

void Stack:: Destroy()
{
	free(a);
	a = nullptr;
}