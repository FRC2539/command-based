#include "ZeroGyroCommand.h"

ZeroGyroCommand::ZeroGyroCommand() : InstantCommand("ZeroGyro")
{
	SetRunWhenDisabled(true);
}

void ZeroGyroCommand::Initialize()
{
	drivetrain->resetGyro();
}


