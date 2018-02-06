#include "Calculator.h"

Calculator::Calculator() : stack(0), arrSize(0)
{
	stack = new StackList();
}

Calculator::~Calculator()
{
	delete stack;
	stack = NULL;
}

void Calculator::Postfix(string str)
{
	int idx = 0;
	int data = 0;

	while (str[idx])
	{
		switch (str[idx])
		{
		case '(':
			stack->Push('('), idx++;
			break;
		case ')':
			while (!stack->Empty() && stack->Top() != '(')
				postfix[arrSize++] = stack->Pop();
			stack->Pop(), idx++;
			break;
		case '*':
		case '/':
			while (!stack->Empty() && (stack->Top() == '*' || stack->Top() == '/'))
				postfix[arrSize++] = stack->Pop();
			stack->Push(str[idx++]);
			break;
		case '+':
		case '-':
			while (!stack->Empty() && stack->Top() != '(')
				postfix[arrSize++] = stack->Pop();
			stack->Push(str[idx++]);
			break;
		default:
			do
			{
				data = data * 10 + str[idx] - 48;
				idx++;
			} while ('0' <= str[idx] && str[idx] <= '9');

			postfix[arrSize++] = data;
			data = 0;
			break;
		}
	}

	while (stack->Size())
		postfix[arrSize++] = stack->Pop();
}

int Calculator::Postfix_Calc()
{
	int left, right = 0;

	for (int i = 0; i < arrSize; i++)
	{
		switch (postfix[i])
		{
		case '+':
			right = stack->Pop(), left = stack->Pop();
			stack->Push(left + right);
			break;
		case '-':
			right = stack->Pop(), left = stack->Pop();
			stack->Push(left - right);
			break;
		case '*':
			right = stack->Pop(), left = stack->Pop();
			stack->Push(left * right);
			break;
		case '/':
			right = stack->Pop(), left = stack->Pop();
			stack->Push(left / right);
			break;
		default:
			stack->Push(postfix[i]);
			break;
		}
	}

	memset(postfix, 0, 100);
	arrSize = 0;

	return stack->Pop();
}