#include "DefenseStateMonitorCommand.h"

DefenseStateMonitorCommand::DefenseStateMonitorCommand() :
	DefaultCommand("DefenseStateMonitor") {}

void DefenseStateMonitorCommand::Execute()
{
	drivetrain->calculateDefenseState();
}

