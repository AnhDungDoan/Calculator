#include <iostream>
#include <string>
#include <stack>

#include "Header.h"

using namespace std;

const int MAX = 100;

char DataStored[300][MAX + 1];
int nDatastored = 0;

bool isDigit(char x)
{
	return (x >= '0' && x <= '9');
}

bool isOperator(char x)
{
	return (x == '+' || x == '-' || x == '*' || x == '/');
}

int Prioritize(char x)
{
	if (x == '(') return 0;
	else
		if (x == '+' || x == '-') return 1;
		else
			if (x == '*' || x == '/') return 2;

	return -1;
}

void InfixToPostfix(char infix[], char postfix[])
{
	int j = 0;
	stack <char> Operator;

	bool minus[MAX + 1];
	memset(minus, false, sizeof(minus));
	int nInfix = strlen(infix);

	for (int i = 0; i < nInfix; i++)
	{
		if (infix[i] == ' ' || infix[i] == '\t') continue; //remove space in infix array

		if (isDigit(infix[i]) || (DataStored[infix[i]] != ""))
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

	stack <float> Number;
	int nPostfix = strlen(postfix);
	for (int i = 0; i < nPostfix; i++)
	{
		while (postfix[i] == ' ') i++;

		if (isDigit(postfix[i]))
		{
			float realNumber = 1;
			float num = int(postfix[i]) - 48;

			while (isDigit(postfix[i + 1]) || (postfix[i + 1] == '.'))
			{
				i++;
				if (postfix[i] == '.')
				{
					realNumber = 10;
					continue;
				}
				float x = int(postfix[i]) - 48;

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
	cout << "Result is: " << result;
}

void basicCalculator:: checkExpression()
{
	bool checkRightExpression = false;
	char Expression[MAX + 1], postfixExpression[MAX + 1];

	cout << "\nWrite your calculation: ";

	cin.ignore();
	gets_s(Expression);

	// Check that the expression entered is correct or not

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

			if ((Expression[i] == '/' && Expression[i + 1] == '*') || (Expression[i + 1] == '/' && Expression[i] == '*'))
			{
				rightParenthese = -1;
				break;
			}
		}

		if (rightParenthese != 0 || isOperator(Expression[lengthExpression - 1]))
		{
			cout << "Your expression is incorrect, enter again? Y/N: ";
			char question;
			cin >> question;
			if (question == 'N') return;
		}
		else checkRightExpression = true;


	}

	// Process expression using stack and Postfix
	InfixToPostfix(Expression, postfixExpression);
}
