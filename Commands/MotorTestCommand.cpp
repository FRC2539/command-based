#include "MotorTestCommand.h"

MotorTestCommand::MotorTestCommand(float speed) : DefaultCommand("MotorTest"),
	m_speed(speed)
{
	Requires(shooter);
}

void MotorTestCommand::Initialize()
{
    shooter->manualShooter(m_speed);
}

void MotorTestCommand::End()
{
    shooter->manualShooter(0);
}
