#include "DriveDistanceCommand.h"

#include <PIDController.h>
#include "../../RobotMap.h"

DriveDistanceCommand::DriveDistanceCommand(double distance, Direction direction)
	: DefaultCommand("DriveDistance"),
	m_direction(direction)
{
	Requires(drivetrain);
	pidLoop = new PIDController(.001, .001, 0, drivetrain, drivetrain);
	pidLoop->SetAbsoluteTolerance(35);
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
		
	if (-0.25 < drivetrain->currentSpeed() && drivetrain->currentSpeed() < .025)
	{
		return pidLoop->OnTarget();
		return true;
	}
	else
	{
		return false;

	}
	

}

void DriveDistanceCommand::End()
{
	pidLoop->Reset();
	drivetrain->setMaxSpeed(RobotMap::DriveBase::maxSpeed);
}
