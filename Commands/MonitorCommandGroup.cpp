#include "MonitorCommandGroup.h"

#include "ZeroGyroCommand.h"
#include "DefenseStateMonitorCommand.h"
#include "CameraMonitorCommand.h"

MonitorCommandGroup::MonitorCommandGroup() : CommandGroup("Monitor")
{
	SetRunWhenDisabled(true);

	AddParallel(new ZeroGyroCommand());
	AddParallel(new DefenseStateMonitorCommand());
	AddParallel(new CameraMonitorCommand());
}

