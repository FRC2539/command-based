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
	elevator->go(Elevator::HOLD);
	tines->directDrive(0);
}


