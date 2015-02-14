#ifndef RAISE_ELEVATOR_COMMAND_H
#define RAISE_ELEVATOR_COMMAND_H

#include "Types/DefaultCommand.h"

class RaiseElevatorCommand : public DefaultCommand {

public:
	RaiseElevatorCommand();
	void Initialize();
	bool IsFinished();
	void End();
};

#endif
