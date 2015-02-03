#include "TestTalonCommand.h"

TestTalonCommand::TestTalonCommand()
	: TimedCommand("TestTalonCommand", 0.5)
{
	Requires(drivetrain);
}

void TestTalonCommand::Initialize()
{
	drivetrain->setMotorSpeed(1,0.5);
}

void TestTalonCommand::End()
{
	drivetrain->setMotorSpeed(1,0);
}
