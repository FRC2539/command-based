#include "DriveDistanceCommand.h"

#include <PIDController.h>
#include "../../RobotMap.h"

DriveDistanceCommand::DriveDistanceCommand(double distance, Direction direction)
	: DefaultCommand("DriveDistance"),
	m_direction(direction),
	onTarget(false),
	inverted(1)
{
	Requires(drivetrain);
	m_distance = distance / RobotMap::DriveBase::encoderSensitivity;
	if (distance < 0)
	{
		inverted = -1;
	}
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

	targetPosition = drivetrain->PIDGet() + m_distance;
	onTarget = false;
}

bool DriveDistanceCommand::IsFinished()
{
	if (onTarget == true)
	{
		float speed = drivetrain->currentSpeed();
		return speed > -0.05 && speed < 0.05;
	}

	float distance = distanceToTarget();
	if (distance > 1000)
	{
		drivetrain->PIDWrite(inverted);
	}
	else if (distance > 500)
	{
		drivetrain->PIDWrite(0.5 * inverted);
	}
	else if (distance > 100)
	{
		drivetrain->PIDWrite(0.25 * inverted);
	}
	else
	{
		onTarget = true;
		drivetrain->PIDWrite(0);
	}

	return false;
}

void DriveDistanceCommand::End()
{
	drivetrain->setMaxSpeed(RobotMap::DriveBase::maxSpeed);
}

double DriveDistanceCommand::distanceToTarget()
{
	float position = drivetrain->PIDGet();

	if (inverted < 0)
	{
		return position - targetPosition;
	}
	else
	{
		return targetPosition - position;
	}
}
