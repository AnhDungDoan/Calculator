#pragma once
#include <string>

class Processor
{
private:
	static const int MAX = 100;

	struct floatDataStored
	{
		std::string Name;
		float Data;
	};

	struct vectorType
	{
		std::string Name;
		float coordinate[2];
	};

	static floatDataStored VariableDataStored[MAX  + 1];
	static int nVariableDataStored;

	static vectorType vectorStored[MAX + 1];
	static int nVectorStored;

	static bool isDigit(char x);
	static bool isChar(char x);
	static bool isOperator(char x);
	static int Prioritize(char x);
	static float InfixToPostfix(std::string infix, char postfix[]);

public:
	friend class IOhandler;

	static float fakeNumber;

	static int Analysis(std::string &Expression);

	static float basicCalculator(std::string Expression);
	static void assignmentVariable(std::string Expression);
	static float* vectorCalculator(std::string Expression);
};

