#include "PreciseArcadeDriveCommand.h"

#include "../RobotMap.h"

PreciseArcadeDriveCommand::PreciseArcadeDriveCommand()
	: DefaultCommand("PreciseArcadeDrive")
{
	Requires(drivetrain);
}

void PreciseArcadeDriveCommand::Initialize()
{
	drivetrain->setMaxSpeed(RobotMap::DriveBase::preciseModeMaxSpeed);
}

void PreciseArcadeDriveCommand::Execute()
{
	drivetrain->move(
		oi->getAxisValue(logicalAxes::DriveY),
		oi->getAxisValue(logicalAxes::DriveRotate)
	);
}

void PreciseArcadeDriveCommand::End()
{
	drivetrain->setMaxSpeed(RobotMap::DriveBase::maxSpeed);
}