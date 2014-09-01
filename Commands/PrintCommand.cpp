#include "PrintCommand.h"

#include <iostream>

PrintCommand::PrintCommand(std::string msg) :
	InstantCommand("Reset"), message(msg) {}

void PrintCommand::Initialize()
{
	std::cout << message << "\n";
}


