#include "DefenseStateMonitorCommand.h"

DefenseStateMonitorCommand::DefenseStateMonitorCommand() :
	DefaultCommand("DefenseStateMonitor")
{
	SetRunWhenDisabled(true);
}

void DefenseStateMonitorCommand::Execute()
{
	drivetrain->calculateDefenseState();
}
