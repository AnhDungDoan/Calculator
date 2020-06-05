#include "IOHandler.h"
#include "Processor.h"

#include <iostream>

std::string IOHandler::getInput()
{
	std::string input;
	std::cin >> input;
	return input;
}

void IOHandler::run()
{
	while (true)
	{
		std::string input = getInput();
		Processor::basicCalculator(input);
	}
}
