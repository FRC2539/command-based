#ifndef RAISE_ELEVATOR_COMMAND_H
#define RAISE_ELEVATOR_COMMAND_H

#include "Types/InstantCommand.h"

class RaiseElevatorCommand : public InstantCommand {

public:
	RaiseElevatorCommand();
	void Initialize();
};

#endif
