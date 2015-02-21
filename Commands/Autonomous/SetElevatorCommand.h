#ifndef SET_ELEVATOR_COMMAND_H
#define SET_ELEVATOR_COMMAND_H

#include "../Types/DefaultCommand.h"

class SetElevatorCommand : public DefaultCommand {

public:
	SetElevatorCommand(int target);
	void Initialize();
	bool IsFinished();
	void End();

protected:
	int targetHeight;
};

#endif