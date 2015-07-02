#include "TurnAngleCommand.h"

#include <PIDController.h>
#include "../../RobotMap.h"

TurnAngleCommand::TurnAngleCommand(double angle)
	: DefaultCommand("TurnAngle"),
	m_angle(angle)
{
	Requires(drivetrain);
}

void TurnAngleCommand::Initialize()
{
	float speed = RobotMap::DriveBase::preciseModeMaxSpeed;
	if (m_angle < 0)
	{
		speed *= -1;
	}
	m_target = drivetrain->getAngle() + m_angle;
	drivetrain->move(0, 0, speed);
}

bool TurnAngleCommand::IsFinished()
{
	if (m_angle < 0)
	{
		return (drivetrain->getAngle() < m_target);
	}
	return (drivetrain->getAngle() > m_target);
}

void TurnAngleCommand::End()
{
	drivetrain->stop();
}
