#include "CameraMonitorCommand.h"

CameraMonitorCommand::CameraMonitorCommand() :
	DefaultCommand("CameraMonitor")
{
	SetRunWhenDisabled(true);
}

void CameraMonitorCommand::Execute()
{
	shooter->calculateTargetPosition();
}
