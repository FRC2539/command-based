#include "CameraMonitorCommand.h"

CameraMonitorCommand::CameraMonitorCommand() :
	DefaultCommand("CameraMonitor") {}

void CameraMonitorCommand::Execute()
{
	shooter->calculateTargetPosition();
}
