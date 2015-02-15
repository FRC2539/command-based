#include "ResetCommand.h"

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
	Requires(elevator);
}

void ResetCommand::Initialize()
{
	drivetrain->stop();
	elevator->endDirectDrive();
}


