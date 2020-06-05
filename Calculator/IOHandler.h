#pragma once

#include <string>
#include <Process.h>

class IOHandler
{
private:
	static std::string getInput();

public:
	static void run();
};
