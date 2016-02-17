#include "MonitorCommandGroup.h"

#include "ZeroGyroCommand.h"
#include "DefenseStateMonitorCommand.h"

MonitorCommandGroup::MonitorCommandGroup() : CommandGroup("Monitor")
{
	AddParallel(new ZeroGyroCommand());
	AddParallel(new DefenseStateMonitorCommand());
}

