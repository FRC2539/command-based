#include "ResetCommand.h"

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
	Requires(pickup);
	Requires(shooter);
}

void ResetCommand::Initialize()
{
	drivetrain->directDrive(0, 0);
	pickup->pickup(0);
	shooter->reset();
}


