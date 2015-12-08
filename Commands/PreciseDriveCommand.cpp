#include "PreciseDriveCommand.h"

PreciseDriveCommand::PreciseDriveCommand()
	: DriveCommand("PreciseDrive") {}

void PreciseDriveCommand::Initialize()
{
	drivetrain->setMaxSpeed(Config::DriveBase::preciseModeMaxSpeed);
}

void PreciseDriveCommand::End()
{
	drivetrain->setMaxSpeed(Config::DriveBase::maxSpeed);
}
