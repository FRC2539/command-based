#include "ResetCommand.h"

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
}

void ResetCommand::Initialize()
{
	drivetrain->move(0,0, 0);
}


