#include "ChangeSpeedCommand.h"

ChangeSpeedCommand::ChangeSpeedCommand(double speed):
	InstantCommand("ChangeSpeed"),
	m_speed(speed)
{
	Requires(drivetrain);
}

void ChangeSpeedCommand::Initialize()
{
	drivetrain->setMaxSpeed(m_speed);
}

