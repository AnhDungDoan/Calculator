#include "IOHandler.h"

#include <iostream>

int main()
{
	std::cout << "Welcome to basic calculator!\n";
	std::cout << "Please read 'language.txt'\n";
	std::cout << "It can be used for calculating, assign a variable, basic calculate 2x2 matrix\n";
	std::cout << "Type 'exit' and press 'enter' to exit this program!\n";
	std::cout << "Thank you for using my calculator!!!\n";
	std::cout << "Type your expression, enjoy!\n";
	std::cout << "\n";

	IOHandler::run();

	return 0;
}