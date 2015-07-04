#ifndef BUTTON_ELEVATOR_COMMAND_H
#define BUTTON_ELEVATOR_COMMAND_H

#include "Types/DefaultCommand.h"

class ButtonElevatorCommand : public DefaultCommand {

public:
	ButtonElevatorCommand(Elevator::Direction direction);
	void Initialize();
	void Execute();

protected:
	Elevator::Direction m_direction;
};

#endif
