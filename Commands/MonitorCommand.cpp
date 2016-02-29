#include "MonitorCommand.h"

#include <RobotState.h>

MonitorCommand::MonitorCommand() : DefaultCommand("Monitor")
{
	SetRunWhenDisabled(true);
}

void MonitorCommand::Execute()
{
	if (RobotState::IsEnabled())
	{
		drivetrain->calculateDefenseState();
	}
}
