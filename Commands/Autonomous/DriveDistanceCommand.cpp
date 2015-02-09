#include "DriveDistanceCommand.h"

#include <PIDController.h>
#include "../../RobotMap.h"

DriveDistanceCommand::DriveDistanceCommand(double distance, Direction direction)
	: DefaultCommand("DriveDistance"),
	m_direction(direction)
{
	Requires(drivetrain);
	pidLoop = new PIDController(0.01, 0, 0, drivetrain, drivetrain);
	pidLoop->SetAbsoluteTolerance(5);
	m_distance = distance / RobotMap::DriveBase::encoderSensitivity;
}

void DriveDistanceCommand::Initialize()
{
	drivetrain->setMaxSpeed(RobotMap::DriveBase::preciseModeMaxSpeed);
	if (m_direction == Direction::X)
	{
		drivetrain->setPIDMode(drivetrain->DriveX);
	}
	else
	{
		drivetrain->setPIDMode(drivetrain->DriveY);
	}

	pidLoop->SetSetpoint(drivetrain->PIDGet() + m_distance);
	pidLoop->Enable();
}

bool DriveDistanceCommand::IsFinished()
{
	return pidLoop->OnTarget();
}

void DriveDistanceCommand::End()
{
	pidLoop->Disable();
	drivetrain->setMaxSpeed(RobotMap::DriveBase::maxSpeed);
}
