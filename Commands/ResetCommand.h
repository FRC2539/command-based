#ifndef RESET_COMMAND_H
#define RESET_COMMAND_H

#include "Types/InstantCommand.h"

class ResetCommand : public InstantCommand {

public:
	ResetCommand();
	void Initialize();
};

#endif
