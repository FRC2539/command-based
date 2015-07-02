#include "PreciseDriveCommand.h"

PreciseDriveCommand::PreciseDriveCommand()
	: DefaultCommand("PreciseDrive")
{
	Requires(drivetrain);
}

void PreciseDriveCommand::Initialize()
{
	drivetrain->setMaxSpeed(RobotMap::DriveBase::preciseModeMaxSpeed);
}

void PreciseDriveCommand::Execute()
{
	drivetrain->move(
		oi->getAxisValue(logicalAxes::DriveX),
		oi->getAxisValue(logicalAxes::DriveY),
		oi->getAxisValue(logicalAxes::DriveRotate)
	);
}

void PreciseDriveCommand::End()
{
	drivetrain->setMaxSpeed(RobotMap::DriveBase::maxSpeed);
}
