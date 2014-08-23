#ifndef PRINT_COMMAND_H
#define PRINT_COMMAND_H

#include "Types/InstantCommand.h"
#include <string>

class PrintCommand : public InstantCommand {

public:
	PrintCommand(std::string msg);
	void Initialize();

protected:
	std::string message;
};

#endif
