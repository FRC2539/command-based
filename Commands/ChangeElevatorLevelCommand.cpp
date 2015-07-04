#include "ChangeElevatorLevelCommand.h"

ChangeElevatorLevelCommand::ChangeElevatorLevelCommand(int change)
	: DefaultCommand("ChangeElevatorLevel"), m_change(change)
{
	Requires(elevator);
}

void ChangeElevatorLevelCommand::Initialize()
{
	elevator->changeLevel(m_change);
}

void ChangeElevatorLevelCommand::Execute()
{
	elevator->updateDashboardHeight();
}

bool ChangeElevatorLevelCommand::IsFinished()
{
	return elevator->atTargetPosition();
}
