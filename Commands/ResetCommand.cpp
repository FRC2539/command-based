#include "ResetCommand.h"

ResetCommand::ResetCommand() : InstantCommand("Reset")
{
	Requires(drivetrain);
	Requires(shooter);
	Requires(pickuparms);
}

void ResetCommand::Initialize()
{
	drivetrain->stop();
	shooter->stopShooter();
	shooter->setIndexerSpeed(0);
	pickuparms->setRollerSpeed(0);
}


