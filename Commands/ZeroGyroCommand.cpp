#include "ZeroGyroCommand.h"

ZeroGyroCommand::ZeroGyroCommand()
	: InstantCommand("PreciseDrive")
{
	Requires(drivetrain);
}

void ZeroGyroCommand::Initialize()
{
	drivetrain->resetGyro();
}
