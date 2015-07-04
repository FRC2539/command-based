#ifndef CHANGE_ELEVATOR_LEVEL_COMMAND_H
#define CHANGE_ELEVATOR_LEVEL_COMMAND_H

#include "Types/DefaultCommand.h"

class ChangeElevatorLevelCommand : public DefaultCommand {

public:
	ChangeElevatorLevelCommand(int change);
	void Initialize();
	void Execute();
	bool IsFinished();

protected:
	int m_change;
};

#endif
