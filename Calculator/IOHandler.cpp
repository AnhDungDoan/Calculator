#include "IOHandler.h"
#include "Processor.h"

#include <iostream>

std::string IOHandler::getInput()
{
	std::string input;
	//std::cin.ignore();
	std::getline(std::cin, input);
	return input;
}

void IOHandler::run()
{
	//condition returns:
	//	1: Basic Calculator
	//	2: Assignment Variable
	//  3: Vector Processing
	//  4: Matrix

	while (true)
	{
		std::string input = "";
		do
		{
			input = getInput();
		} 
		while (input.empty());

		int options = Processor::Analysis(input);

		switch (options)
		{
		case 1:
		{
			float result = Processor::basicCalculator(input);
			if (result == Processor::fakeNumber)
				std::cout << "Error!!!" << std::endl;
			else
				std::cout << "Result is: " << result << std::endl;
			break;
		}
		case 2:
		{
			Processor::assignmentVariable(input);
			break;
		}
		case 3:
		{
			float* ans = Processor::vectorCalculator(input);
			std::cout << "[" << ans[0] << "," << ans[1] << "]" << std::endl;
			break;
		}
		}
	}
}
