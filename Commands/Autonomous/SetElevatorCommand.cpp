#include "SetElevatorCommand.h"

SetElevatorCommand::SetElevatorCommand(int target)
	: DefaultCommand("SetElevator"), m_targetHeight(target)
{
	Requires(elevator);
}

void SetElevatorCommand::Initialize()
{
	elevator->goTo(m_targetHeight);
}

void SetElevatorCommand::Execute()
{
	elevator->updateDashboardHeight();
}

bool SetElevatorCommand::IsFinished()
{
	return elevator->atTargetPosition();
}

