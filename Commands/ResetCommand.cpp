#include "ResetCommand.h"

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
	Requires(pickuparm);
}

void ResetCommand::Initialize()
{
	drivetrain->directDrive(0, 0);
	pickuparm->setWheelSpeed(0);
}


