#ifndef MAINTAIN_ELEVATOR_HEIGHT_COMMAND_H
#define MAINTAIN_ELEVATOR_HEIGHT_COMMAND_H

#include "Types/DefaultCommand.h"

class MaintainElevatorHeightCommand : public DefaultCommand {

public:
	MaintainElevatorHeightCommand();
	void Initialize();
};

#endif
