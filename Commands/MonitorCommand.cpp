#include "MonitorCommand.h"

#include <RobotState.h>
#include <SmartDashboard/SmartDashboard.h>

MonitorCommand::MonitorCommand() : DefaultCommand("Monitor")
{
	SetRunWhenDisabled(true);
	Requires(monitor);
}

void MonitorCommand::Execute()
{
	if (RobotState::IsEnabled())
	{
		drivetrain->calculateDefenseState();
		SmartDashboard::PutBoolean("Has Ball?", shooter->hasBall());
	}
}
