#pragma once
#include <string>

class Processor
{
private:
	static const int MAX = 100;

	struct DataStored
	{
		char Name[11];
		float Data;
	};

	static DataStored VariableDataStored[MAX  + 1];

	static bool isDigit(char x);
	static bool isOperator(char x);
	static int Prioritize(char x);
	static void InfixToPostfix(std::string infix, char postfix[]);

public:
	friend class IOhandler;

	static void basicCalculator(std::string Expression);
	static int Generator(std::string Expression);

};

