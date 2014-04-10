#include "ResetCommand.h"

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
	Requires(shooter);
}

void ResetCommand::Initialize()
{
	drivetrain->directDrive(0, 0);
	shooter->reset();
}


