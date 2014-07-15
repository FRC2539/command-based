#include "ArcadeDriveCommand.h"
#include "../ControllerMap.h"

ArcadeDriveCommand::ArcadeDriveCommand() : DefaultCommand("ArcadeDrive")
{
	Requires(drivetrain);
}

void ArcadeDriveCommand::Execute()
{
	drivetrain->move(
		oi->getAxis(DRIVE_Y_AXIS),
		oi->getAxis(DRIVE_ROTATE_AXIS)
	);
}

