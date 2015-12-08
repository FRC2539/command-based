#include "DriveCommand.h"

DriveCommand::DriveCommand(const char* name) : DefaultCommand(name)
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

