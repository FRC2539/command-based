#include "ResetCommand.h"

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
}

void ResetCommand::Initialize()
{
	drivetrain->directDrive(0, 0);
}


