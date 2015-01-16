#include "ArcadeDriveCommand.h"

ArcadeDriveCommand::ArcadeDriveCommand() : DefaultCommand("ArcadeDrive")
{
	Requires(drivetrain);
}

void ArcadeDriveCommand::Execute()
{
	drivetrain->move(
		oi->getAxisValue(logicalAxes::DriveY),
		oi->getAxisValue(logicalAxes::DriveX),
		oi->getAxisValue(logicalAxes::DriveRotate)
	);
}

