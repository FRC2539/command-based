#include "ResetCommand.h"

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
	Requires(elevator);
	Requires(tines);
}

void ResetCommand::Initialize()
{
	drivetrain->stop();
	elevator->directDrive(0);
	tines->directDrive(0);
}


