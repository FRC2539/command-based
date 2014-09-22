#include "PreciseArcadeDriveCommand.h"

#include "../RobotMap.h"

PreciseArcadeDriveCommand::PreciseArcadeDriveCommand()
	: DefaultCommand("PreciseArcadeDrive")
{
	Requires(drivetrain);
}

void PreciseArcadeDriveCommand::Execute()
{
	drivetrain->directDrive(
		scaleAxis(
			logicalAxes::DriveY,
			RobotMap::DriveBase::preciseModeMaxY
		),
		scaleAxis(
			logicalAxes::DriveRotate,
			RobotMap::DriveBase::preciseModeMaxRotate
		)
	);
}

float PreciseArcadeDriveCommand::scaleAxis(const unsigned int axis, float max)
{
	float val = oi->getAxisValue(axis);
	float newVal = val * val * max;
	if (val < 0)
	{
		newVal *= -1;
	}

	return newVal;
}