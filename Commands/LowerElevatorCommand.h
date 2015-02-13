#ifndef LOWER_ELEVATOR_COMMAND_H
#define LOWER_ELEVATOR_COMMAND_H

#include "Types/InstantCommand.h"

class LowerElevatorCommand : public InstantCommand {

public:
	LowerElevatorCommand();
	void Initialize();
};

#endif
