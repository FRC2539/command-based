#ifndef LOWER_ELEVATOR_COMMAND_H
#define LOWER_ELEVATOR_COMMAND_H

#include "Types/DefaultCommand.h"

class LowerElevatorCommand : public DefaultCommand {

public:
	LowerElevatorCommand();
	void Initialize();
	bool IsFinished();
	void End();
};

#endif
