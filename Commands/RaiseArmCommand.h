#ifndef RAISE_ARM_COMMAND_H
#define RAISE_ARM_COMMAND_H

#include "Types/InstantCommand.h"

class RaiseArmCommand : public InstantCommand {

public:
	RaiseArmCommand();
	void Initialize();
};

#endif
