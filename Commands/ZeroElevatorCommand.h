#ifndef ZERO_ELEVATOR_COMMAND_H
#define ZERO_ELEVATOR_COMMAND_H

#include "Types/DefaultCommand.h"

class ZeroElevatorCommand : public DefaultCommand {

public:
	ZeroElevatorCommand();
	void Initialize();
	void End();
};

#endif
