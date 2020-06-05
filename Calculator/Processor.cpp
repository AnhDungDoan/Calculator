#include "Processor.h"

#include <iostream>
#include <string>
#include <stack>


bool Processor::isDigit(char x)
{
	return (x >= '0' && x <= '9');
}

bool Processor::isOperator(char x)
{
	return (x == '+' || x == '-' || x == '*' || x == '/');
}


int Processor::Prioritize(char x)
{
	if (x == '(') return 0;
	else
		if (x == '+' || x == '-') return 1;
		else
			if (x == '*' || x == '/') return 2;

	return -1;
}

void Processor::InfixToPostfix(std::string infix, char postfix[])
{
	int j = 0;
	std::stack <char> Operator;

	int nInfix = infix.size();

	for (int i = 0; i < nInfix; i++)
	{
		if (infix[i] == ' ' || infix[i] == '\t') continue; //remove space in infix array

		if (isDigit(infix[i]))
		{
			postfix[j++] = infix[i];
			while (isDigit(infix[i + 1]) || infix[i + 1] == '.')
			{
				i++;
				postfix[j++] = infix[i];
			}

			postfix[j++] = ' ';
		}
		else
		{
			if (infix[i] == '(') Operator.push(infix[i]);
			else
				if (infix[i] == ')')
				{
					char x = Operator.top();
					Operator.pop();
					while (x != '(')
					{
						postfix[j++] = x;
						x = Operator.top();
						Operator.pop();
					}
				}
				else
				{
					if (!Operator.empty())
					{
						while (Prioritize(infix[i]) <= Prioritize(Operator.top()))
						{
							postfix[j++] = Operator.top();
							Operator.pop();

							if (Operator.empty()) break;
						}
					}
					Operator.push(infix[i]);
				}
		}
	}

	while (!Operator.empty())
	{
		postfix[j++] = Operator.top();
		Operator.pop();
	}

	postfix[j] = '\0';

	// Calculate

	std::stack <float> Number;
	int nPostfix = strlen(postfix);
	for (int i = 0; i < nPostfix; i++)
	{
		while (postfix[i] == ' ') i++;

		if (isDigit(postfix[i]))
		{
			float realNumber = 1;
			float num = (float) int(postfix[i]) - 48;

			while (isDigit(postfix[i + 1]) || (postfix[i + 1] == '.'))
			{
				i++;
				if (postfix[i] == '.')
				{
					realNumber = 10;
					continue;
				}
				float x = (float) int(postfix[i]) - 48;

				if (realNumber == 1) num = num * 10 + x;
				else
				{
					num = num + (x / realNumber);
					realNumber = realNumber * 10;
				}
			}

			Number.push(num);
		}
		else
		{
			float a = Number.top(); Number.pop();
			float b = Number.top(); Number.pop();
			switch (postfix[i])
			{
			case '+':
				Number.push(a + b);
				break;
			case '-':
				Number.push(b - a);
				break;
			case '*':
				Number.push(a * b);
				break;
			case '/':
				Number.push(b / a);
			}
		}
	}

	float result = Number.top();
	std::cout << "Result is: " << result;
}

void Processor::basicCalculator(std::string Expression)
{
	bool checkRightExpression = false;
	char postfixExpression[MAX + 1];

	// Check that the expression entered is correct or not
/*
	while (!checkRightExpression)
	{
		int lengthExpression = strlen(Expression);

		int rightParenthese = 0;

		for (int i = 0; i < lengthExpression; i++)
		{
			if (Expression[i] == '(')
				rightParenthese++;
			else
				if (Expression[i] == ')')
					rightParenthese--;

			if (rightParenthese < 0) break;
		}

		if (rightParenthese != 0 || isOperator(Expression[lengthExpression - 1]))
		{
			std::cout << "Your expression is incorrect, enter again? Y/N: ";
			char question;
			std::cin >> question;
			if (question == 'N') return;
		}
		else checkRightExpression = true;


	}
*/

	// Process expression using std::stack and Postfix
	InfixToPostfix(Expression, postfixExpression);
}
