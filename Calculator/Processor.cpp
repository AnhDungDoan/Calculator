#include "Processor.h"

#include <iostream>
#include <string>
#include <stack>
#include <vector>


float Processor::fakeNumber = -0.839812673f;

int Processor::nVariableDataStored = 0;
int Processor::nVectorStored = 0;
Processor::vectorType Processor::vectorStored[MAX + 1];
Processor::floatDataStored Processor::VariableDataStored[MAX + 1];

bool Processor::isDigit(char x)
{
	return (x >= '0' && x <= '9');
}

bool Processor::isChar(char x)
{
	return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'));
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

int Processor::Analysis(std::string &Expression)
{
	//condition returns:
	//	1: Basic Calculator
	//	2: Assignment Variable
	//  3: Vector Processing
	//  4: Matrix

	// remove space in string
	int i = 0;
	while (Expression[i] != '\0')
	{
		while (Expression[i] == ' ') Expression.erase(i, 1);

		i++;
	}

	int lengthExpression = Expression.size();
	for (int i = 0; i < lengthExpression; i++)
	{
		if (Expression[i] == '=') return 2;
		if (Expression[i] == '[' && Expression[i + 1] == '[') return 4;
		if (Expression[i] == '[') return 3;
	}

	return 1;
}


float Processor::InfixToPostfix(std::string infix, char postfix[])
{
	int j = 0;
	std::stack <char> Operator;

	int nInfix = infix.size();

	//Create postfix array

	for (int i = 0; i < nInfix; i++)
	{
		if (infix[i] == ' ' || infix[i] == '\t') continue; //remove space in infix array

		if (isChar(infix[i]))
		{
			postfix[j++] = infix[i];
			while (isChar(infix[i + 1]))
			{
				i++;
				postfix[j++] = infix[i];
			}

			postfix[j++] = ' ';
		}
		else
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

	postfix[j++] = '+';
	postfix[j] = '\0';

	// Calculate

	std::stack <float> Number;
	Number.push(0.0);

	int nPostfix = strlen(postfix);
	for (int i = 0; i < nPostfix; i++)
	{
		while (postfix[i] == ' ') i++;

		//Check variables exist
		if (isChar(postfix[i]))
		{
			std::string Variable = "";

			Variable.push_back(postfix[i]);

			while (isChar(postfix[i + 1]))
			{
				Variable.push_back(postfix[i + 1]);
				i++;
			}

			for (int j = 0; j < nVariableDataStored; j++)
				if (VariableDataStored[j].Name.compare(Variable) == 0)
				{
					Number.push(VariableDataStored[j].Data);
					break;
				}
		}
		else
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
	return result;
}

float Processor::basicCalculator(std::string Expression)
{
	bool checkRightExpression = false;
	char postfixExpression[MAX + 1];

	// Check that the expression entered is correct or not

	int lengthExpression = Expression.size();

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

	if (rightParenthese != 0 || isOperator(Expression[lengthExpression - 1])) return fakeNumber; // a fake number signals a wrong expression

	// Process expression using std::stack and Postfix
	return InfixToPostfix(Expression, postfixExpression);
}


void Processor::assignmentVariable(std::string Expression)
{
	int lengthExpression = Expression.size();
	bool startAdding = false;
	std::string tempExpression = "";

	for (int i = 0; i < lengthExpression; i++)
	{
		if (startAdding) tempExpression.push_back(Expression[i]);

		if (Expression[i] == '=') startAdding = true;
	}

	float value = basicCalculator(tempExpression);
	if (value == fakeNumber)
	{
		std::cout << "Error!!!";
		return;
	}
	else
	{
		// Check duplicate string name in variableDataStored

		std::string duplicateCheck = "";

		int lengthTempExpression = tempExpression.size();

		for (int i = 0; i < lengthExpression - (lengthTempExpression + 1); i++) 
			if (Expression[i] != ' ')
				duplicateCheck.push_back(Expression[i]);

		for (int i = 0; i < nVariableDataStored; i++)
			if (duplicateCheck.compare(VariableDataStored[i].Name) == 0)
			{
				VariableDataStored[i].Data = value;
				return;
			}
			
		for (int j = 0; j < duplicateCheck.size(); j++)
			VariableDataStored[nVariableDataStored].Name.push_back(duplicateCheck[j]);

		VariableDataStored[nVariableDataStored].Data = value;
		++nVariableDataStored;
	}
}

float* Processor::vectorCalculator(std::string inputString)
{
	float vectorDataStored[MAX + 1][2]; // stored coordinates (x, y) each vector by (vectorDataStored[0], vectorDataStored[1])
	static float ans[2];
	int nVectorDataStored = 0, row = 0; 

	std::vector<char> operatorVector;
	operatorVector.push_back('+');

	int lengthInputString = inputString.size();

	for (int i = 0; i < lengthInputString; i++)
	{
		if (isDigit(inputString[i]))
		{
			std::string tempExpression = "";
			tempExpression.push_back(inputString[i]);

			for (int j = i + 1; (inputString[j] != ']') && (inputString[j] != ','); j++)
			{
				tempExpression.push_back(inputString[j]);
				i = j;
			}

			vectorDataStored[nVectorDataStored][row] = basicCalculator(tempExpression);
		}
		
		if (inputString[i] == ',' || isOperator(inputString[i])) row = 1 - row;
		
		if (isOperator(inputString[i]) && inputString[i - 1] == '[') operatorVector.push_back(inputString[i]);

		if (inputString[i] == ']') nVectorDataStored++;
	}

	int indexPointerOperatorVector = 0;
	for (int i = 0; i < nVectorDataStored; i++)
	{
		switch (operatorVector[indexPointerOperatorVector])
		{
		case '+':
		{
			ans[0] += vectorDataStored[i][0];
			ans[1] += vectorDataStored[i][1];
			break;
		}
		case '-':
		{
			ans[0] -= vectorDataStored[i][0];
			ans[1] -= vectorDataStored[i][1];
			break;
		}
		}
	}

	return ans;
}


