#include "Monitor.h"

#include "../Commands/MonitorCommand.h"

Monitor::Monitor(): Subsystem("Monitor") {}

void Monitor::InitDefaultCommand()
{
	SetDefaultCommand(new MonitorCommand());
}