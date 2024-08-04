#pragma once
#include<iostream>
#include<stdlib.h>
class Stack
{
public:
	void STInit(int capaticy = 4);

	void STPush(int x);

	void Destroy();	

private:
	int* a;
	int _top;
	int _capaticy;
};