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
	drivetrain->MOVE_WITH_JOYSTICK;
}

void PreciseDriveCommand::End()
{
	drivetrain->setMaxSpeed(RobotMap::DriveBase::maxSpeed);
}
