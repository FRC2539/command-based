#include "ArcadeDriveCommand.h"

ArcadeDriveCommand::ArcadeDriveCommand() : DefaultCommand("ArcadeDrive")
{
	Requires(drivetrain);
}

void ArcadeDriveCommand::Execute()
{
	drivetrain->move(
		oi->getAxisValue(DRIVE_AXIS_Y),
		oi->getAxisValue(DRIVE_AXIS_ROTATE)
	);
}

