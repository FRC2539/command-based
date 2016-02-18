#include "MotorTestCommand.h"

MotorTestCommand::MotorTestCommand(float speed) : DefaultCommand("MotorTest"),
	m_speed(speed)
{
	Requires(pickuparms);
}

void MotorTestCommand::Initialize()
{
    pickuparms->manualRun(m_speed);
}

void MotorTestCommand::End()
{
    pickuparms->manualRun(0);
}
