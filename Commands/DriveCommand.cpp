#include "DriveCommand.h"

DriveCommand::DriveCommand() : DefaultCommand("Drive")
{
	Requires(drivetrain);
}

void DriveCommand::Execute()
{
	drivetrain->move(
		oi->getAxisValue(logicalAxes::DriveX),
		oi->getAxisValue(logicalAxes::DriveY),
		oi->getAxisValue(logicalAxes::DriveRotate)
	);
}

