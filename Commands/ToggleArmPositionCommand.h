#ifndef TOGGLE_ARM_POSITION_COMMAND_H
#define TOGGLE_ARM_POSITION_COMMAND_H

#include "Types/TimedCommand.h"

class ToggleArmPositionCommand : public TimedCommand {

public:
	ToggleArmPositionCommand();
	void Initialize();
	void End();

protected:
};

#endif
