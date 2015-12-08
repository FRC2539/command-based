#include "DriveCommand.h"

DriveCommand::DriveCommand(const double speed) :
	DefaultCommand("Drive"), m_speed(speed)
{
	Requires(drivetrain);
}

void DriveCommand::Initialize()
{
	drivetrain->setMaxSpeed(m_speed);
}

void DriveCommand::Execute()
{
	drivetrain->move(
		oi->getAxisValue(logicalAxes::DriveX),
		oi->getAxisValue(logicalAxes::DriveY),
		oi->getAxisValue(logicalAxes::DriveRotate)
	);
}

