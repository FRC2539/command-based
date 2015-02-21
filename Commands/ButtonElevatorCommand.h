#ifndef BUTTON_ELEVATOR_COMMAND_H
#define BUTTON_ELEVATOR_COMMAND_H

#include "Types/DefaultCommand.h"

class ButtonElevatorCommand : public DefaultCommand {

public:
	ButtonElevatorCommand(float speed);
	void Initialize();
	void Run();
	void End();

protected:
	float m_speed;
};

#endif
