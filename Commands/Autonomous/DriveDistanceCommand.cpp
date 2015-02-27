#include "DriveDistanceCommand.h"

#include <cmath>
#include <PIDController.h>
#include "../../RobotMap.h"

DriveDistanceCommand::DriveDistanceCommand(double distance, Direction direction, double speed)
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
	
	m_speed = speed;
	if (speed == 0)
	{
		m_speed = RobotMap::DriveBase::preciseModeMaxSpeed;
	}
}

void DriveDistanceCommand::Initialize()
{
	drivetrain->setMaxSpeed(m_speed);
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
	drivetrain->PIDWrite(inverted);
}

bool DriveDistanceCommand::IsFinished()
{
	if (onTarget == true)
	{
		float speed = drivetrain->currentSpeed();
		return speed > -0.05 && speed < 0.05;
	}

	double distance = distanceToTarget();
	if (distance < 10)
	{
		onTarget = true;
		drivetrain->PIDWrite(0);
	}
	else if (distance < 100)
	{
		float input = std::max(distance / 100, 0.2);
		drivetrain->PIDWrite(input * inverted);
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
