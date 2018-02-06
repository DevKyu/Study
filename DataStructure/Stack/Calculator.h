#pragma once
#include "Stack.h"
#include <string>

class Calculator
{
private:
	StackList* stack;
	int postfix[100];
	int arrSize;
public:
	Calculator();
	~Calculator();
	void Postfix(string str);
	int Postfix_Calc();
};
