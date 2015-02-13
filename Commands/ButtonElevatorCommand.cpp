#include "ButtonElevatorCommand.h"

ButtonElevatorCommand::ButtonElevatorCommand(float speed)
	: DefaultCommand("ButtonElevator"), m_speed(speed)
{
	Requires(elevator);
}

void ButtonElevatorCommand::Initialize()
{
	elevator->directDrive(m_speed);
}

void ButtonElevatorCommand::End()
{
	elevator->endDirectDrive();
}
