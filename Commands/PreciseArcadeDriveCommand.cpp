#include "PreciseArcadeDriveCommand.h"
#include "../ControllerMap.h"

PreciseArcadeDriveCommand::PreciseArcadeDriveCommand()
	: DefaultCommand("PreciseArcadeDrive")
{
	Requires(drivetrain);
}

void PreciseArcadeDriveCommand::Execute()
{
	drivetrain->preciseMove(
		oi->getAxis(DRIVE_Y_AXIS),
		oi->getAxis(DRIVE_ROTATE_AXIS)
	);
}