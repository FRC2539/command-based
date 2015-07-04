#include "ButtonElevatorCommand.h"

ButtonElevatorCommand::ButtonElevatorCommand(Elevator::Direction direction)
	: DefaultCommand("ButtonElevator"), m_direction(direction)
{
	Requires(elevator);
}

void ButtonElevatorCommand::Initialize()
{
	elevator->go(m_direction);
}

void ButtonElevatorCommand::Execute()
{
	elevator->updateDashboardHeight();
}
