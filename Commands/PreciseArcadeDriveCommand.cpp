#include "PreciseArcadeDriveCommand.h"

#include "../RobotMap.h"

PreciseArcadeDriveCommand::PreciseArcadeDriveCommand()
	: DefaultCommand("PreciseArcadeDrive")
{
	Requires(drivetrain);
}

void PreciseArcadeDriveCommand::Execute()
{
	float originalY = oi->getAxisValue("DriveAxisY");
	float originalRotate = oi->getAxisValue("DriveAxisRotate");

	float newY = originalY * originalY * PRECISE_MODE_MAX_Y;
	float newRotate = originalRotate * originalRotate * PRECISE_MODE_MAX_ROTATE;

	if (originalY < 0)
	{
		newY *= -1;
	}
	if (originalRotate < 0)
	{
		newRotate *= -1;
	}

	drivetrain->directDrive(newY, newRotate);
}