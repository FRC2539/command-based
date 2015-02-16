#include "ZeroGyroCommand.h"

ZeroGyroCommand::ZeroGyroCommand()
	: InstantCommand("ZeroGyro")
{
	Requires(drivetrain);
}

void ZeroGyroCommand::Initialize()
{
	drivetrain->resetGyro();
}
